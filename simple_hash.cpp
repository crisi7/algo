#include "./utils/common.hpp"

int addHash(string key)
{
    long long hash = 0;
    const int MODULUS = 1000000007; // 大质数
    for (unsigned char c : key)
    {
        // 对大质数取模，没有公约数
        // 如果对合数取模，容易出现聚集现象
        hash = (hash + (int)c) % MODULUS;
    }
    return (int)hash;
}

int mulHash(string key)
{
    long long hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key)
    {
        hash = (31 * hash + (int)c) % MODULUS;
    }
    return (int)hash;
}
int xorHash(string key)
{
    int hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key)
    {
        hash ^= (int)c;
    }
    return hash & MODULUS;
}
int rotHash(string key)
{
    long long hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key)
    {
        hash = ((hash << 4) ^ (hash >> 28) ^ (int)c) % MODULUS;
    }
    return (int)hash;
}