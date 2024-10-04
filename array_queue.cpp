// 基于环形数组实现的队列
#include "./utils/common.hpp"

class ArrayQueue
{
private:
    int *nums;
    int front;

    int queSize;

    int queCapacity;

public:
    ArrayQueue(int capacity)
    {
        nums = new int[capacity];
        queCapacity = capacity;
        front = queSize = 0;
    };
    ~ArrayQueue()
    {
        delete[] nums;
    }
    int capacity()
    {
        return queCapacity;
    }
    int size()
    {
        return queSize;
    }
    bool isEmpty()
    {
        return size() == 0;
    }
    void push(int num)
    {
        if (queSize == queCapacity)
        {
            cout << "full of queue" << endl;
            return;
        }

        // 计算队尾指针，指向队尾索引 + 1
        // 通过取余操作实现 rear 越过数组尾部后回到头部(因为入队是从头部入)
        int rear = (front + queSize) % queCapacity;
        // 原先的是[0,rear-1] or [0,rear)
        nums[rear] = num;
        queSize++;
    }
    int pop()
    {
        int num = peek();
        front = (front + 1) % queCapacity;
        queSize--;
        return num;
    }
    int peek()
    {
        if (isEmpty())
            throw out_of_range("none of queue");
        return nums[front];
    }
    vector<int> toVector()
    {
        vector<int> arr(queSize);
        for (int i = 0, j = front; i < queSize; i++, j++)
        {
            arr[i] = nums[j % queCapacity];
        }
        return arr;
    }
};

ArrayQueue::ArrayQueue(int capacity)
{
}

ArrayQueue::~ArrayQueue()
{
}
