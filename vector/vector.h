// 修复：统一采用完整的深拷贝、扩容和迭代器移动实现。
#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <algorithm>
#include <cassert>
#include <iostream>
namespace My_vector {

template <class T>
class vector {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    vector() { }
    vector(const vector<T>& v)
    {
        reserve(v.capacity()); // 减少扩容次数
        for (auto& e : v) {
            push_back(e);
        }
    }
    template <class InputIterator>
    vector(InputIterator first, InputIterator last) // 类模板的成员函数可以是函数模板
    {
        while (first != last) {
            push_back(*first);
            first++;
        }
    }
    vector(std::initializer_list<T> il)//可以不用加引用，和const原因：这里的initializer_list本来要的就是浅拷贝
        //实质上是il的指针分别指向常量数组的第一个元素和常量数组的最后一个元素，不用拷贝，直接就构造了，因此加上const和引用对性能提升没有影响
        //{1，2，3，4，5，6，78，75}
    {
        reserve(il.size());
        for (auto& e : il)
        {
            push_back(e);
        }
    }
    ~vector()
    {
        delete[] _start;
        _start = _finish = _end_of_storage = nullptr;
    }
    const_iterator begin() const
    {
        return _start;
    }
    const_iterator end() const
    {
        return _finish;
    }
    iterator begin()
    {
        return _start;
    }
    iterator end()
    {
        return _finish;
    }
    size_t size() const
    {
        return _start ? _finish - _start : 0;
    }
    size_t capacity() const
    {
        return _start ? _end_of_storage - _start : 0;
    }
    void reserve(size_t n)
    {
        if (n > capacity()) {
            size_t old_size = size();
            T* tmp = new T[n];
            // memcpy(tmp, _start, old_size * sizeof(T));//这里是按照字节拷贝的，如果使用string,_start和tmp中的_str指向的是同一个字符串，会导致浅拷贝的问题
            // 虽然vector解决了浅拷贝，但是没有解决vector里面的对象里的浅拷贝
            // 解决方法：
            for (size_t i = 0; i < size(); i++) {
                tmp[i] = _start[i]; // 这里和memcpy不同，是通过调用对应的对象的赋值，赋值是对应对象的深拷贝，这样就可以防止浅拷贝的问题
            }
            delete[] _start;
            _start = tmp;
            _finish = old_size + tmp;
            _end_of_storage = tmp + n;
        }
    }
    void push_back(const T& val) // 有可能是string，vector等，避免拷贝构造因此使用传引用
    {
        /*if (_finish == _end_of_storage)
        {
            reserve(capacity() == 0 ? 4 : 2 * capacity());
        }

        *_finish = val;
        ++_finish;*/
        insert(end(), val);
    }
    void insert(iterator pos, T val)
    {
        assert(pos >= _start);
        assert(pos <= _finish);
        if (_finish == _end_of_storage) {
            size_t len = _start ? pos - _start : 0; // 使用len的原因：得到扩容前的相对位置，以便后续的pos找到位置
            reserve(capacity() == 0 ? 4 : 2 * capacity());
            pos = _start + len; // 如果发生了扩容，需要将pos进行更新，否则就会导致迭代器失效
        }
        // 修复：从尾后位置移动，避免构造首元素前一个位置的非法指针。
        for (iterator it = _finish; it != pos; --it) *it = *(it - 1);
        *pos = val;
        ++_finish;
    }

    vector<T>& operator=(vector<T> v) // 由于是传值而不是传引用，因此不会将v原来的值修改，这里只是v的拷贝
    {
        swap(v);
        return *this;
    }
    T& operator[](size_t pos)
    {
        assert(pos < size());
        return _start[pos];
    }
    iterator erase(iterator pos)
    {
        assert(pos >= _start && pos < _finish);
        // 修复：左移后继元素，避免解引用值参与地址计算。
        for (iterator it = pos + 1; it != _finish; ++it) *(it - 1) = *it;
        --_finish;
        return pos;
    }
    void resize(size_t n, const T& val = T()) // 对于自定义类型调用构造函数，对于内置类型将其进行初始化，如int()初始化为0，char()初始化为'\0'
    {
        // 即便容量足够，新增长度也必须初始化新增元素。
        if (n > capacity()) reserve(n);
        while (size() < n) { *_finish = val; ++_finish; }
        if (_start) _finish = _start + n;
    }

    void swap(vector<T>& v)
    {
        std::swap(_start, v._start);
        std::swap(_finish, v._finish);
        std::swap(_end_of_storage, v._end_of_storage);
    }
    void pop_back()
    {
        assert(!empty());
        erase(_finish - 1); // 修复：尾迭代器返回临时值，不能对其直接前置递减。
    }
    bool empty()
    {
        return _start == _finish;
    }

private:
    iterator _start = nullptr;
    iterator _finish = nullptr;
    iterator _end_of_storage = nullptr;
};
template <class T>
void swap(vector<T>& t1, vector<T>& t2)
{
    t1.swap(t2);
}
}
