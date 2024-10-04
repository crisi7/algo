#include <iostream>
#include <random>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;                                   // 节点值
    ListNode *next;                            // 指向下一节点的指针
    ListNode(int x) : val(x), next(nullptr) {} // 构造函数
};

struct ListNode_fb
{
    int val;
    ListNode_fb *next;
    ListNode_fb *prev;
    ListNode_fb(int x) : val(x), next(nullptr), prev(nullptr) {}
};

/*List Class*/
class MyList
{
private:
    int *arr;
    int arrCapacity = 10;
    int arrSize = 0;
    int extendRatio = 2;

public:
    /*构造方法*/
    MyList(/* args */)
    {
        arr = new int[arrCapacity];
    }

    /*析构方法*/
    ~MyList()
    {
        delete[] arr;
    }
    /*获取当前列表长度*/
    int size()
    {
        return arrSize;
    }

    /*获取容量*/
    int capacity()
    {
        return arrCapacity;
    }

    /*访问元素*/
    int get(int index)
    {
        if (index < 0 || index >= arrSize)
            throw out_of_range("out of range");
        return arr[index];
    }

    /*更新元素*/
    void set(int index, int num)
    {
        if (index < 0 || index >= arrSize)
            throw out_of_range("out of range");
        arr[index] = num;
    }

    /*在尾部添加元素*/
    void add(int num)
    {
        if (size() == capacity())
            extendCapacity();
        arr[size()] = num;
        arrSize++;
    }

    /*在中间插入元素*/
    void insert(int index, int num)
    {
        if (index < 0 || index >= size())
            throw out_of_range("out of range");
        if (size() == capacity())

            extendCapacity();
        for (int j = size() - 1; j >= index; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[index] = num;
    }

    /*删除元素*/
    int remove(int index)
    {
        if (index < 0 || index >= size())
            throw out_of_range("out of range");
        int num = arr[index];
        for (int j = index; j < size() - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        arrSize--;
        return num;
    }

    /*列表扩容*/
    void extendCapacity()
    {
        // 扩容为原先容量的两倍
        int newCapacity = capacity() * extendRatio;

        int *tmp = arr;
        arr = new int[newCapacity];
        for (int i = 0; i < size(); i++)
        {
            arr[i] = tmp[i];
        }

        delete[] tmp;
        arrCapacity = newCapacity;
    }

    /*将列表转换为Vector用于打印*/
    vector<int> toVector()
    {
        vector<int> vec(size());
        for (int i = 0; i < size(); i++)
        {
            vec[i] = arr[i];
        }
        return vec;
    }
};

int find(ListNode *head, int target)
{
    int index = 0;
    while (head != nullptr)
    {
        if (head->val == target)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

// 返回类型是 ListNode *
// 函数名是access，但是自动格式化会把*并到access旁边
ListNode *access(ListNode *head, int index)
{
    for (int i = 0; i < index; i++)
    {
        if (head == nullptr)

            return nullptr;
        head = head->next;
    }
    return head;
}

void insert(ListNode *n0, ListNode *p)
{
    ListNode *n1 = n0->next;
    p->next = n1;
    n0->next = p;
}

void remove(ListNode *n0)
{
    if (n0->next = nullptr)
        return;
    ListNode *p = n0->next;
    ListNode *n1 = p->next;

    n0->next = n1;
    delete p;
}

int randomAccess(int *nums, int size)
{
    int randomIndex = rand() % size;
    int randomNum = nums[randomIndex];
    return randomNum;
}

void insert(int *nums, int size, int index, int num)
{
    for (size_t i = size - 1; i > index; i--)
    {
        nums[i] = nums[i - 1];
    }
    nums[index] = num;
}

void remove(int *nums, int size, int target)
{
    for (int i = target; i < size - 1; i++)
    {
        nums[i] = nums[i + 1];
    }
}

void traverse(int *nums, int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        count += nums[i];
    }
}

int find(int *nums, int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (nums[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int *extend(int *nums, int size, int enlarge)
{
    int *res = new int[size + enlarge];
    for (int i = 0; i < size; i++)
    {
        res[i] = nums[i];
    }

    delete[] nums;
    return res;
}
