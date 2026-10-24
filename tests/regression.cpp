#include <cassert>
#include "../priority_queue/priority_queue.h"
// 回归：自定义比较器必须同时作用于上浮和下沉。
int main() {
    My_Priority_queue::priority_queue<int> maxQueue;
    My_Priority_queue::priority_queue<int, std::vector<int>, My_Priority_queue::Greater<int>> minQueue;
    for (int value : {4, 1, 7, 3, 9, 2}) { maxQueue.push(value); minQueue.push(value); }
    for (int expected : {9, 7, 4, 3, 2, 1}) { assert(maxQueue.top() == expected); maxQueue.pop(); }
    for (int expected : {1, 2, 3, 4, 7, 9}) { assert(minQueue.top() == expected); minQueue.pop(); }
    assert(maxQueue.empty() && minQueue.empty());
}
