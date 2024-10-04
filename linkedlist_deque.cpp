#include "./utils/common.hpp"

// 由于双向队列需要两端都实现出入操作，这里链表的节点也需要有前后的指针
struct DoublyListNode
{
    int val;
    DoublyListNode *next;
    DoublyListNode *prev;
    DoublyListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};

class LinkedListDeque
{
private:
    DoublyListNode *front, *rear;

    int queSize = 0;

public:
    // DoublyListNode是自建结构体，需要自己写构造方法和析构方法
    LinkedListDeque() : front(nullptr), rear(nullptr) {}
    ~LinkedListDeque()
    {
        DoublyListNode *pre, *cur = front;
        while (cur != nullptr)
        {
            pre = cur;
            cur = cur->next;
            delete pre;
        }
    }
    int size()
    {
        return queSize;
    }
    bool isEmpty()
    {
        return size() == 0;
    }
    // 入列，siFront决定入队首还是队尾
    void push(int num, bool isFront)
    {
        DoublyListNode *node = new DoublyListNode(num);
        if (isEmpty())
            front = rear = node;
        else if (isFront) // 入队首
        {
            front->prev = node;
            node->next = front;
            front = node;
        }
        else
        {
            front->prev = node;
            node->next = front;
            front = node;
        }
        queSize++;
    }
    // 队首入队
    void pushFirst(int num)
    {
        push(num, true);
    }
    // 队尾入队
    void pushLast(int num)
    {
        push(num, false);
    }

    // 出列
    int pop(bool isFront)
    {
        if (isEmpty())
            throw out_of_range("none of deque");
        int val;
        if (isFront)
        {
            val = front->val;

            // 标记次节点，删除头节点
            DoublyListNode *fNext = front->next;
            if (fNext != nullptr)
            {
                // 断开次节点与头节点联系
                fNext->prev = nullptr;
                front->next = nullptr;
            }
            delete front;
            front = fNext; // 新的头节点
        }
        else
        {
            val = rear->val;

            // 标记次尾节点，删除尾节点
            DoublyListNode *rPrev = rear->prev;
            if (rPrev != nullptr)
            {
                rPrev->next = nullptr;
                rear->prev = nullptr;
            }
            delete rear;
            rear = rPrev;
        }
        queSize--;
        return val;
    }
    // 输出队首
    int popFirst()
    {
        return pop(true);
    }
    // 删除队尾
    int popLast()
    {
        return pop(false);
    }
    // 访问队首
    int peekFirst()
    {
        if (isEmpty())
            throw out_of_range("none of deque");
        return front->val;
    }
    // 访问队尾
    int peekLast()
    {
        if (isEmpty())
            throw out_of_range("none of deque");
        return rear->val;
    }

    vector<int> toVector()
    {
        DoublyListNode *node = front;
        vector<int> res(size());
        for (int i = 0; i < res.size(); i++)
        {
            res[i] = node->val;
            node = node->next;
        }
        return res;
    }
};

LinkedListDeque::LinkedListDeque(/* args */)
{
}

LinkedListDeque::~LinkedListDeque()
{
}
