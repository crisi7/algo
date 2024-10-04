// #include <ListNode.cpp>
#include <stack>
#include <iostream>
using namespace std;
/*栈*/

int main()
{
    stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    int top = stack.top();
    cout << top << endl;
    stack.pop();
    int top2 = stack.top();
    cout << top << endl;

    cout << top2 << endl;

    bool empty = stack.empty();

    return 0;
}