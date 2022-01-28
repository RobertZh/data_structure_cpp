#include <stdio.h>
#define MaxSize 10
#define StackInitialTopPointer -1
/* 顺序栈 */
typedef struct {
    int data[MaxSize];
    int top;    // 指向栈顶元素
} SqStack;

void InitStack(SqStack &S) {
    S.top = StackInitialTopPointer;
}

bool StackEmpty(SqStack S) {
    return S.top == StackInitialTopPointer;
}

bool Push(SqStack &S, int x) {
    // 判断栈是否满了
    if (S.top == MaxSize - 1) {
        printf("Stack is full!\n");
        return false;
    }
    // S.top += 1;
    // S.data[S.top] = x;
    // 等价于
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, int &x) {
    if (S.top == StackInitialTopPointer) {
        printf("Stack is empty!");
        return false;
    }
    x = S.data[S.top--];
    return true;
}

/// 获取栈顶
bool GetTop(SqStack S, int &x) {
    if (S.top == StackInitialTopPointer) {
        printf("Stack is empty!");
        return false;
    }
    x = S.data[S.top];
    return true;
}
