#include "../../lib/LinkedList/DoubleLinkedList.hpp"
int main(void)
{
    using namespace std;
    DLinkList D;
    InitDLinkList(D);
    cout << Empty(D) << endl;
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = 1;
    HeadInsert(D, s);
    HeadInsert(D, 2);
    HeadInsert(D, 3);
    // 删除操作传入参数是结点
    DestoryList(D);
    return 0;
}
