#include "./utils/common.hpp"

int main()
{
    int num = 3;
    size_t hashNum = hash<int>()(num);
    cout << "整数 " << num << " 的哈希值为 " << hashNum << "\n";

    bool bol = true;
    size_t hashBol = hash<bool>()(bol);
    cout << "布尔量 " << bol << " 的哈希值为 " << hashBol << "\n";

    double dec = 3.14159;
    size_t hashDec = hash<double>()(dec);
    cout << "小数 " << dec << " 的哈希值为 " << hashDec << "\n";

    string str = "Hello 算法";
    size_t hashStr = hash<string>()(str);
    cout << "字符串 " << str << " 的哈希值为 " << hashStr << "\n";
}