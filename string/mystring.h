#pragma once
#include <string>
#include <cassert>
// 修复：由标准字符串管理容量和结束符，保留学习示例的操作接口。
// 插入、追加允许源字符串指向自身；拷贝与赋值拥有独立存储。
class my_string {
    std::string value_;
public:
    inline static constexpr size_t npos = std::string::npos;
    my_string() = default;
    my_string(const char* text) : value_(text ? text : "") {}
    void reserve(size_t capacity) { value_.reserve(capacity); }
    void insert(char character, size_t position) { value_.insert(position, 1, character); }
    void insert(const char* text, size_t position) { value_.insert(position, std::string(text)); }
    void append(const char* text) { value_ += std::string(text); }
    void push_back(char character) { value_.push_back(character); }
    void resize(size_t count, char character = '\0') { value_.resize(count, character); }
    void erase(size_t position, size_t length = npos) { value_.erase(position, length); }
    size_t size() const { return value_.size(); }
    const char* c_str() const { return value_.c_str(); }
};
