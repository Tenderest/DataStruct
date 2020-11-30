#include "../../lib/LinkedList/DoubleLinkedList.hpp"
int main(void)
{
    using namespace std;

    DoubleLinkedList list;
    cout << list.Empty() << endl;
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = 1;
    list.HeadInsert(s);
    list.HeadInsert(7);
    list.HeadInsert(3);
    
    list.DestoryList();
    return 0;
}
