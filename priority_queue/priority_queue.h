#include <algorithm>
#include <vector>
#include<iostream>
namespace My_Priority_queue {
template <class T>
struct Less {
    bool operator()(const T& t1, const T& t2)
    {
        return t1 < t2;
    }
};
template<class T>
struct Greater
{
    bool operator()(const T& t1, const T& t2)
    {
        return t1 > t2;
    }
};
template <class T, class Container = std::vector<T>, class Compare=Less<T>>
class priority_queue {
public:
    Compare com;
    void push(const T& data)
    {
        _con.push_back(data);
        adjust_up(_con.size() - 1);
    }
    void adjust_up(int child)
    {
        int father=(child-1)/2;
        while (child > 0)
        {
            if (com(_con[father] , _con[child])) { 
                std::swap(_con[father], _con[child]);
                child = father;
                father = (child - 1) / 2;
            }
            else
            {
                break;
            }
        }
    }
    void pop()
    {
        std::swap(_con[0], _con[_con.size() - 1]);
        _con.pop_back();
        adjust_down(0);
    }
    T& top()
    {
        return _con.front();
    }
    void adjust_down(int father)
    {
        int child = (father * 2) + 1;
        while (child<_con.size())
        {
            if (child + 1 < _con.size() && _con[child + 1] > _con[child])//若右孩子存在且大于左孩子，则child为右孩子，否则不变
            {
                child++;
            }
            if (com(_con[father] , _con[child])) {
                std::swap(_con[father], _con[child]);
                father=child;
                child = child = (father * 2) + 1;
            }
            else
            {
                break;
            }
        }
    }
    size_t size()
    {
        return _con.size();
    }
    bool empty()
    {
        return _con.empty();
    }

private:
    Container _con;
};
}