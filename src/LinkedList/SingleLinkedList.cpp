#include "../../lib/LinkedList/SingleLinkedList.hpp"
int main(void)
{
    using namespace std;
    LNode *tmpnode;
    int e;
    SingleLinkedList list;
    list.Empty();
    list.HeadInsert(1);
    list.HeadInsert(2);
    list.HeadInsert(3);
    list.visit();

    // cout << list.GetElem(2)->data << endl;
    list.ListInsert(2, 5);
    list.visit();

    // cout << list.GetElem(2)->data << endl;
    // cout << list.LocateElem(3)->data << endl;

    list.DeleteNode(list.GetElem(3));
    list.ListDelete(3, e);
    cout << e << endl;
    list.visit();

    list.Empty();

    return 0;
}