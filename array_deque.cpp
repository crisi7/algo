#include "./utils/common.hpp"
class ArrayDeque
{
private:
    vector<int> nums;
    int front; // 队首指针，指向队首元素
    int queSize;

public:
    ArrayDeque(int capacity)
    {
        nums.resize(capacity);
        front = queSize = 0;
    };
    int capacity()
    {
        return nums.size();
    }
    int size()
    {
        return queSize;
    }
    bool isEmpty()
    {
        return queSize == 0;
    }

    /* 计算环形数组索引 */
    int index(int i)
    {
        // 通过取余操作实现数组首尾相连->实现循环数组
        // 当 i 越过数组尾部后，回到头部
        // 当 i 越过数组头部后，回到尾部
        return (i + capacity()) % capacity();
    }
    void pushFirst(int num)
    {
        if (queSize == capacity())
        {
            cout << "full of deque" << endl;
            return;
        }
        front = index(front - 1);
        nums[front] = num;
        queSize++;
    }
    void pushLast(int num)
    {
        if (queSize == capacity())
        {
            cout << "full of deque" << endl;
            return;
        }
        int rear = index(front + queSize);
        nums[rear] = num;
        queSize++;
    }
    int popFirst()
    {
        int num = peekFirst();
        front = index(front + 1);
        queSize--;
        return num;
    }
    int popLast()
    {
        int num = peekLast();
        // front = index(front + 1);
        queSize--;
        return num;
    }
    int peekFirst()
    {
        if (isEmpty())
            throw out_of_range("none of deque");
        return nums[front];
    }
    int peekLast()
    {
        if (isEmpty())
            throw out_of_range("none of deque");
        int last = index(front + queSize - 1);
        return nums[last];
    }
    vector<int> toVector()
    {
        vector<int> res(queSize);
        for (int i = 0, j = front; i < queSize; i++, j++)
        {
            res[i] = nums[index(j)];
        }
        return res;
    }
    ~ArrayDeque();
};

ArrayDeque::ArrayDeque(int capacity)
{
}

ArrayDeque::~ArrayDeque()
{
}
