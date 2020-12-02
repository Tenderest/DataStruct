#include "../PublicLib.hpp"

// 链式队列的实现
// 链式队列结点
typedef struct LinkNode {
    // ElemType data;
    int data;
    struct LinkNode *next;
} LinkNode;

// 链式队列
typedef struct {
    LinkNode *front, *rear; // 队列的队头和队尾指针
} LinkQueue;

class LQueue
{
private:
    LinkQueue Q;
public:
    void InitQueue();
    bool isEmpty();
    void EnQueue(int x);
    bool DeQueue(int &x);
    void GetHead(int &x);
    void visit();
};

// 初始化队列（带头结点）
void LQueue::InitQueue()
{
    // 初始时 front、rear 都指向头结点
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->next = nullptr;
}

// 判断队列是否为空
bool LQueue::isEmpty()
{
    return (Q.front == Q.rear);
}

// 新元素入队（带头结点）
// 注意第一个元素入队
// void EnQueue(LinkQueue &Q, ElemType x)
void LQueue::EnQueue(int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = nullptr;
    Q.rear->next = s;   // 新结点插入到 rear 之后
    Q.rear = s;         // 修改表尾指针
}

// 出队（带头结点）
// 注意最后一个元素出队
// bool DeQueue(LinkQueue &Q, ElemType &x)
bool LQueue::DeQueue(int &x)
{
    if (isEmpty())
        return false;   // 空队
    LinkNode *p = Q.front->next;
    x = p->data;             // 用变量 x 返回队头元素
    Q.front->next = p->next; // 修改头结点的 next 指针
    if (Q.rear == p)         // 此次是最后一个结点出队
        Q.rear = Q.front;    // 修改 rear 指针
    free(p);                 // 释放结点空间
    return true;
}

void LQueue::GetHead(int &x)
{
    x = Q.front->next->data;
}

void LQueue::visit()
{
    LinkNode *p = Q.front;
    while (p != Q.rear)
    {
        std::cout << p->next->data << " -- ";
        p = p->next;
    }
    std::cout << "END" << std::endl;
}

/* // 初始化队列（不带头结点）
void InitQueue(LinkQueue &Q)
{
    // 初始时 front、rear 都指向 NULL
    Q.front = nullptr;
    Q.rear = nullptr;
}

// 判断队列是否为空（不带头结点）
bool isEmpty(LinkQueue Q)
{
    return (Q.front == nullptr);
}

// 新元素入队（不带头结点）
// 注意第一个元素入队
// void EnQueue(LinkNode &Q, ElemType x)
void EnQueue(LinkQueue &Q, int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = nullptr;
    if (Q.front == nullptr) // 在空队列中插入第一个元素
    {
        Q.front = Q.rear = s; // 修改队头队尾指针
    }
    else
    {
        Q.rear->next = s; // 新结点插入到 rear 结点之后
        Q.rear = s;       // 修改 rear 指针
    }
    
}

// 队头元素出队（不带头结点）
// 注意最后一个元素出队
// bool DeQueue(LinkQueue &Q, ElemType &x)
bool DeQueue(LinkQueue &Q, int &x)
{
    if (Q.front == nullptr)
        return false;       // 空队
    LinkNode *p = Q.front;  // p 指向此次出队的结点
    x = p->data;            // 用变量 x 返回队头元素
    Q.front = p->next;      // 修改 front 指针
    if (Q.rear == p)        // 此次最后一个结点出队
    {
        Q.front = nullptr;  // front 指向 NULL
        Q.rear = nullptr;   // rear  指向 NULL
    }
    free(p);                // 释放结点空间
    return true;
} */
