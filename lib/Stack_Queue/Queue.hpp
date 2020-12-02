#include "../PublicLib.hpp"

// 用顺序存储实现队列
#define MaxSize 10 // 定义队列中元素最大的个数
typedef struct {
    // ElemType data[MaxSize];
    int data[MaxSize]; // 用静态数组存放队列元素
    int front, rear;   // 队头指针和队尾指针
} SqQueue;
// Sq: sequence -- 顺序

class Queue
{
private:
    SqQueue Q;
public:
    void InitQueue();
    bool QueueEmpty();
    bool QueueFull();
    bool EnQueue(int x);
    bool DeQueue(int &x);
    bool GetHead(int &x);
    void visit();
};

void Queue::InitQueue()
{
    // 初始化时 队头、队尾指针指向0
    Q.rear = Q.front = 0;
}

// 判断队列是否为空
bool Queue::QueueEmpty()
{
    return (Q.rear == Q.front);
}

// 判断队列是否已满
bool Queue::QueueFull()
{
    return ((Q.rear + 1)%MaxSize == Q.front);
}

// 入队
// bool EnQueue(SqQueue &Q, ElemType x)
bool Queue::EnQueue(int x)
{
    if (QueueFull())
        return false;   // 队满则报错
    Q.data[Q.rear] = x; // 新元素插入队尾
    Q.rear = (Q.rear + 1) % MaxSize; // 队尾指针加 1 取模，形成一个环形（循环）队列
    return true;
}

// 出队
// bool DeQueue(SqQueue &Q, ElemType &x)
bool Queue::DeQueue(int &x)
{
    if (QueueEmpty())
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

// 获得队头元素的值，用 x 返回
// bool GetHead(SqQueue Q, ElemType &x)
bool Queue::GetHead(int &x)
{
    if (QueueEmpty())
        return false;
    x = Q.data[Q.front];
    return true;
}

void Queue::visit()
{
    int i = Q.front;
    while ((i+1)%MaxSize != Q.rear)
    {
        std::cout << Q.data[i] << " -- ";
        i ++;
    }
    std::cout << "END" << std::endl;
}
