#include "./utils/common.hpp"

int main()
{

    // 初始化hash
    unordered_map<int, string> map;

    map[12523] = "笑哈了";
    map[14234] = "的萨芬";
    map[13454] = "格非为";
    map[15435] = "各为其";
    map[19542] = "恢复到";

    printHashMap(map);

    string name = map[12523];
    cout << name << endl;

    map.erase(19542);
    printHashMap(map);

    /* 遍历哈希表 */
    cout << "\n遍历键值对 Key->Value" << endl;
    for (auto kv : map)
    {
        cout << kv.first << "->" << kv.second << endl;
    }
    cout << "\n使用迭代器遍历 Key->Value" << endl;
    for (auto iter = map.begin(); iter != map.end(); iter++)
    {
        cout << iter->first << "->" << iter->second << endl;
    }
}

// . 运算符用于直接访问对象的成员。
// -> 运算符用于通过指针访问对象的成员。
// . 运算符确保你正在操作的是对象实例，而不是指针。
// ->运算符确保你正在操作的是指针，并且需要解引用。