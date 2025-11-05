#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int STDataType;
typedef struct Stack
{
    STDataType *arr;
    int top;
    int capacity;
}Stack;

Stack* StackInit(int capacity)
{
    Stack *st = (Stack*)malloc(sizeof(Stack));
    assert(st != NULL);
    st->arr = (int*)malloc(sizeof(int)*capacity);
    assert(st->arr != NULL);
    st->top = 0;
    st->capacity = capacity;
    return st;
}

void StackPush(Stack *st,STDataType data)
{
    if(st->top == st->capacity)
    {
        printf("Stack is full\n");
    }
    else
    {
        st->arr[st->top] = data;
        st->top++;
    }
    
}
int StackPop(Stack* st)
{
    if(st->top == 0)
    {
        return 0;
    }
    else
    {
        st->top--;
        return st->arr[st->top];
    }
}
STDataType StackTop(Stack* ps)
{
    if(ps->top == 0)
    {
        return 0;
    }
    else
    {
        return ps->arr[ps->top-1];
    }
}
int StackSize(Stack* ps)
{
    return ps->top;
}
int StackEmpty(Stack* st)
{
    if(st->top == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void StackDestroy(Stack* ps)
{
    free(ps->arr);
    free(ps);
}
