// 动态数组实现队列
// vector本身就有自动扩容机制
#include "./utils/common.hpp"

class VectorQueue
{
private:
    vector<int> queue;

public:
    VectorQueue();
    ~VectorQueue();
    int size()
    {
        return queue.size();
    }
    bool isEmpty()
    {
        return queue.size() == 0;
    }
    // 入列
    void push(int num)
    {
        queue.push_back(num);
        // 作用域结束后，析构函数自动释放tmp这一vector的内存
    }
    // 出列
    int pop()
    {
        if (isEmpty())
            throw out_of_range("none of queue");
        // 出列是第一个元素删除
        int num = queue[0];
        queue.erase(queue.begin());
        return num;
    }
    //访问列首
    int top()
    {
        if (isEmpty())
            throw out_of_range("out of range");
        // back() 是 C++ 标准库中 std::vector 类的一个成员函数，用于返回向量的最后一个元素的引用
        return queue[0];
    }
    vector<int> toVector()
    {
        // 本身就是vector类型，不用转换
        return queue;
    }
};

VectorQueue::VectorQueue(/* args */)
{
}

VectorQueue::~VectorQueue()
{
}
