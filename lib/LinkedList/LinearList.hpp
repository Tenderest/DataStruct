#include "../PublicLib.hpp"

// 顺序表的实现--静态分配
#define S_MaxSize 10 // 定义最大长度
typedef char ElemType;
typedef struct LinearListStatic{
    // ElemType data[S_MaxSize];
    int data[S_MaxSize];
    // char data[S_MaxSize]; // 用静态的“数组”存放元素
    int length;         // 顺序表当前长度
} SqList;               // 顺序表的类型定义（静态分配方式）

// 顺序表的实现--动态分配
#define InitSize 10 // 顺序表的初始长度
typedef struct LinearListDynamic{
    // ElemType *data; // 指示动态分配数组的指针
    int *data; // 指示动态分配数组的指针
    int MaxSize;    // 顺序表的最大容量
    int length;     // 顺序表的当前长度
} SeqList;          // 顺序表的类型定义（动态分配方式）

class LinearList
{
private:
    SqList L;
public:
    LinearList()
    {
        InitList();
    }
    void InitList();
    bool ListInsert(int i, int e);
    bool ListDelete(int i, int &e);
    int GetElem(int i);
    int LocateElem(int e);
    void visit();
};

// 基本操作——初始化一个静态顺序表 static
void LinearList::InitList()
{
    // 可省略
    for (int i = 0; i < S_MaxSize; i ++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}
// 基本操作——初始化一个动态顺序表 dynamic
void InitList(SeqList &L)
{
    // L.data = (ElemType *) malloc(sizeof(ElemType) * InitSize);
    L.data = (int *) malloc(sizeof(int) * InitSize);
    L.length = 0;
    L.MaxSize = InitSize;
}

// 增加动态数组的长度
void IncreaseSize(SeqList &L, int len)
{
    // ElemType *p = L.data;
    int *p = L.data;
    L.data = (int *)malloc(sizeof(int) * (L.MaxSize + len));
    for (int i = 0; i < L.length; i ++)
    {
        L.data[i] = p[i];        // 将数据复制到新区域
    }
    L.MaxSize = L.MaxSize + len; // 顺序表最大长度增加 len
    free(p);                     // 释放原来的内存空间
}

// 基本操作——插入操作 在表 L 中的第 i 个位置上插入指定元素 e（i 是位序从 1 开始）
bool LinearList::ListInsert(int i, int e)
{
    if (i < 1 || i > L.length + 1) // 判断范围是否有效
        return false;
    if (L.length >= S_MaxSize)     // 当前存储空间已满，不能插入
        return false;
    for (int j = L.length; j >= i; j --) // 将第 i 个元素及之后的元素后移
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e; // 在位置 i 处放入 e
    L.length ++;       // 长度加 1
    return true;
}

// 基本操作——删除操作 删除表 L 中第 i 个位置的元素，并用 e 返回删除元素的值
bool LinearList::ListDelete(int i, int &e)
{
    if (i < 1 || i > L.length) // 判断范围是否有效
        return false;
    e = L.data[i - 1];         // 将被删除元素赋值给 e
    for (int j = i; j < L.length; j ++) // 将第 i 个位置之后的元素前移
    {
        L.data[j - 1] = L.data[j];
    }
    L.length --;       // 长度加 1
    return true;
}

// 基本操作——查找 获取表 L 中第 i 个位置的元素的值
int LinearList::GetElem(int i)
{
    return L.data[i - 1];
}

/* ElemType GetElem(SqList &L, int i)
{
    return L.data[i - 1];
} */

// 基本操作——查找 在表 L 中查找具有给定关键字值的元素，并返回位序
int LinearList::LocateElem(int e)
{
    for (int i = 0; i < L.length; i ++)
    {
        if (L.data[i] == e)
        {
            return i + 1; // 数组下标为 i 的元素值等于 e，返回其位序 i+1
        }
    }
    return -1; // 退出循环，说明查找失败
}

void LinearList::visit()
{
    for(int i = 0; i < L.length; i ++)
    {
        std::cout << L.data[i] << " -- ";
    }
    std::cout << "NULL" << std::endl;
}
