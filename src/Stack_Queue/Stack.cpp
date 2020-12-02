#include "../../lib/Stack_Queue/Stack.hpp"
int main(void)
{
    using namespace std;
    SqStack sq;
    int top;
    int pop;
    InitStack(sq);
    Push(sq, 1);
    Push(sq, 2);
    Push(sq, 3);
    Push(sq, 4);
    Push(sq, 5);
    Push(sq, 6);
    GetTop(sq, top);
    cout << top << endl;

    Pop(sq, pop);
    cout << pop << endl;

    Pop(sq, pop);
    cout << pop << endl;
    
    GetTop(sq, top);
    cout << top << endl;
    return 0;
}
