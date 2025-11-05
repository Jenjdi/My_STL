#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<windows.h>
typedef struct Stack
{
    int *arr;
    int top;
    int capacity;
}Stack;

Stack* createStack(int capacity)
{
    Stack *st = (Stack*)malloc(sizeof(Stack));
    assert(st != NULL);
    st->arr = (int*)malloc(sizeof(int)*capacity);
    assert(st->arr != NULL);
    st->top = 0;
    st->capacity = capacity;
    return st;
}

void push(Stack *st,int data)
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
int pop(Stack* st)
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
bool isEmpty(Stack* st)
{
    if(st->top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Stack* s = createStack(10);
    printf("请输入一个十进制数\n");
    int in;
    scanf("%d",&in);
    
    while(in!=0)
    {
        push(s,in%8);
        in/=8;
    }
    int sum=0;
    while(!isEmpty(s))
    {
        sum+=pop(s);
        sum*=10;
    }
    sum/=10;
    printf("转换为8进制为%d\n",sum);
    system("pause");
}