#include <cmath>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string.h>

#include "include/byte_array.h"
#include "include/endian_sylar.h"
#include "include/log.h"

namespace sylar {

static sylar::Logger::ptr g_logger = SYLAR_LOG_NAME("system");

ByteArray::Node::Node() 
    :ptr(nullptr),
     next(nullptr),
     size(0) {
}

ByteArray::Node::Node(size_t s)
    :ptr(new char[s]),
     next(nullptr),
     size(s) {
}

ByteArray::Node::~Node() {
    if (ptr) {
        delete[] ptr;
    }
}

ByteArray::ByteArray(size_t base_size) 
    :m_baseSize(base_size),
     m_position(0),
     m_capacity(base_size),
     m_size(0),
     m_endian(SYLAR_BIG_ENDIAN),
     m_root(new Node(base_size)),
     m_cur(m_root) {
}

ByteArray::~ByteArray() {
    Node *tmp = m_root;
    while (tmp) {
        m_cur = tmp;
        tmp = tmp->next;
        delete m_cur;
    }
}

void ByteArray::writeFInt8(int8_t value) {
    write(&value, sizeof(value));
}

void ByteArray::writeFUint8(uint8_t value) {
    write(&value, sizeof(value));
}

void ByteArray::writeFInt16(int16_t value) {
    if (m_endian != SYLAR_BYTE_ORDER) {
        value = byteswap(value);    
    }
    write(&value, sizeof(value));
}

void ByteArray::writeFUint16(uint16_t value) {
    if (m_endian != SYLAR_BYTE_ORDER) {
        value = byteswap(value);    
    }
    write(&value, sizeof(value));
}

void ByteArray::writeFInt32(int32_t value) {
    if (m_endian != SYLAR_BYTE_ORDER) {
        value = byteswap(value);    
    }
    write(&value, sizeof(value));
}

void ByteArray::writeFUint32(uint32_t value) {
    if (m_endian != SYLAR_BYTE_ORDER) {
        value = byteswap(value);    
    }
    write(&value, sizeof(value));
}

void ByteArray::writeFInt64(int64_t value) {
    if (m_endian != SYLAR_BYTE_ORDER) {
        value = byteswap(value);    
    }
    write(&value, sizeof(value));
}

void ByteArray::writeFUint64(uint64_t value) {
    if (m_endian != SYLAR_BYTE_ORDER) {
        value = byteswap(value);    
    }
    write(&value, sizeof(value));
}

// Vint 编码方式参考TVL协议（与protobuf一致）
static uint32_t EncodeZigzag32(const int32_t v) {
    if (v < 0) {
        /// 将32位有符号数转换成32位无符号数的表示范围内 
        return ((uint32_t)(-v)) * 2 - 1;
    } else {
        return v * 2;
    }
}

static int32_t DecodeZigzag32(const uint32_t v) {
    /// 将32位无符号数还原成32位有符号数的表示范围内 
    return (v >> 1) ^ -(v & 1);
}

// Vint 编码方式参考TVL协议（与protobuf一致）
static uint64_t EncodeZigzag64(const int64_t v) {
    if (v < 0) {
        /// 将64位有符号数转换成64位无符号数的表示范围内 
        return ((uint64_t)(-v)) * 2 - 1;
    } else {
        return v * 2;
    }
}

static int64_t DecodeZigzag64(const uint64_t v) {
    /// 将64位无符号数还原成64位有符号数的表示范围内 
    return (v >> 1) ^ -(v & 1);
}

void ByteArray::writeInt32(int32_t value) {
    writeUint32(EncodeZigzag32(value));
}

/// TODO: Protobuf实现原理 
void ByteArray::writeUint32(uint32_t value) {
    uint8_t tmp[5];
    uint8_t i = 0;
    while (value >= 0x80) {
        tmp[i++] = (value & 0x7f) | 0x80;
        /// TODO: 为什么移动7位？ 
        value >>= 7; 
    }
    tmp[i++] = value;
    write(tmp, i);
}

void ByteArray::writeInt64(int64_t value) {
    writeUint64(EncodeZigzag64(value));
}

void ByteArray::writeUint64(uint64_t value) {
    uint8_t tmp[10];
    uint8_t i = 0;
    while (value >= 0x80) {
        tmp[i++] = (value & 0x7f) | 0x80;
        value >>= 7;
    }
    tmp[i++] = value;
    write(tmp, i);
}

void ByteArray::writeFloat(float value) {
    uint32_t v;
    memcpy(&v, &value, sizeof(value));
    writeFUint32(v);
}

void ByteArray::writeDouble(double value) {
    uint64_t v;
    memcpy(&v, &value, sizeof(value));
    writeUint64(v);
}

void ByteArray::writeStringF16(const std::string &value) {
    writeFUint16(sizeof(value));
    write(value.c_str(), sizeof(value));
}

void ByteArray::writeStringF32(const std::string &value) {
    writeFUint32(sizeof(value));
    write(value.c_str(), value.size());
}

void ByteArray::writeStringF64(const std::string &value) {
    writeFUint64(sizeof(value));
    write(value.c_str(), value.size());
}

void ByteArray::writeStringVint(const std::string &value) {
    writeUint64(sizeof(value));
    write(value.c_str(), sizeof(value));
}

void ByteArray::writeStringWithoutLength(const std::string &value) {
    write(value.c_str(), sizeof(value));
}

int8_t ByteArray::readFInt8() {
    int8_t v;
    read(&v, sizeof(v));
    return v;
}

uint8_t ByteArray::readFUint8() {
    uint8_t v;
    read(&v, sizeof(v));
    return v;
}

#define XX(type) \
    type v; \
    read(&v, sizeof(v)); \
    if (m_endian == SYLAR_BYTE_ORDER) { \
        return v; \
    } else { \
        return byteswap(v); \
    }

int16_t ByteArray::readFInt16() {
    XX(int16_t);
}

uint16_t ByteArray::readFUint16() {
    XX(uint16_t);
}

int32_t ByteArray::readFInt32() {
    XX(int32_t);
}

uint32_t ByteArray::readFUint32() {
    XX(uint32_t);
}

int64_t ByteArray::readFInt64() {
    XX(int64_t);
}

uint64_t ByteArray::readFUint64() {
    XX(uint64_t);
}
#undef XX

int32_t ByteArray::readInt32() {
    return DecodeZigzag32(readUint32());
}

uint32_t ByteArray::readUint32() {
    uint32_t result = 0;
    for (int i = 0; i < 32; i += 7) {
        uint8_t b = readFUint8();
        if (b < 0x80) {
            /// 无后续数据
            result |= ((uint32_t)b) << i;
            break;
        } else {
            /// 还有后续数据
            result |= ((uint32_t)(b & 0x7f)) << i;
        }
    }
    return result;
}

int64_t ByteArray::readInt64() {
    return DecodeZigzag64(readUint64());
}

uint64_t ByteArray::readUint64() {
    uint64_t result = 0;
    for (int i = 0; i < 64; i += 7) {
        uint8_t b = readFUint8();
        if (b < 0x80) {
            /// 无后续数据
            result |= ((uint64_t)b) << i;
            break;
        } else {
            /// 还有后续数据
            result |= ((uint64_t)(b & 0x7f)) << i;
        }
    }
    return result;
}

float ByteArray::readFloat() {
    uint32_t v = readFUint32();
    float value;
    memcpy(&value, &v, sizeof(v));
    return value;
}

double ByteArray::readDouble() {
    uint64_t v = readFUint64();
    double value;
    memcpy(&value, &v, sizeof(v));
    return value;
}

std::string ByteArray::readStringF16() {
    uint16_t len = readFUint16();
    std::string buff;
    buff.resize(len);
    read(&buff[0], len);
    return buff;
}

std::string ByteArray::readStringF32() {
    uint32_t len = readFUint32();
    std::string buff;
    buff.resize(len);
    read(&buff[0], len);
    return buff;
}

std::string ByteArray::readStringF64() {
    uint64_t len = readFUint64();
    std::string buff;
    buff.resize(len);
    read(&buff[0], len);
    return buff;
}

std::string ByteArray::readStringVint() {
    uint64_t len = readUint64();
    std::string buff;
    buff.resize(len);
    read(&buff[0], len);
    return buff;
}

void ByteArray::clear() {
    m_position = 0;
    m_size = 0;
    m_capacity = m_baseSize;
    Node *tmp = m_root->next;
    while (tmp) {
        m_cur = tmp;
        tmp = tmp->next;
        delete m_cur;
    }
    m_cur = m_root;
    m_root->next = nullptr;
}

void ByteArray::write(const void *buf, size_t size) {
    if (0 == m_size) {
        return;
    }
    addCapacity(size);

    size_t npos = m_position % m_baseSize;  // 当前节点内操作位置
    size_t ncap = m_cur->size - npos;       // 当前节点可写容量
    size_t bpos = 0;                        // buf写指针

    while (size > 0) {
        if (ncap >= size) {
            memcpy(m_cur->ptr + npos, (const char *)buf, size);
            if (m_cur->size == (npos + size)) {
                m_cur = m_cur->next;    // 当前节点恰好写满，移动到下一个节点
            }
            m_position += size;
            bpos += size;
            size = 0;
        } else {
            memcpy(m_cur->ptr + npos, (const char *)buf, ncap);
            m_position += ncap;
            bpos += ncap;
            size -= ncap;

            /// 当前节点不够写，先写满当前节点，再移动到下一个节点继续写 
            m_cur = m_cur->next;
            ncap = m_cur->size;
            npos = 0;
        }
    }

    if (m_position > m_size) {
        m_size = m_position;
    }
}

void ByteArray::read(void *buf, size_t size) {
    if (size > getReadSize()) {
        throw std::out_of_range("not enough space for reading");
    }

    size_t npos = m_position & m_baseSize;
    size_t ncap = m_cur->size - npos;
    size_t bpos = 0;

    while (size > 0) {
        if (ncap >= size) {
            memcpy((char *)buf + bpos, m_cur->ptr + npos, size);
            if (m_cur->size == (npos + size)) {
                m_cur = m_cur->next;    // 当前节点恰好读完，移动到下一个节点
            }
            m_position += size;
            bpos += size;
            ncap -= size;
            size = 0;
        } else {
            memcpy((char *)buf + bpos, m_cur->ptr + npos, ncap);
            m_position += ncap;
            size -= ncap;
            bpos += ncap;

            /// 当前节点不够读，先读完当前节点，再移动到下一个节点继续读
            m_cur = m_cur->next;
            ncap = m_cur->size;
            npos = 0;
        }
    }
}

void ByteArray::read(void *buf, size_t size, size_t position) const {
    if (size > (m_size - position)) {
        throw std::out_of_range("not enough space for reading");
    }

    size_t npos = position & m_baseSize;
    size_t ncap = m_cur->size - npos;
    size_t bpos = 0;
    Node *cur = m_cur;
    while (size > 0) {
        if (ncap >= size) {
            memcpy((char *)buf + bpos, cur->ptr + npos, size);
            if (cur->size == (npos + size)) {
                cur = cur->next;    // 当前节点恰好读完，移动到下一个节点
            }
            position += size;
            bpos += size;
            ncap -= size;
            size = 0;
        } else {
            memcpy((char *)buf + bpos, cur->ptr + npos, ncap);
            position += ncap;
            size -= ncap;
            bpos += ncap;

            /// 当前节点不够读，先读完当前节点，再移动到下一个节点继续读
            cur = cur->next;
            ncap = cur->size;
            npos = 0;
        }
    }
}

bool ByteArray::writeToFile(const std::string &name) const {
    std::ofstream ofs;
    ofs.open(name, std::ios::trunc | std::ios::binary);
    if (!ofs) {
        SYLAR_LOG_ERROR(g_logger) << "writeToFile name=" << name 
                                  << " error, errno=" << errno 
                                  << " errstr=" << strerror(errno);
        return false;
    }

    int64_t read_size = getReadSize();
    int64_t pos = m_position;
    Node *cur = m_cur;

    while (read_size > 0) {
        int diff = pos % m_baseSize;
        int64_t len = (read_size + diff) > (int64_t)m_baseSize ? (m_baseSize - diff) : read_size;
        ofs.write(cur->ptr + diff, len);
        cur = cur->next;
        pos += len;
        read_size -= len;
    }

    return true;
}

bool ByteArray::readFromFile(const std::string &name) {
    std::ifstream ifs;
    ifs.open(name, std::ios::binary);
    if (!ifs) {
        SYLAR_LOG_ERROR(g_logger) << "readFromFile name=" << name 
                                  << " error, errno=" << errno 
                                  << " errstr=" << strerror(errno);
        return false;
    }

    std::shared_ptr<char> buff(new char[m_baseSize], [](char *ptr) {
        delete[] ptr;
    });
    while (!ifs.eof()) {
        ifs.read(buff.get(), m_baseSize);
        write(buff.get(), ifs.gcount());
    }
    return true;
}

void ByteArray::setPosition(size_t v) {
    if (v > m_capacity) {
        throw std::out_of_range("setPosition out of range");
    }
    m_position = v;
    if (m_position > m_size) {
        m_size = m_position;
    }
    m_cur = m_root;
    while (v > m_cur->size) {
        v -= m_cur->size;
        m_cur = m_cur->next;
    }
    if (v == m_cur->size) {
        m_cur = m_cur->next;
    }
}

bool ByteArray::isLittleEndian() const {
    return m_endian == SYLAR_LITTLE_ENDIAN;
}

void ByteArray::setLittleEndian(bool val) {
    m_endian = val ? SYLAR_LITTLE_ENDIAN : SYLAR_BIG_ENDIAN;
}

std::string ByteArray::toString() const {
    std::string str;
    str.resize(getReadSize());
    if (str.empty()) {
        return str;
    }
    read(&str[0], str.size(), m_position);
    return str;
}

std::string ByteArray::toHexString() const {
    std::string str = toString();
    std::stringstream ss;

    for (size_t i = 0; i < str.size(); ++i) {
        if (i > 0 && i % 32 == 0) {
            ss << std::endl;
        }
        ss << std::setw(2) << std::setfill('0') << std::hex 
           << (int)(uint8_t)str[i] << " ";
    }

    return ss.str();
}

uint64_t ByteArray::getReadBuffers(std::vector<iovec> &buffer, 
                                   uint64_t len) const {
    len = len > getReadSize() ? getReadSize() : len;
    if (0 == len) {
        return 0;
    }

    uint64_t size = len;
    size_t npos = m_position % m_baseSize;
    size_t ncap = m_cur->size - npos;
    struct iovec iov;
    Node *cur = m_cur;

    while (len > 0) {
        if (ncap >= len) {
            iov.iov_base = m_cur->ptr + npos;
            iov.iov_len = len;
            len = 0;
        } else {
            iov.iov_base = m_cur->ptr + npos;
            iov.iov_len = ncap;
            len -= ncap;
            cur = cur->next;
            ncap = cur->size;
            npos = 0;
        }
        buffer.emplace_back(iov);
    }
    
    return size;
}

uint64_t ByteArray::getReadBuffers(std::vector<iovec> &buffer, uint64_t len,
                                   uint64_t position) {
    len = len > getReadSize() ? getReadSize() : len;
    if (0 == len) {
        return 0;
    }

    uint64_t size = len;
    size_t npos = m_position % m_baseSize;
    size_t count = position / m_baseSize;
    Node *cur = m_root;
    while (count > 0) {
        cur = cur->next;
        --count;
    }

    size_t ncap = m_cur->size - npos;
    struct iovec iov;
    while (len > 0) {
        if (ncap >= len) {
            iov.iov_base = cur->ptr + npos;
            iov.iov_len = len;
            len = 0;
        } else {
            iov.iov_base = cur->ptr + npos;
            iov.iov_len = ncap;
            len -= ncap;
            cur = cur->next;
            ncap = cur->size;
            npos = 0;
        }
        buffer.emplace_back(iov);
    }
    
    return size;
}

uint64_t ByteArray::getWriteBuffers(std::vector<iovec> &buffers, uint64_t len) {
    if (0 == len) {
        return 0;
    }

    addCapacity(len);
    uint64_t size = len;

    size_t npos = m_position % m_baseSize;
    size_t ncap = m_cur->size - npos;
    struct iovec iov;
    Node *cur = m_cur;
    while (len > 0) {
        if (ncap >= len) {
            iov.iov_base = cur->ptr + npos;
            iov.iov_len = len;
            len = 0;
        } else {
            iov.iov_base = cur->ptr + npos;
            iov.iov_len = ncap;
            len -= ncap;
            cur = cur->next;
            ncap = cur->size;
            npos = 0;
        }
        buffers.emplace_back(iov);
    }

    return size;
}

void ByteArray::addCapacity(size_t size) {
    if (0 == size) {
        return;
    }
    size_t old_cap = getCapacity();
    if (old_cap >= size) {
        return;
    }

    size = size - old_cap;
    size_t count = ceil(1.0 * size / m_baseSize);
    Node *tmp = m_root;
    while (tmp->next) {
        tmp = tmp->next;
    }

    Node *first = nullptr;
    for (size_t i = 0; i < count; ++i) {
        tmp->next = new Node(m_baseSize);
        if (nullptr == first) {
            first = tmp->next;
        }
        tmp = tmp->next;
        m_capacity += m_baseSize;
    }

    if (0 == old_cap) {
        m_cur = first;
    }
}

} // namespace sylar