#include "../../lib/LinkedList/LinearList.hpp"
int main(void)
{
    /* SqList static_L;    // 声明 static 一个顺序表 declare a static linear list
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
    ListInsert(static_L, 11, 11); */
    using namespace std;
    LinearList list;
    list.InitList();
    list.ListInsert(1, 1);
    list.ListInsert(2, 2);
    list.ListInsert(3, 3);
    list.visit();
    int e = -1;
    if (list.ListDelete(3, e))
    {
        printf("Delete 3th element, the value of the element = %d\n", e);
    }
    else
    {
        printf("You enter the value of i is not allow be use, delete failed.\n");
    }
    list.visit();
    list.ListDelete(10, e);
    list.ListDelete(1, e);
    cout << "After twice delete operator.." << endl;
    list.visit();
    cout << endl;
    e = 1;
    while(list.ListInsert(1, e++) != false) ;
    cout << "Insert operator failed, the static list is full." << endl;
    list.visit();
    return 0;
}
