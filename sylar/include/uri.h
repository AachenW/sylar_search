#ifndef __SYLAR_URI_H__
#define __SYLAR_URI_H__

#include <memory>
#include <string.h>
#include <stdint.h>
#include "include/address.h"

namespace sylar {
/*
     foo://user@sylar.com:8042/over/there?name=ferret#nose
       \_/   \______________/\_________/ \_________/ \__/
        |           |            |            |        |
     scheme     authority       path        query   fragment
*/

class Uri {
public:
    typedef std::shared_ptr<Uri> ptr;
    
    static Uri::ptr Create(const std::string &uri);
    
    Uri();
    
    const std::string &getScheme() const { return m_scheme;}
    const std::string &getUserInfo() const { return m_userInfo;}
    const std::string &getHost() const { return m_host;}
    const std::string &getPath() const { return m_path;}
    const std::string &getQuery() const { return m_query;}
    const std::string &getFragment() const { return m_fragment;}
    int32_t getPort() const;

    void setScheme(std::string &v) { m_scheme = v;}
    void setUserInfo(std::string &v) { m_userInfo = v;}
    void setHost(std::string &v) { m_host = v;}
    void setPath(std::string &v) { m_path = v;}
    void setQuery(std::string &v) { m_query = v;}
    void setFragment(std::string &v) { m_fragment = v;}
    void setPort(int32_t v) { m_port = v;}

    std::ostream &dump(std::ostream &os) const;
    std::string toString() const;
    Address::ptr createAddress() const;
private:
    bool isDefaultPort() const;
private:
    std::string m_scheme;
    std::string m_userInfo;
    std::string m_host;
    std::string m_path;
    std::string m_query;
    std::string m_fragment;
    int32_t m_port;
};
} // namespace sylar

#endif