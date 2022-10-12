/*
 * 功能: 散列表（哈希表）查找
 * 作者: Guyue
 * 微信公众号(破壳Ai): https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-10-11
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define HASHSIZE 12  // 哈希表的最大长度
#define NULLKEY -32768

typedef struct {
    int *pBase;  // 动态数组基址
    int count;   // 哈希表当前容量
} HashTable;

int m = 0;  // 散列表长度

// 初始化哈希表
bool InitHashTable(HashTable *H)
{
    m = HASHSIZE;
    H->pBase = (int *)malloc(sizeof(int) * m);
    if ( NULL == H->pBase ) {
        printf("内存分配失败！\n");
        return false;
    }
    H->count = m;

    for ( int i = 0; i < m; i++ ) {
        H->pBase[i] = NULLKEY;
    }
    return true;
}

// 散列函数
int Hash(int key)
{
    return key % m;  // 除留余数法
}

// 插入关键字进哈希表
void InsertHash(HashTable *H, int key)
{
    int addr = Hash(key);

    while ( H->pBase[addr] != NULLKEY ) {  // 该地址已有值存入，冲突
        addr = (addr + 1) % m;  // 开放定址法的线性探测
    }
    H->pBase[addr] = key;
}

// 查找关键字
bool SearchHash(HashTable *H, int key, int *addr)
{
    *addr = Hash(key);

    while ( H->pBase[*addr] != key ) {
        *addr = (*addr + 1) % m;
        // 若key不存在，分两种情况：哈希表未满或已满
        // 未满：往后去寻找时会遇到NULLKEY
        // 已满：最终会循环回来
        if ( NULLKEY == H->pBase[*addr] || *addr == Hash(key) ) {   
            return false;
        }
    }
    return true;
}