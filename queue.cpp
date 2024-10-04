#include "./utils/common.hpp"
// 有现成的queue队列类
int main()
{
    queue<int> queue;

    queue.push(1);
    queue.push(3);
    queue.push(2);
    queue.push(5);
    queue.push(4);

    // queue没有重载<<，不能直接cout，可以用
    cout << "queue: ";
    printQueue(queue);

    // 用queue类的成员函数front访问队首元素
    int front = queue.front();
    cout << "first element is: " << front << endl;

    // 出列!
    queue.pop();
    cout << front << "出列后，" << "new queue is: ";
    printQueue(queue);

    int size = queue.size();
    cout << "size of queue = " << size << endl;

    bool empty = queue.empty();
    cout << "is empty? " << empty << endl;
    
    return 0;
}
