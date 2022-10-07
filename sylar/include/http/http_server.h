#ifndef __SYLAR_HTTP_SERVER_H__
#define __SYLAR_HTTP_SERVER_H__

#include "include/http/http_session.h"
#include "include/tcp_server.h"
#include "include/http/servlet.h"

namespace sylar {
namespace http {

class HttpServer : public TcpServer {
public:
    typedef std::shared_ptr<HttpServer> ptr;

    HttpServer(IOManager *worker = IOManager::GetThis(), 
               IOManager *accept_worker = IOManager::GetThis(), 
               bool keep_alive = false);
    
    ServletDispatch::ptr getServletDispatch() const { return m_dispatch;}
    
    void setServletDispatch(ServletDispatch::ptr v) { m_dispatch = v;}
    virtual void setName(const std::string &v) override;
protected:
    virtual void handleClient(Socket::ptr client) override;
private:
    bool m_isKeepAlive;
    ServletDispatch::ptr m_dispatch;
};

} // namespace http
} // namespace sylar

#endif