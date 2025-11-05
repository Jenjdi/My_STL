#include"List.h"

void TestList()
{
    ListNode* pHead = ListCreate();
    // 测试尾插
    ListPushBack(pHead, 1);
    ListPushBack(pHead, 2);
    ListPushBack(pHead, 3);
    ListPrint(pHead); // 应该输出 1 2 3

    // 测试头插
    ListPushFront(pHead, 0);
    ListPushFront(pHead, -1);
    ListPrint(pHead); // 应该输出 -1 0 1 2 3

    // 测试查找
    ListNode* pos = ListFind(pHead, 2);
    if (pos)
    {
        printf("找到元素: %d\n", pos->_data); // 应该输出 找到元素: 2
    }
    else
    {
        printf("未找到元素\n");
    }

    // 测试在pos前面插入
    ListInsert(pos, 5);
    ListPrint(pHead); // 应该输出 -1 0 1 5 2 3

    // 测试删除pos位置的节点
    ListErase(pos);
    ListPrint(pHead); // 应该输出 -1 0 1 5 3

    // 测试尾删
    ListPopBack(pHead);
    ListPrint(pHead); // 应该输出 -1 0 1 5

    // 测试头删
    ListPopFront(pHead);
    ListPrint(pHead); // 应该输出 0 1 5

    // 销毁链表
    ListDestory(pHead);
}

int main()
{
    

    TestList();
    return 0;
}