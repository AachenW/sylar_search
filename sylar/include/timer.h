#ifndef __SYLAR_TIEMR_H__
#define __SYLAR_TIMER_H__

#include <memory>
#include <set>
#include <vector>

#include "include/mutex.h"

namespace sylar {

class TimerManager;

/// @brief 定时器
class Timer : public std::enable_shared_from_this<Timer> {
    friend class TimerManager;
public:
    /// @brief 定时器智能指针类型
    typedef std::shared_ptr<Timer> ptr;
    /**
     * @brief 取消定时器
     */
    bool cancel();

    /**
     * @brief 刷新设置定时器的执行时间
     */
    bool refresh();
    /**
     * @brief 重置定时器时间
     * @param[in] ms 定时器执行间隔时间（毫秒）
     * @param[in] from_now 是否从当前时间开始计算
     */
    bool reset(uint64_t ms, bool from_now);
private:
    /// @brief 构造函数
    /// @param ms 定时器执行间隔时间
    /// @param cb 回调函数
    /// @param recurring 是否循环使用定时器
    /// @param manager 定时器管理器
    Timer(uint64_t ms, std::function<void()> cb, bool recurring,
          TimerManager* manager);
    /// @brief 构造函数
    /// @param next 精确的执行时间
    Timer(uint64_t next);
private:
    bool m_recurring = false;       // 是否循环定时器
    uint64_t m_ms = 0;              // 执行周期
    uint64_t m_next = 0;            // 精确的执行时间
    std::function<void()> m_cb;     // 回调函数
    TimerManager* m_manager;        // 定时器管理器
private:
    /// @brief 定时器比较类
    struct Comparator {
        /**
         * @brief 比较定时器的智能指针的大小(按执行时间排序)
         * @param[in] lhs 定时器智能指针
         * @param[in] rhs 定时器智能指针
         */
        bool operator()(const Timer::ptr& lhs, const Timer::ptr& rhs) const;
    };
};

/// @brief 定时器管理器
class TimerManager {
    friend class Timer;
public:
    /// @brief 读写锁类型
    typedef RWMutex RWMutexType;
    /// @brief 构造函数
    TimerManager();
    /// @brief 析构函数
    virtual ~TimerManager();
    /// @brief 添加定时器
    /// @param ms 定时时间
    /// @param cb 回调
    /// @param recurring 是否循环定时器
    /// @return 定时器指针
    Timer::ptr addTimer(uint64_t ms, std::function<void()> cb,
                        bool recurring = false);

    /// @brief 添加条件定时器
    /// @param ms 定时时间
    /// @param cb 回调函数
    /// @param weak_cond 需要判断的条件值（使用虚函数的意义在于，条件不满足可以通过弱指针判断）
    /// @param recurring 是否循环定时器
    /// @return 
    Timer::ptr addConditionTimer(uint64_t ms, std::function<void()> cb,
                                 std::weak_ptr<void> weak_cond, 
                                 bool recurring = false);

    /// @brief 到最近一个定时器执行的时间间隔（毫秒）
    uint64_t getNextTimer();

    /**
     * @brief 获取需要执行的定时器的回调函数列表
     * @param[out] cbs 回调函数数组
     */
    void listExpiredCb(std::vector<std::function<void()>>& cbs);

    /**
     * @brief 是否有定时器
     */
    bool hasTimer();
protected:
    /// @brief 当有新的定时器插入到定时器的首部时，执行该函数
    virtual void onTimerInsertedAtFront() = 0;
    
    /**
     * @brief 将定时器添加到管理器中
     */
    void addTimer(Timer::ptr val, RWMutexType::WriteLock& lock);
private:
    /**
     * @brief 检测服务器时间是否被调后了
     */
    bool detectClockRollover(uint64_t now_ms);
private:
    RWMutexType m_mutex;            // 互斥锁
    std::set<Timer::ptr, Timer::Comparator> m_timers;   // 定时器集合
    bool m_tickled = false;         // 是否触发onTimerInsertedAtFront回调函数
    uint64_t m_previousTime = 0;    // 上次执行时间
};
}


#endif