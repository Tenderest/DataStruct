#include "../PublicLib.hpp"
// 链表的实现
/**
 * 单链表
 * 双链表
 * 循环链表
 * 静态链表
 **/

// 双链表
typedef struct DNode {  // 定义单链表结点类型
    // Elemtype data;
    int data;           // 每个节点存放一个数据元素
    struct DNode *prior, *next; // 指针指向下一个节点
}DNode, *DLinkList;
DLinkList Head = nullptr;
DLinkList Tail = nullptr;

class DoubleLinkedList
{
private:
    DLinkList L;
public:
    DoubleLinkedList()
    {
        InitDLinkList();
    }
    bool InitDLinkList();
    bool Empty();
    bool InsertNextDNode(DNode *p, DNode *s);
    bool InsertNextDNode(DNode *p, int e);
    bool HeadInsert(DNode *e);
    bool HeadInsert(int e);
    bool DeleteNextNode(DNode *p);
    void DestoryList();
    void visit();
};

// 初始化双链表
bool DoubleLinkedList::InitDLinkList()
{
    L = (DNode *) malloc(sizeof(DNode)); // 分配一个头结点
    if (L == nullptr)   // 内存不足，分配失败
        return false;
    L->prior = nullptr; // 头结点的 prior 永远指向 NULL
    L->next = nullptr;  // 头结点之后暂时没有节点
    Head = L;
    Tail = L;
    return true;
}

// 判断双链表是否为空（带头结点）
bool DoubleLinkedList::Empty()
{
    return (L->next == nullptr);
}

// 在 p 结点之后插入 s 结点
bool DoubleLinkedList::InsertNextDNode(DNode *p, DNode *s)
{
    if (p == nullptr || s == nullptr) // 非法参数
        return false;
    // version 1
    /* s->next = p->next;
    p->next->prior = s; // 有Bug，如果p是最后一个结点，则 p->next为空，无法找到prior
    s->prior = p;
    p->next = s; */

    // version 2
    s->next = p->next;
    if (p->next != nullptr)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    Tail = s;
    return true;
}

// 在 p 结点之后插入 e 元素
bool DoubleLinkedList::InsertNextDNode(DNode *p, int e)
{
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    if (p == nullptr || s == nullptr) // 非法参数
        return false;
    // version 1
    /* s->next = p->next;
    p->next->prior = s; // 有Bug，如果p是最后一个结点，则 p->next为空，无法找到prior
    s->prior = p;
    p->next = s; */

    // version 2
    s->next = p->next;
    if (p->next != nullptr)
        p->next->prior = s;
    s->prior = p;
    p->next = s;
    Tail = s;
    return true;
}

// 头插法
bool DoubleLinkedList::HeadInsert(DNode *e)
{
    return InsertNextDNode(Head, e);
}

// 头插法
bool DoubleLinkedList::HeadInsert(int e)
{
    return InsertNextDNode(Head, e);
}

// 删除操作
bool DoubleLinkedList::DeleteNextNode(DNode *p)
{
    if (p == nullptr)
        return false;
    /* p->next = q->next;
    q->next->prior = p; // 有Bug，如果p是最后一个结点，则 p->next为空，无法找到prior
    // .. --> p --> q --> NULL
    // .. <-- p <-- q <-- NULL
    free(q); */

    DNode *q = p->next; // 找到 p 的后继结点 q
    if (q == nullptr)
        return false;   // p 没有后继
    p->next = q->next;
    if (q->next != nullptr) // q 结点不是最后一个结点
        q->next->prior = p;
    free(q); // 释放空间
    return true;
}

// 销毁一个双链表
void DoubleLinkedList::DestoryList()
{
    // 循环释放各个数据结点
    while(L->next != nullptr)
        DeleteNextNode(L);
    free(L);
    L = nullptr;
}

// 遍历操作
void DoubleLinkedList::visit()
{
    DNode *p = L;
    // 后向遍历
    while(p != nullptr)
    {
        p = p->next;
        // other operator, example print
    }
    // 前向遍历
    while(p != nullptr)
    {
        p = p->prior;
        // other operator, example print
    }
    // 前向遍历（跳过头结点）
    while(p->prior != nullptr)
    {
        p = p->prior;
        // other operator, example print
    }
}
