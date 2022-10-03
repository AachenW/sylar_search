#ifndef __SYLAR_IOMANAGER_H__
#define __SYLAR_IOMANAGER_H__

#include "scheduler.h"
#include "timer.h"

namespace sylar {

class IOManager : public Scheduler, public TimerManager {
public:
    typedef std::shared_ptr<IOManager> ptr;
    typedef RWMutex RWMutexType;
    /**
     * @brief IO事件
     */
    enum Event {
        NONE    = 0x0,  // 无事件
        READ    = 0x1,  // EPOLLIN
        WRITE   = 0x4   // EPOLLOUT
    };
private:
    /**
     * @brief Socket事件上下文类
     */
    struct FdContext {
        typedef Mutex MutexType;
        /**
         * @brief 事件上下文类
         */
        struct EventContext {
            Scheduler* scheduler = nullptr;     // 事件执行的调度器
            Fiber::ptr fiber;                   // 事件协程
            std::function<void()> cb;           // 事件的回调函数
        };

        /// @brief 获取事件上下文类
        /// @param event 事件类型
        /// @return 返回对应事件的上下文
        EventContext& getContext(Event event);

        /// @brief 重置时间上下文
        /// @param ctx 待重置的上下文类
        void resetContext(EventContext& ctx);

        /// @brief 触发事件
        /// @param event 事件类型
        void triggerEvent(Event event);

        EventContext read;      // 读事件上下文
        EventContext write;     // 写事件上下文
        int fd = 0;             // 事件关联的句柄
        Event events = NONE;     // 当前的事件
        MutexType mutex;        // 事件的Mutex
    };
public:
    /// @brief 构造函数
    /// @param threads 线程数量
    /// @param use_caller 是否将调用线程包含进去
    /// @param name 调度器的名称
    IOManager(size_t threads = 1, bool use_caller = true, const std::string& name = "");

    /// @brief 析构函数
    ~IOManager();

    /// @brief 添加事件
    /// @param fd socket句柄
    /// @param event 事件类型
    /// @param cb 事件回调函数
    /// @return 添加成功返回0，失败返回-1
    int addEvent(int fd, Event event, std::function<void()> cb = nullptr);
    
    /// @brief 删除事件
    /// @param fd socket句柄
    /// @param event 事件类型
    /// @return 删除成功返回0，失败返回-1
    /// @attention 不会触发事件
    bool delEvent(int fd, Event event);
    
    /// @brief 取消事件
    /// @param fd socket句柄
    /// @param event 事件类型
    /// @return 取消成功返回0，失败返回-1
    /// @attention 如果事件存在则触发事件
    bool cancelEvent(int fd, Event event);
    
    /// @brief 取消所有事件
    /// @param fd socket句柄
    /// @return 取消成功返回0，失败返回-1
    /// @attention 找到事件并强制执行
    bool cancelAll(int fd);
    
    /// @brief 返回当前的IOManager
    static IOManager* GetThis();
protected:
    void tickle() override;
    bool stopping() override;
    void idle() override;
    void onTimerInsertedAtFront() override;

    /// @brief 重置socket句柄上下文的容器大小
    /// @param size 容量大小
    void contextResize(size_t size);

    /// @brief 判断是否可以停止
    /// @param timeout 最近要发出的定时事件间隔
    /// @return 返回是否可以停止
    bool stopping(uint64_t& timeout);
private:
    int m_epfd = 0;                                 // epoll文件句柄
    int m_tickleFds[2];                             // pipe文件句柄
    std::atomic<size_t> m_pendingEventCount = {0};  // 当前等待执行的事件数量
    RWMutexType m_mutex;                            // IOManager的Mutex
    std::vector<FdContext*> m_fdContexts;           // socket事件上下文的容器
};


}

#endif