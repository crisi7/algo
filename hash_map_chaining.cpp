#include "./array_hash_map.cpp"

class HashMapChaining
{
private:
    int size;                       // 键值对数量，Pair.size
    int capacity;                   // hash map容量
    double loadThres;               // 触发扩容的负载因子阈值
    int extendRatio;                // 扩容倍数
    vector<vector<Pair *>> buckets; // 桶数组。元素是由vector实现的链表

public:
    HashMapChaining() : size(0), capacity(4), loadThres(2.0 / 3.0), extendRatio(2) // 成员初始化列表
    {                                                                              // 构造函数体
        buckets.resize(capacity);
    }

    ~HashMapChaining()
    {
        for (auto &bucket : buckets)
            for (Pair *pair : bucket)
                delete pair;
    }
    int hashFunc(int key)
    {
        return key % capacity;
    }
    double loadFactor()
    { // 键值对数量比key容量
        return (double)size / (double)capacity;
    }
    // search
    string get(int key)
    {
        int index = hashFunc(key);
        for (Pair *pair : buckets[index])
            if (pair->key == key)
                return pair->val;
        return "";
    }
    // add
    void put(int key, string val)
    {
        if (loadFactor() > loadThres)
            extend();
        int index = hashFunc(key);
        // 遍历桶，若遇到指定 key ，说明已有则更新对应 val 并返回
        for (Pair *pair : buckets[index])
        {
            if (pair->key == key)
            {
                pair->val = val;
                return;
            }
        }
        // 若无该 key ，则将键值对添加至尾部
        buckets[index].push_back(new Pair(key, val));
        size++;
    }
    void remove(int key)
    {
        int index = hashFunc(key);
        auto &bucket = buckets[index];
        for (int i = 0; i < bucket.size(); i++)
        {
            if (bucket[i]->key == key)
            {
                // 引入 tmp 变量的目的是为了在删除 bucket[i] 之前，先保存对它的引用。这样做的原因是为了避免在删除 bucket[i] 后，无法正确释放内存。
                Pair *tmp = bucket[i];
                bucket.erase(bucket.begin() + i);
                delete tmp;
                size--;
                return;
            }
        }
    }
    void extend()
    {
        // 将原hash暂存在暂存hash中
        vector<vector<Pair *>> bucketsTmp = buckets;
        // 将原hash初始化扩容为新hash，并且清空内容准备填充
        capacity *= extendRatio;
        buckets.clear();
        buckets.resize(capacity);
        size = 0;
        // 把键值对从暂存表搬至新hashmap
        for (auto &bucket : bucketsTmp)
        {
            for (Pair *pair : bucket)
            {
                // 从暂存hash中把旧数据搬至新hash
                // 因为put成员函数可以访问private的buckets，因此实际上此处虽然使用bucketsTmp作为循环条件，但实际上操作的是新哈希表buckets
                put(pair->key, pair->val);
                // 同时删去暂存hash中的键值对，释放内存
                delete pair;
            }
        }
    }
    void print()
    {
        for (auto &bucket : buckets)
        {
            cout << "[";
            for (Pair *pair : bucket)
                cout << pair->key << "->" << pair->val << ", ";
            cout << "]\n";
        }
    }
};
