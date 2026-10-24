#include "../queue/queue.c"
#include <assert.h>
// 回归：空队列、FIFO 顺序及销毁时释放剩余节点。
int main(void) {
 Queue* queue=createQueue();assert(isEmpty(queue));
 QueuePush(queue,12);QueuePush(queue,34);assert(QueueSize(queue)==2);
 assert(QueueFront(queue)==12 && QueueBack(queue)==34);
 assert(QueuePop(queue)==12);assert(QueuePop(queue)==34);assert(isEmpty(queue));
 QueuePush(queue,56);QueueDestroy(queue);
}
