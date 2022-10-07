#ifndef __SYLAR_TCP_SERVER_H__
#define __SYLAR_TCP_SERVER_H__

#include <memory>
#include <vector>

#include "include/address.h"
#include "include/io_manager.h"
#include "include/noncopyable.h"
#include "include/socket.h"

namespace sylar {

class TcpServer : public std::enable_shared_from_this<TcpServer>, Noncopyable {
public:
    typedef std::shared_ptr<TcpServer> ptr;

    TcpServer(IOManager *worker = IOManager::GetThis(), IOManager *accept_worker = IOManager::GetThis());
    virtual ~TcpServer();

    virtual bool bind(Address::ptr addr);
    virtual bool bind(const std::vector<Address::ptr> &addrs, 
                      std::vector<Address::ptr> &fails);
    virtual bool start();
    virtual void stop();
    virtual std::string toString(const std::string &prefix = "");

    uint64_t getRecvTimeout() const { return m_recvTimeout;}
    std::string getName() const { return m_name;}
    std::vector<Socket::ptr> getSocks() const { return m_socks;}
    void setRecvTimeout(uint64_t v) { m_recvTimeout = v;}
    virtual void setName(const std::string &name) { m_name = name;}

    bool isStop() const { return m_isStop;}
protected:
    virtual void handleClient(Socket::ptr client);
    virtual void startAccept(Socket::ptr sock);
private:
    std::vector<Socket::ptr> m_socks;
    IOManager *m_accpetWorker;
    IOManager *m_worker;
    uint64_t m_recvTimeout;
    std::string m_name;
    std::string m_type = "tcp";
    bool m_isStop;
};
} // namespace sylar
#endif 