#include "address.h"
#include <sstream>

namespace sylar {

int Address::getFamily() const {
    return getAddr()->sa_family;
}

std::string Address::toString() const {
    std::stringstream ss;
    insert(ss);
    return ss.str();
}

bool Address::operator<(const Address &rhs) const {
    socklen_t minlen = std::min(getAddrLen(), rhs.getAddrLen());
    int result = memcmp(getAddr(), rhs.getAddr(), minlen);
    if (result < 0) {
        return true;
    } else if (result > 0) {
        return false;
    } else if (getAddrLen() < rhs.getAddrLen()) {
        return true;
    }
    return false;
}

bool Address::operator==(const Address &rhs) const {
    return getAddrLen() == rhs.getAddrLen()
        && memcmp(getAddr(), rhs.getAddr(), getAddrLen()) == 0;
}

bool Address::operator!=(const Address &rhs) const {
    return !(*this == rhs);
}

IPv4Address::IPv4Address(const sockaddr_in &address) {

}
IPv4Address::IPv4Address(uint32_t address, uint32_t port) {

}

const sockaddr *IPv4Address::getAddr() const {

}

sockaddr *IPv4Address::getAddr() {

}

socklen_t IPv4Address::getAddrLen() const {

}

std::ostream &IPv4Address::insert(std::ostream &os) const {

}

IPAddress::ptr IPv4Address::broadcastAddress(uint32_t prefix_len) {

}

IPAddress::ptr IPv4Address::networkAddress(uint32_t prefix_len) {

}

IPAddress::ptr IPv4Address::subNetMask(uint32_t prefix_len) {

}

uint32_t IPv4Address::getPort() const {

}

void IPv4Address::setPort(uint16_t v) {

}

IPv6Address::IPv6Address() {

}

IPv6Address::IPv6Address(const sockaddr_in6 &address) {

}

IPv6Address::IPv6Address(const uint8_t address[16], uint32_t port = 0) {

}

const sockaddr *IPv6Address::getAddr() const {

}

sockaddr *IPv6Address::getAddr() {

}

socklen_t IPv6Address::getAddrLen() const {

}

std::ostream &IPv6Address::insert(std::ostream &os) const {
    
}

IPAddress::ptr IPv6Address::broadcastAddress(uint32_t prefix_len) {

}

IPAddress::ptr IPv6Address::networkAddress(uint32_t prefix_len) {

}

IPAddress::ptr IPv6Address::subNetMask(uint32_t prefix_len) {

}

uint32_t IPv6Address::getPort() const {

}

void IPv6Address::setPort(uint16_t v) {

}


UnixAddress::UnixAddress() {

}

UnixAddress::UnixAddress(const std::string &path) {

}

const sockaddr *UnixAddress::getAddr() const {

}

sockaddr *UnixAddress::getAddr() {

}

socklen_t UnixAddress::getAddrLen() const {
    
}

void UnixAddress::setAddrLen(uint32_t v) {

}

std::string UnixAddress::getPath() const {

}

std::ostream &UnixAddress::insert(std::ostream &os) const {

}

UnknownAddress::UnknownAddress(int family) {

}

UnknownAddress::UnknownAddress(const sockaddr &addr) {

}

const sockaddr *UnknownAddress::getAddr() const {

}

sockaddr *UnknownAddress::getAddr() {

}

socklen_t UnknownAddress::getAddrLen() const {

}

std::ostream &UnknownAddress::insert(std::ostream &os) const {

}

} // namespace sylar