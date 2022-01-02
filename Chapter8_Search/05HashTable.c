/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-11-16 18:23:58
 * @FilePath: \DaHua\Chapter8_Search\05HashTable.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define HASHSIZE 12 // 哈希表长度
#define NULLKEY -32768


// 创建哈希表结构
typedef struct {
    int * elem; // 动态数组
    int count; // 哈希表元素个数
}HashTable;

int m = 0; // 全局变量，哈希表长度

// 初始化
void InitHashTable(HashTable * H)
{
    m = HASHSIZE;
    H->count = m;
    H->elem = (int *)malloc(m * sizeof(int)); // 为动态数组分配内存空间
    //开始初始化数组元素
    for (int i = 0; i < m; i++) {
        H->elem[i] = NULLKEY; //全部赋上空置
    }
}


// 哈希函数
int Hash(int key)
{
    return key % m; // 取模法
}


// 插入关键字
bool InsertHash(HashTable * H, int key)
{
    int addr = Hash(key);
    
    while(H->elem[addr] != NULLKEY) { // 冲突
        addr = (addr + 1) % m; // 线性探索法
    }
    H->elem[addr] = key;

    return true;
}

// 搜索关键字
bool SearchHash(HashTable H, int key, int * addr)
{
    *addr = Hash(key);
    while(H.elem[*addr] != key) { // 冲突
        *addr = (*addr + 1) % m; // 线性探索法
        // 若key不存在，分两种情况：哈希表未满或已满
        // 未满：往后去寻找时会遇到NULLKEY
        // 已满：最终会循环回来
        if (NULLKEY == H.elem[*addr] || *addr == Hash(key)) 
            return false;
    }

    return true;
}

int main(void)
{
    int arr[HASHSIZE] = {12, 67, 56, 16, 25, 37, 22, 29, 15, 47, 48, 34};
    HashTable H;
    int addr, result;
    int key = 17;

    InitHashTable(&H);
    for (int i = 0; i < m; i++)
        InsertHash(&H, arr[i]);
    
    for (int i = 0; i < m; i++) {
        printf("%d ", H.elem[i]);
    }
    
    result = SearchHash(H, key, &addr);
    if (result)     
        printf("查找 %d 的地址为：%d\n", key, addr);
    else
        printf("查找 %d 失败\n", key);
    
    for (int i = 0; i < m; i++) {
        key = arr[i];
        SearchHash(H, key, &addr);
        printf("查找 %d 的地址为 %d\n", key, addr);
    }

    return 0;
}