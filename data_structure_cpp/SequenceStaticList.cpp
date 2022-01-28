
/**
 * 顺序表静态实现
 */

#include <stdio.h>

#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int length;
} SqStaticList;

/**
 * 初始化顺序表
*/
void InitList(SqStaticList &L) {
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;    
}
/**
 * 往表L中第i个位置插入元素e，i的位置从1开始
*/
bool ListInsert(SqStaticList &L, int i, int e) {
    // 检查下标的有效范围
    if (i < 1 || i > L.length + 1) {
        return false;
    }
    // 如果当前表已满，返回
    if (L.length >= MaxSize) {  
        return false;
    }

    for (int j = L.length; j >= i ; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}


void printList(SqStaticList L) {
    for (int i = 0; i < L.length; i++) {
        if (i == 0) {
            printf("[");
        } else if (i ==  L.length - 1) {
            printf("%d", L.data[i]);
            printf("]");
        } else {
            printf("%d, ", L.data[i]);
        }

    }
}

