#include "../../lib/Stack_Queue/Stack.hpp"
int main(void)
{
    using namespace std;
    Stack sq;
    int top;
    int pop;
    sq.InitStack();
    sq.Push(1);
    sq.Push(2);
    sq.Push(3);
    sq.Push(4);
    sq.Push(5);
    sq.Push(6);
    sq.GetTop(top);
    cout << "GetTop = " << top << endl;

    sq.Pop(pop);
    cout << "PopTop = " << pop << endl;

    sq.Pop(pop);
    cout << "PopTop = " << pop << endl;
    
    sq.GetTop(top);
    cout << "GetTop = " << top << endl;
    sq.Push(11);
    sq.Push(22);
    sq.GetTop(top);
    cout << "GetTop = " << top << endl;
    return 0;
}
