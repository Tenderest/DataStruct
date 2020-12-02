#include "../../lib/Stack_Queue/LinkQueue.hpp"
int main(void)
{
    using namespace std;
    LinkQueue Q;
    InitQueue(Q);
    cout << "isEmpty = " << isEmpty(Q) << endl;
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 11);
    EnQueue(Q, 22);
    EnQueue(Q, 33);

    int e;
    GetHead(Q, e);
    cout << "GetHead = " << e << endl;
    visit(Q);

    DeQueue(Q, e);
    cout << "DeQueue = " << e << endl;
    visit(Q);
    DeQueue(Q, e);
    cout << "DeQueue = " << e << endl;
    DeQueue(Q, e);
    cout << "DeQueue = " << e << endl;
    DeQueue(Q, e);
    cout << "DeQueue = " << e << endl;
    DeQueue(Q, e);
    cout << "DeQueue = " << e << endl;
    visit(Q);
    return 0;
}
