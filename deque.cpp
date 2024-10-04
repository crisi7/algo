// cpp现成的deque类实现双向队列

#include "./utils/common.hpp"

int main()
{
    deque<int> deque;

    deque.push_back(2);
    deque.push_back(5);
    deque.push_back(4);
    deque.push_front(3);
    deque.push_front(1);

    int front = deque.front();
    int back = deque.back();

    deque.pop_front();
    deque.pop_back();

    int size = deque.size();

    bool empty = deque.empty();
}