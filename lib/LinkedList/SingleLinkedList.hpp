#include "../PublicLib.hpp"
// 链表的实现
/**
 * 单链表
 * 双链表
 * 循环链表
 * 静态链表
 **/

// 单链表
typedef struct LNode {  // 定义单链表结点类型
    // Elemtype data;
    int data;           // 每个节点存放一个数据元素
    struct LNode *next; // 指针指向下一个节点
}LNode, *LinkList;
LinkList Head;
LinkList Tail;
/**
 * 要表示一个单链表时，只需要声明一个 头指针 head L，指向单链表的第一个结点
 * LNode *L;   // 声明一个指向单链表第一个结点的指针
 * LinkList L; // 声明一个指向单链表第一个结点的指针
 * --------------------------------------------------------------
 * "LinkList" 等价于 "LNode *"
 * 前者强调这是链表，后者强调这是结点
 * 合适的地方使用合适的名字，代码可读性更高
 **/

// 初始化一个空的单链表 init an empty single linked list
bool InitList_no_head_node(LinkList &L)
{
    L = nullptr; // 空表，暂时没有任何结点 empty list
    return true;
}

// 初始化一个空的单链表（带头结点） init an empty single linked list(have head node)
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode)); // 分配一个头结点 
    if (L == nullptr) // 内存不足，分配失败
        return false;
    L->next = nullptr; // 头结点之后暂时没有结点
    Head = Tail = L;
    return true;
}

// 判断单链表是否为空 judge whether the single linked list is empty
bool Empty(LinkList L)
{
    /* if (L == nullptr)
        return true;
    else
        return false; */

    // return (L == nullptr);
    return (L->next == nullptr);
}

// 求表的长度
int Length(LinkList L)
{
    int len = 0; // 统计表长
    LNode *p = L;
    while(p->next != nullptr)
    {
        p = p->next;
        len ++;
    }
    return len;
}

// 查找操作
// 按位查找 返回第 i 个元素（带头结点）
LNode *GetElem(LinkList L, int i)
{
    if (i < 0)
    {
        return nullptr;
    }
    LNode *p;  // 指针 p 指向当前扫描到的结点
    int j = 0; // 当前 j 指向的是第几个结点
    p = L;     // L 指向头结点，头结点是第 0 个结点（不存数据）
    while(p != nullptr && j < i) // 循环找到第 i - 1 个结点
    {
        p = p->next;
        j ++;
    }
    return p;
}
// 按值查找 找到数据域等于 e 的结点
// LNode *LocateElem(LinkList L, ElemType e)
LNode *LocateElem(LinkList L, int e)
{
    LNode *p = L->next;
    // 从第 1 个结点开始查找数据域为 e 的结点
    while(p != nullptr && p->data != e)
    {
        p = p->next;
    }
    return p;
}

// 后插操作：在 p 结点之后插入元素
// bool InsertNextNode(LNode *p, ElemType e)
bool InsertNextNode(LNode *p, int e)
{
    if (p == nullptr)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == nullptr) // 内存分配失败
        return false;
    s->data = e;      // 用结点 s 保存数据元素 e
    s->next = p->next;
    p->next = s;      // 将结点 s 连到 p 之后
    return true;
}

// 前插操作：在 p 结点之前插入元素 e
// bool InsertPriorNode(LNode *p, ElemType e)
bool InsertPriorNode(LNode *p, int e)
{
    if (p == nullptr)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == nullptr)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;
    return true;
}

// 插入操作 在表 L 中第 i 个位置上插入指定元素 e
bool ListInsert(LinkList &L, int i, int e)
{
    // 在第 i 个位置插入元素 e 带头结点
    if (i < 1)
    {
        return false;
    }
    // 查找操作
    /* LNode *p;  // 指针 p 指向当前扫描到的结点
    int j = 0; // 当前 j 指向的是第几个结点
    p = L;     // L 指向头结点，头结点是第 0 个结点（不存数据）
    while(p != nullptr && j < i - 1) // 循环找到第 i - 1 个结点
    {
        p = p->next;
        j ++;
    } */
    LNode *p = GetElem(L, i - 1);

    /* if (p == nullptr) // i 值不合法
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s; // 将结点 s 连到 p 之后
    return true; // 插入成功 */
    return InsertNextNode(p, e);
}

// Head insert element
bool HeadInsert(LinkList &L, int e)
{
    return InsertNextNode(Head, e);
}

// 删除操作 删除表 L 中第 i 个位置的元素，并用 e 返回删除元素的值
// bool ListDelete(LinkList &L, int i, ElemType &e)
bool ListDelete(LinkList &L, int i, int &e)
{
    // 在第 i 个位置插入元素 e 带头结点
    if (i < 1)
    {
        return false;
    }
    // 查找操作
    /* LNode *p;  // 指针 p 指向当前扫描到的结点
    int j = 0; // 当前 j 指向的是第几个结点
    p = L;     // L 指向头结点，头结点是第 0 个结点（不存数据）
    while(p != nullptr && j < i - 1) // 循环找到第 i - 1 个结点
    {
        p = p->next;
        j ++;
    } */
    LNode *p = GetElem(L, i - 1);
    if (p == nullptr)   // i 值不合法
        return false;
    if (p->next == nullptr) // 第 i - 1 个结点之后已无其他结点
        return false;
    LNode *q = p->next; // 令 q 指向被删除的结点
    e = q->data;        // 用 e 返回元素的值
    p->next = q->next;  // 将 *q 结点从链中断开
    free(q);            // 释放结点的存储空间
    return true;        // 删除成功
}

// 删除指定结点 p
bool DeleteNode(LNode *p)
{
    if (p == nullptr)
        return false;
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    return true;
}
