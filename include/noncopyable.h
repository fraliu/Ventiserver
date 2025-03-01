//
// Created by 10480 on 2025/3/1.
//

#ifndef NONCOPYABLE_H
#define NONCOPYABLE_H

class noncopyable
{
public:
    noncopyable(const noncopyable &) = delete;
    noncopyable &operator=(const noncopyable &) = delete;
    // void operator=(const noncopyable &) = delete;    // muduo将返回值变为void 这其实无可厚非
protected:
    noncopyable() = default;
    ~noncopyable() = default;
};

#endif //NONCOPYABLE_H
