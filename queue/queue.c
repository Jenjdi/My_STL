#include <stdio.h>
#include <stdlib.h>

// 定义队列节点的结构
typedef int QDataType;
typedef struct Node {
    QDataType data;
    struct Node* next;
} Node;

// 定义队列的结构
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// 创建一个新的节点
Node* createNode(QDataType data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 创建一个空队列
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
void QueueDestroy(Queue* q)
{
    while(!isEmpty(q))
    {
        QueuePop(q);
    }
    free(q);
}
// 入队操作
void QueuePush(Queue* q, QDataType data) {
    Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// 出队操作
int  QueuePop(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    int data = temp->data;
    free(temp);
    return data;
}
QDataType QueueFront(Queue* q)
{
    if(q->front==NULL)
    {
        return NULL;
    }
    return q->front->data;
}
QDataType QueueBack(Queue* q)
{
    if(q->rear==NULL)
    {
        return NULL;
    }
    return q->rear->data;
}
int QueueSize(Queue* q)
{
    int size = 0;
    Node* temp = q->front;
    while(temp)
    {
        size++;
        temp = temp->next;
    }
    return size;
}
// 检查队列是否为空
int isEmpty(Queue* q) {
    return q->front == NULL;
}


