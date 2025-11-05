#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<windows.h>
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* pHead = (ListNode*)malloc(sizeof(ListNode));
	assert(pHead);
	pHead->_next = pHead;
	pHead->_prev = pHead;
	return pHead;
}
// 双向链表销毁
void ListDestory(ListNode* pHead)
{
    ListNode* cur=pHead->_next;
    while(cur!=pHead)
    {
        ListNode* next=cur->_next;
        free(cur);
        cur=next;
    }
    free(pHead);
}
// 双向链表打印
void ListPrint(ListNode* pHead)
{
	ListNode* cur = pHead->_next;
	while (cur != pHead)
	{
		printf("%d ", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
    ListNode* newnode=(ListNode*)malloc(sizeof(ListNode));
    newnode->_data=x;
    newnode->_next=pHead;
    newnode->_prev=pHead->_prev;
    pHead->_prev->_next=newnode;
    pHead->_prev=newnode;
    
}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
    assert(pHead->_next!=pHead);
    ListNode* ptail=pHead->_prev;
    pHead->_prev=ptail->_prev;
    ptail->_prev->_next=pHead;
    free(ptail);
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
    ListNode* newnode=(ListNode*)malloc(sizeof(ListNode));
    newnode->_data=x;
    newnode->_prev=pHead;
    newnode->_next=pHead->_next;
    pHead->_next->_prev=newnode;
    pHead->_next=newnode;
}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
    ListNode* cur=pHead->_next;
    pHead->_next=cur->_next;
    cur->_next->_prev=pHead;
    free(cur);
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
    ListNode* cur=pHead->_next;
    while(cur!=pHead)
    {
        if(cur->_data==x)
        {
            return cur;
        }
        cur=cur->_next;
    }
    return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
    assert(pos);
    ListNode* newnode=(ListNode*)malloc(sizeof(ListNode));
    newnode->_data=x;
    newnode->_next=pos;
    newnode->_prev=pos->_prev;
    pos->_prev->_next=newnode;
    pos->_prev=newnode;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
    assert(pos);
    pos->_prev->_next=pos->_next;
    pos->_next->_prev=pos->_prev;
    free(pos);
}