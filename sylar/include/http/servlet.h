#ifndef __SYLAR_HTTP_SERVLET_H__
#define __SYLAR_HTTP_SERVLET_H__

#include <memory>
#include <functional>
#include <string>
#include <vector>
#include <unordered_map>

#include "include/http/http.h"
#include "include/http/http_session.h"
#include "include/thread.h"
#include "include/util.h"

namespace sylar {
namespace http {

class Servlet {
public:
    typedef std::shared_ptr<Servlet> ptr;

    Servlet(const std::string &name);
    virtual ~Servlet() {}

    virtual int32_t handle(HttpRequest::ptr request, 
                           HttpResponse::ptr response,
                           HttpSession::ptr session) = 0;
    const std::string &getName() const { return m_name;}
protected:
    std::string m_name;
};

class FunctionServlet : public Servlet {
public:
    typedef std::shared_ptr<FunctionServlet> ptr;
    typedef std::function<int32_t(HttpRequest::ptr request, 
                                  HttpResponse::ptr response,
                                  HttpSession::ptr session)> callback;
    
    FunctionServlet(callback cb);
    
    virtual int32_t handle(HttpRequest::ptr request, 
                           HttpResponse::ptr response,
                           HttpSession::ptr session) override;
private:
    callback m_cb;
};

class ServletDispatch : public Servlet {
public:
    typedef std::shared_ptr<ServletDispatch> ptr;
    typedef RWMutex RWMutexType;

    ServletDispatch();
    virtual int32_t handle(HttpRequest::ptr request, 
                           HttpResponse::ptr response,
                           HttpSession::ptr session) override;

    void addServlet(const std::string &uri, Servlet::ptr slt);
    void addServlet(const std::string &uri, FunctionServlet::callback cb);
    void addGlobalServlet(const std::string &uri, Servlet::ptr slt);
    void addGlobalServlet(const std::string &uri, FunctionServlet::callback cb);

    void delServlet(const std::string &uri);
    void delGlobalServlet(const std::string &uri);

    Servlet::ptr getDefault() const { return m_defaultServlet;}
    Servlet::ptr getServlet(const std::string &uri);
    Servlet::ptr getGlobServlet(const std::string &uri);
    Servlet::ptr getMatchedServlet(const std::string &uri);

    void setDefault(Servlet::ptr v) { m_defaultServlet = v;}

private:
    RWMutexType m_mutex;
    std::unordered_map<std::string, Servlet::ptr> m_datas;
    std::vector<std::pair<std::string, Servlet::ptr>> m_globs;
    Servlet::ptr m_defaultServlet;
};

class NotFoundServlet : public Servlet {
public:
    typedef std::shared_ptr<NotFoundServlet> ptr;
    NotFoundServlet(const std::string &name);
    virtual int32_t handle(HttpRequest::ptr request, 
                           HttpResponse::ptr response,
                           HttpSession::ptr session) override;
private:
    std::string m_name;
    std::string m_content;
};

} // namespace http
} // namespace sylar

#endif