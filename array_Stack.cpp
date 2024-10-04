#include <ListNode.cpp>

class ArrayStack
{
private:
    // 由于栈的长度可能不断变化，因此使用动态数组
    vector<int> stack;

public:
    ArrayStack();
    ~ArrayStack();
    int size()
    {
        return stack.size();
    }
    bool isEmpty()
    {
        return stack.size() == 0;
    }
    void push(int num)
    {
        stack.push_back(num);
    }
    /*出栈*/
    int pop()
    {
        int num = top();
        stack.pop_back();
        return num;
    }
    int top()
    {
        if (isEmpty())
            throw out_of_range("out of range");
        // back() 是 C++ 标准库中 std::vector 类的一个成员函数，用于返回向量的最后一个元素的引用
        return stack.back();
    }
    vector<int> toVector()
    {
        // 本身就是vector类型，不用转换
        return stack;
    }
};

ArrayStack::ArrayStack(/* args */)
{
}

ArrayStack::~ArrayStack()
{
}
