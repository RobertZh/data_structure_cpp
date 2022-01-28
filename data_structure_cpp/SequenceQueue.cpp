
#define MaxSize 10

typedef struct {
    int data[MaxSize];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue &Q) {
    Q.rear = Q.front = 0;
}

bool QueueEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}

bool EnQueue(SqQueue &Q, int x) {
    if ((Q.rear + 1) % MaxSize == Q.front) // 队满
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;    // 循环队列，让队尾指向下一个位置
    return true;
}

bool DeQueue(SqQueue &Q, int &x) {
    if (Q.rear == Q.front)
        return false; // 空队
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}
