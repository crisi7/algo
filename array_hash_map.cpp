#include "./utils/common.hpp"

// 键值对结构体Pair
struct Pair
{
public:
    int key;
    string val;
    // 构造函数
    Pair(int key, string val)
    {
        this->key = key;
        this->val = val;
    }
    /*构造函数也可写作以下方式
    Pair(int x, string y) : key(x), val(y) {}
    */
};

class ArrayHasMap
{
private:
    // 动态数组buckets，储存的是Pair对象的指针，他就是桶数组，每个元素都是桶
    vector<Pair *> buckets;

public:
    ArrayHasMap()
    {
        buckets = vector<Pair *>(100);
    }
    ~ArrayHasMap()
    {
        // &表示bucket是引用，采用引用是避免在每次迭代时复制bucket的值，提高性能
        // bucket是一个桶的别名，因为bucket是对桶数组buckets中元素的引用
        // bucket是一个键值对Pair对象的指针的别名，就是一个Pair*的别名，因为类型就是Pair*

        // auto表示自动判断类型，buckets是vector<Pair *>
        // const表示引用bucket是常量，不能在循环中更改
        for (const auto &bucket : buckets)
        {
            // 释放每个桶指向的 Pair 对象的内存。
            // const 只保证引用本身bucket不能被重新赋值，但并不阻止bucket通过引用修改所引用对象Pair*的内容。
            // delete bucket通过引用bucket访问桶Pair*，由此清空了指向的键值对Pair的数据(内存)
            delete bucket;
        }
        // 清空 buckets 数组，释放其占用的内存。
        // clear()方法将buckets容器的大小设置为 0，并销毁容器中的所有元素。
        buckets.clear();
    }

    // 哈希函数
    int hashFunc(int key)
    {
        int index = key & 100;
        return index;
    }

    // 查询
    string get(int key)
    {
        int index = hashFunc(key);
        // 取出对应key的指针pair
        Pair *pair = buckets[index];
        if (pair == nullptr)
            return "";
        return pair->val;
    }

    // add element
    void put(int key, string val)
    {
        Pair *pair = new Pair(key, val);
        int index = hashFunc(key);
        buckets[index] = pair;
    }

    // delete element
    void remove(int key)
    {
        int index = hashFunc(key);
        // 先释放键值对数值，再重置桶为nullptr
        delete buckets[index];
        buckets[index] = nullptr;
    }
    // get all Pair
    vector<Pair *> pairSet()
    {
        vector<Pair *> pairSet;
        for (auto bucket : buckets)
        {
            if (bucket != nullptr)
            {
                pairSet.push_back(bucket);
            }
        }
        return pairSet;
    }
    // get all key
    vector<int> keySet()
    {
        vector<int> keySet;
        for (Pair *pair : buckets)
        {
            if (pair != nullptr)
            {
                keySet.push_back(pair->key);
            }
        }
        return keySet;
    }
    // get all val
    vector<string> valueSet()
    {
        vector<string> valueSet;
        for (Pair *pair : buckets)
        {
            if (pair != nullptr)
            {
                valueSet.push_back(pair->val);
            }
        }
        return valueSet;
    }
    // print Hash
    void print()
    {
        for (auto &bucket : buckets)
        {
            cout << bucket->key << "->" << bucket->val << endl;
        }
    }
};
// hash collision哈希冲突
// 哈希扩容
// 负载因子 load factor
