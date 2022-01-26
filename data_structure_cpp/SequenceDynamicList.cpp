
/**
 * 顺序表动态实现
 */
#include <stdlib.h>

#define InitSize 10
typedef struct SequenceDynamicList
{
    int *data;
    int MaxSize;
    int length;
}SeqDynamicList;


void InitList(SeqDynamicList &L) {
    L.data = (int *)malloc(InitSize * sizeof(int));
    L.length = 0;
    L.MaxSize = InitSize;
}

/**
 * 扩容
 * @param len 扩展多少长度
*/
void IncreaseSize(SeqDynamicList &L, int len) {
    int *newData = (int *)malloc((len + L.MaxSize) * sizeof(int));
    for (int i = 0; i < L.length; i++) {
        newData[i] = L.data[i]; // 时间开销大
    }
    free(L.data);
    L.data = newData;    
}