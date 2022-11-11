#ifndef __SYLAR_HTTP_PARSER_H__
#define __SYLAR_HTTP_PARSER_H__

#include "include/http/http.h"
#include "include/http/http11_parser.h"
#include "include/http/httpclient_parser.h"


namespace sylar {
namespace http {

/**
 * @brief HTTP请求解析类
 */
class HttpRequestParser {
public:
    typedef std::shared_ptr<HttpRequestParser> ptr;

    HttpRequestParser();

    /**
     * @brief 解析协议
     * @param[in, out] data 协议文本内存
     * @param[in] len 协议文本内存长度
     * @return 返回实际解析的长度,并且将已解析的数据移除
     */
    size_t execute(char *data, size_t len);

    /**
     * @brief 是否解析完成
     * @return 是否解析完成
     */
    int isFinished();

    /**
     * @brief 是否有错误
     * @return 是否有错误
     */
    int hasError();

    /**
     * @brief 获取消息体长度
     */
    uint64_t getContentLength();

    /**
     * @brief 返回HttpRequest结构体
     */
    HttpRequest::ptr getData() const { return m_data;}
    
    /**
     * @brief 获取http_parser结构体
     */
    const http_parser &getParser() const { return m_parser;}
    
    /**
     * @brief 设置错误码
     * @param[in] v 错误码
     */
    void setError(int v) { m_error = v;}
public:
    /**
     * @brief 返回HttpRequest协议解析的缓存大小
     */
    static uint64_t GetHttpRequestBufferSize();

    /**
     * @brief 返回HttpRequest协议的最大消息体大小
     */
    static uint64_t GetHttpRequestMaxBodySize();
private:
    http_parser m_parser;       // http_parser
    HttpRequest::ptr m_data;    // HttpRequest结构
    /// 错误码
    /// 1000: invalid method
    /// 1001: invalid version
    /// 1002: invalid field
    int m_error;
};


class HttpResponseParser {
public:
    typedef std::shared_ptr<HttpResponseParser> ptr;

    HttpResponseParser();

    /**
     * @brief 解析HTTP响应协议
     * @param[in, out] data 协议数据内存
     * @param[in] len 协议数据内存大小
     * @param[in] chunck 是否在解析chunck
     * @return 返回实际解析的长度,并且移除已解析的数据
     */
    size_t execute(char *data, size_t len, bool chunck);
    
    /**
     * @brief 是否解析完成
     */
    int isFinished();
    
    /**
     * @brief 是否有错误
     */
    int hasError();

    /**
     * @brief 返回HttpResponse
     */
    HttpResponse::ptr getData() const { return m_data;}
    
    /**
     * @brief 获取消息体长度
     */
    uint64_t getContentLength();
    
    /**
     * @brief 返回httpclient_parser
     */
    const httpclient_parser &getParser() const { return m_parser;}

    /**
     * @brief 设置错误码
     * @param[in] v 错误码
     */
    void setError(int v) { m_error = v;}
public:
    /**
     * @brief 返回HTTP响应解析缓存大小
     */
    static uint64_t GetHttpResponseBufferSize();

    /**
     * @brief 返回HTTP响应最大消息体大小
     */
    static uint64_t GetHttpResponseMaxBodySize();
private:
    httpclient_parser m_parser; // httpclient_parser
    HttpResponse::ptr m_data;   // HttpResponse
    /// 错误码
    /// 1001: invalid version
    /// 1002: invalid field
    int m_error;    
};

} // namespace http
} // namespace sylar 
#endif