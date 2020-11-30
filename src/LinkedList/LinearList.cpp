#include "../../lib/LinkedList/LinearList.hpp"
int main(void)
{
    SqList static_L;    // 声明 static 一个顺序表 declare a static linear list
    InitList(static_L); // 初始化顺序表 init linear list
    ListInsert(static_L, 1, 1);
    ListInsert(static_L, 2, 2);
    ListInsert(static_L, 3, 3);

    // SeqList dynamic_L;   // 声明 dynamic 一个顺序表 declare a dynamic linear list
    // InitList(dynamic_L); // 初始化顺序表 init linear list
    // // .. 往顺序表中添加几个元素 ... add some elements to the linear list
    // IncreaseSize(dynamic_L, 5);

    ListInsert(static_L, 4, 4);
    ListInsert(static_L, 5, 5);
    ListInsert(static_L, 6, 6);
    ListInsert(static_L, 7, 7);
    ListInsert(static_L, 8, 8);
    ListInsert(static_L, 9, 9);
    ListInsert(static_L, 10, 10);
    ListInsert(static_L, 11, 11);

    int e = -1;
    if (ListDelete(static_L, 3, e))
    {
        printf("Delete 3th element, the value of the element = %d\n", e);
    }
    else
    {
        printf("You enter the value of i is not allow be use, delete failed.\n");
    }
    
    ListDelete(static_L, 10, e);
    ListDelete(static_L, 1, e);

    return 0;
}
