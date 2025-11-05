#include "priority_queue.h"

using namespace My_Priority_queue;
struct A
{
    int _a;
};
//bool operator<(const A* a1, const A* a2)
//{
//
//}
// 运算符重载必须要有自定义类型，自定义类型的指针为指针，也是内置类型，因此如果直接使用operator<，会报错，因此这里需要使用仿函数
//仿函数不仅控制比较逻辑，还控制了如何进行比较
int main()
{
    priority_queue<int> pq;
    pq.push(12);
    pq.push(123);
    pq.push(8);
    pq.push(7);
    while (!pq.empty())
    {
        std::cout << pq.top() << std::endl;
        pq.pop();
    }
    priority_queue<A*,std::vector<A*>> pq;
    
}