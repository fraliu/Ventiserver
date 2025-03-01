//
// Created by 10480 on 2025/2/25.
//

#ifndef LOGBUFFER_H
#define LOGBUFFER_H
#include <string>
#include <cstring>
#include <iostream>

constexpr int kSmallBufferSize = 4000;
constexpr int kLargeBufferSize = 4000 * 1000;

// 固定的缓冲区类，用于管理日志数据的存储
// 该类提供了一个固定大小的缓冲区，允许将数据追加到缓冲区中，并提供相关的操作方法
template <int buffer_size>
class LogBuffer {
public:
    LogBuffer():cur_(data_),size_(0) {

    }
    void append(const char* buf,size_t len) {
        if(avail()>len) {
            memcpy(cur_,buf,len);
            add(len);
        }
    }

    size_t avail() const{
        return static_cast<size_t>(buffer_size-size_);
    }
    void add(size_t len) {
        cur_ += len;
        size_ += len;
    }
    const char* get_data_ptr() const {
        return data_;
    }
    int get_lenth() const {
        return size_;
    }
    char* get_cur_ptr() const {
        return cur_;
    }
    void reset() {
        cur_ = data_;
        size_ = 0;
    }
    std::string to_String() const {
        return std::string(data_,get_lenth());
    }
    // void bzero() { ::bzero(data_, sizeof(data_)); } maybe过时
    void bzero() {
        memset(data_.get(), 0, buffer_size);
    }
private:
    char data_[buffer_size]; // 定义固定大小的缓冲区
    char *cur_;              // 当前指针，指向缓冲区中下一个可写入的位置
    int size_;               // 已用的缓冲区的大小

};



#endif //LOGBUFFER_H
