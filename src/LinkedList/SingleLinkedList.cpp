#include "../../lib/LinkedList/SingleLinkedList.hpp"
int main(void)
{
    using namespace std;
    LNode *tmpnode;
    int e;
    LinkList L;
    InitList(L);
    bool emp = Empty(L);
    cout << emp << endl;
    int len = Length(L);
    cout << len << endl;

    HeadInsert(L, 1);
    HeadInsert(L, 2);
    HeadInsert(L, 3);
    HeadInsert(L, 4);
    HeadInsert(L, 5);

    emp = Empty(L);
    cout << emp << endl;
    len = Length(L);
    cout << len << endl;
    tmpnode = GetElem(L, 1);
    cout << tmpnode << endl;
    tmpnode = GetElem(L, 3);
    tmpnode = GetElem(L, 7);

    tmpnode = LocateElem(L, 1);
    tmpnode = LocateElem(L, 5);
    tmpnode = LocateElem(L, 7);

    emp = ListDelete(L, 4, e);
    emp = ListDelete(L, 2, e);
    emp = ListDelete(L, 5, e);

    DeleteNode(LocateElem(L, 5));
    DeleteNode(LocateElem(L, 3));

    return 0;
}