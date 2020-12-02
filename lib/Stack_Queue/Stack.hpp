#include "../PublicLib.hpp"

// 顺序栈的实现
#define MaxSize 10 // 定义栈中元素的最大个数
typedef struct {
    // ElemType data[MaxSize]; // 静态数组存放栈中元素
    int data[MaxSize]; // 静态数组存放栈中元素
    int top;                // 栈顶指针
} SqStack;
// Sq: sequence -- 顺序

// 共享栈 share
typedef struct {
    ElemType data[MaxSize];
    int top0;
    int top1;
} ShStack;

class Stack
{
private:
    SqStack S;
public:
    void InitStack();
    bool isEmpty();
    bool isFull();
    bool Push(int x);
    bool Pop(int &x);
    bool Pop(ElemType &x);
    bool GetTop(int &x);
};

void InitStack(ShStack &S)
{
    S.top0 = -1;
    S.top1 = MaxSize;
}

// 初始化栈 Init stack
void Stack::InitStack()
{
    S.top = -1;
}

// 判断栈是否为空
bool Stack::isEmpty()
{
    return (S.top == -1);
}

// 判断栈是否已满
bool Stack::isFull()
{
    return (S.top == MaxSize - 1);
}

// 新元素进栈
// bool Push(SqStack &S, ElemType x)
bool Stack::Push(int x)
{
    if (isFull())      // 栈满，返回 false
        return false;
    S.top = S.top + 1;  // 指针先加 1
    S.data[S.top] = x;  // 新元素入栈
    return true;
}

// 出栈操作
bool Stack::Pop(ElemType &x)
{
    if (isEmpty())     // 栈空，返回 false
        return false;
    x = S.data[S.top];  // 栈顶元素先出栈
    S.top = S.top - 1;  // 指针再减 1
    return true;
}

bool Stack::Pop(int &x)
{
    if (isEmpty())     // 栈空，返回 false
        return false;
    x = S.data[S.top];  // 栈顶元素先出栈
    S.top = S.top - 1;  // 指针再减 1
    return true;
}

// 读取栈顶元素
// bool GetTop(SqStack S, ElemType &x)
bool Stack::GetTop(int &x)
{
    if (isEmpty())     // 栈空，返回 false
        return false;
    x = S.data[S.top];  // x 记录栈顶元素
    return true;
}

// 括号匹配的算法实现
// 使用静态栈容易出现溢出，可以使用链栈
bool bracketCheck(char str[], int length)
{
    /**
     * 用栈实现括号匹配：
     * 依次扫描所有字符，遇到左括号入栈，遇到右括号则弹出栈顶元素检查是否匹配
     * 匹配失败情况：
     * 1️⃣左括号单身2️⃣右括号单身3️⃣左右括号不匹配
     **/
    Stack S;
    for (int i = 0; i < length; i ++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            S.Push(str[i]);
        }
        else
        {
            if (S.isEmpty())
                return false;
            
            char topElem;
            S.Pop(topElem);
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    return S.isEmpty();
}
