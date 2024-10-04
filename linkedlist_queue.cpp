#include "./utils/common.hpp"
class LinkedListQueue
{
private:
    ListNode *front, *rear;
    int queSize;

public:
    LinkedListQueue()
    {
        front = nullptr;
        rear = nullptr;
        queSize = 0;
    }
    ~LinkedListQueue()
    {
        freeMemoryLinkedList(front);
    };
    int size()
    {
        return queSize;
    }
    bool isEmpty()
    {
        return queSize == 0;
    }

    void push(int num)
    {
        ListNode *node = new ListNode(num);
        if (front == nullptr)
        {
            front = node;
            rear = node;
        }
        else
        {
            rear->next = node;
            rear = node;
        }
        queSize++;
    }
    int pop()
    {
        int num = peek();
        ListNode *tmp = front;
        front = front->next;
        delete tmp;
        queSize--;
        return num;
    }
    int peek()
    {
        if (size() == 0)
            throw out_of_range("none of queue");
        return front->val;
    }

    vector<int> toVector()
    {
        ListNode *node = front;
        vector<int> res(size());
        for (int i = 0; i < res.size() - 1; i++)
        {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};

LinkedListQueue::LinkedListQueue(/* args */)
{
}

LinkedListQueue::~LinkedListQueue()
{
}
