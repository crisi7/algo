#include "./utils/common.hpp"

class LinkedListStack
{
private:
    ListNode *stackTop; //
    int stackSize;      // size of stack

public:
    LinkedListStack()
    {
        stackTop = nullptr;
        stackSize = 0;
    }
    ~LinkedListStack()
    {
        freeMemoryLinkedList(stackTop);
    }
    int size()
    {
        return stackSize;
    }
    bool isEmpty()
    {
        return size() == 0;
    }
    void push(int num)
    {
        ListNode *node = new ListNode(num);
        node->next = stackTop;
        stackTop = node;
        stackSize++;
    }
    int pop()
    {
        int num = top();
        ListNode *tmp = stackTop;
        stackTop = stackTop->next;
        delete tmp;
        stackSize--;
        return num;
    }
    int top()
    {
        if (isEmpty())
            throw out_of_range("out of range");
        return stackTop->val;
    }
    vector<int> toVector()
    {
        ListNode *node = stackTop;
        vector<int> res(size()); // res是向量名
        for (int i = res.size() - 1; i >= 0; i--)
        {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
    void freeMemoryLinkedList(ListNode *stackkTop)
    {
        ListNode *current = stackTop;
        while (current != nullptr)
        {
            ListNode *next = current->next;
            delete current;
            current = next;
        }
        stackTop = nullptr;
        cout << "LinkedList_Stack destroyed" << endl;
    }
};
