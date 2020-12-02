#include "../../lib/Stack_Queue/Queue.hpp"
int main(void)
{
    using namespace std;
    Queue queue;
    queue.InitQueue();
    queue.QueueEmpty();
    queue.QueueFull();

    int e = 1;
    while (queue.EnQueue(e++) != false) ;
    cout << "The queue is full now." << endl;
    queue.visit();

    queue.GetHead(e);
    cout << "GetHead = " << e << endl;

    queue.DeQueue(e);
    cout << "DeQueue = " << e << endl;

    queue.DeQueue(e);
    cout << "DeQueue = " << e << endl;

    queue.GetHead(e);
    cout << "GetHead = " << e << endl;
    queue.visit();
    queue.EnQueue(11);
    queue.EnQueue(22);
    queue.EnQueue(33);
    queue.visit();
    return 0;
}
