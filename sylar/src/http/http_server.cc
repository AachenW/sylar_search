#include "include/http/http_server.h"
#include "include/log.h"

namespace sylar {
namespace http {

static Logger::ptr g_logger = SYLAR_LOG_NAME("system");

HttpServer::HttpServer(IOManager *worker, IOManager *accept_worker,
                       bool keep_alive) 
    :TcpServer(worker, accept_worker),
     m_isKeepAlive(keep_alive) {
    m_dispatch.reset(new ServletDispatch);
}

void HttpServer::setName(const std::string &v) {
    TcpServer::setName(v);
    m_dispatch->setDefault(NotFoundServlet::ptr(new NotFoundServlet(v)));
}

void HttpServer::handleClient(Socket::ptr client) {
    SYLAR_LOG_DEBUG(g_logger) << "handleClient " << *client;
    HttpSession::ptr session(new HttpSession(client));
    do {
        auto req = session->recvRequest();
        if (!req) {
            SYLAR_LOG_DEBUG(g_logger) << "recv http request fail, errno=" 
                                      << errno << " errstr=" << strerror(errno)
                                      << " client:" << *client 
                                      << " keep_alive=" << m_isKeepAlive;
            break;
        }

        HttpResponse::ptr rsp(new HttpResponse(req->getVersion(), 
                                            req->isClose() || !m_isKeepAlive));
        rsp->setHeader("Server", getName());
        m_dispatch->handle(req, rsp, session);
        session->sendResponse(rsp);

        if (!m_isKeepAlive || req->isClose()) {
            break;
        }
    } while (true);
    session->close();
}
} // namespace http
} // namespace sylar