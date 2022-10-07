#include "include/tcp_server.h"
#include "include/log.h"
#include "include/io_manager.h"
#include "include/byte_array.h"
#include "include/address.h"

static sylar::Logger::ptr g_logger = SYLAR_LOG_ROOT();

class EchoServer : public sylar::TcpServer {
public:
    EchoServer(int type);
    void handleClient(sylar::Socket::ptr client) override;
private:
    int m_type = 0;
};

EchoServer::EchoServer(int type)
    :m_type(type) {
}

void EchoServer::handleClient(sylar::Socket::ptr client) {
    SYLAR_LOG_INFO(g_logger) << "handleClient " << *client;
    sylar::ByteArray::ptr ba(new sylar::ByteArray);
    while (true) {
        ba->clear();
        std::vector<iovec> iovs;
        ba->getWriteBuffers(iovs, 1024);

        int rt = client->recv(&iovs[0], iovs.size());
        if (0 == rt) {
            SYLAR_LOG_INFO(g_logger) << "client close:" << *client;
            break;
        } else if (rt < 0) {
            SYLAR_LOG_INFO(g_logger) << "client error rt=" << rt << " errno=" << errno
                                     << " errstr=" << strerror(errno);
            break;
        }
        ba->setPosition(ba->getPostion() + rt);
        ba->setPosition(0);
        if (1 == m_type) {
            std::cout << ba->toString();
        } else {
            std::cout << ba->toHexString();
        }
        std::cout.flush();
    }
}

int type = 1;

void run() {
    SYLAR_LOG_INFO(g_logger) << "server type=" << type;
    EchoServer::ptr es(new EchoServer(type));
    auto addr = sylar::Address::LookpAny("0.0.0.0:8020");
    while (!es->bind(addr)) {
        sleep(2);
    }
    es->start();
}

int main(int argc, char **argv) {
    if (argc < 2) {
        SYLAR_LOG_INFO(g_logger) << "used as[" << argv[0] << "-t] or [" 
                                 << argv[0] << " -b]";
        return 0;
    }

    if (!strcmp(argv[1], "-b")) {
        type = 2;
    }

    sylar::IOManager iom(2);
    iom.schedule(run);
    return 0;
}