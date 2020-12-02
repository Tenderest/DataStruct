#include "../../lib/Stack_Queue/Queue.hpp"
int main(void)
{
    using namespace std;
    SqQueue Q;
    InitQueue(Q);
    QueueEmpty(Q);
    QueueFull(Q);

    int e = 1;
    while (EnQueue(Q, e++) != false) ;
    cout << "The queue is full now." << endl;
    visit(Q);

    GetHead(Q, e);
    cout << "GetHead = " << e << endl;

    DeQueue(Q, e);
    cout << "DeQueue = " << e << endl;

    GetHead(Q, e);
    cout << "GetHead = " << e << endl;
    visit(Q);
    return 0;
}
