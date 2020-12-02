#include "../../lib/Stack_Queue/LinkQueue.hpp"
int main(void)
{
    using namespace std;
    LQueue lq;
    lq.InitQueue();
    cout << "isEmpty = " << lq.isEmpty() << endl;
    lq.EnQueue(1);
    lq.EnQueue(2);
    lq.EnQueue(3);
    lq.EnQueue(11);
    lq.EnQueue(22);
    lq.EnQueue(33);

    int e;
    lq.GetHead(e);
    cout << "GetHead = " << e << endl;
    lq.visit();

    
    lq.DeQueue(e);
    cout << "DeQueue = " << e << endl;
    lq.DeQueue(e);
    cout << "DeQueue = " << e << endl;
    lq.DeQueue(e);
    cout << "DeQueue = " << e << endl;
    lq.DeQueue(e);
    cout << "DeQueue = " << e << endl;
    lq.DeQueue(e);
    cout << "DeQueue = " << e << endl;
    lq.visit();
    return 0;
}
