/*
 * 功能: 动态数组实现
 * 作者: Guyue
 * 微信公众号: 破壳Ai
 * 网站：https://arctee.cn
 * Github: https://github.com/pokoai
 * Date: 2022-06-09
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LENGTH 100

// 定义一个复合数据类型
struct Arr 
{
    int * pBase;  // 存储数组第一个元素的地址
    int len;      // 数组所能容纳的最大元素的个数
    int cnt;      // 数组当前元素的个数
};

// 初空满个
void init_arr(struct Arr * pArr, int length);
bool is_empty(struct Arr * pArr);
bool is_full();
bool length_arr();
// 增删改查
bool append_arr();
bool insert_arr();
bool delete_arr();
bool change_arr();
bool locate_arr();
// 取遍清
bool get();
void traverse_arr();
bool clear_arr();
// 排反显
void sort_arr();
void inverse_arr();
void show_arr(struct Arr * pArr);

int main(void)
{
    struct Arr arr;

    init_arr(&arr, MAX_LENGTH);
    show_arr(&arr);
    //printf("%d %d\n", arr.cnt, arr.len);

    return 0;
}

void init_arr(struct Arr * pArr, int length)
{
    pArr->pBase = (int *)malloc(sizeof(int) * length);
    if ( NULL == pArr->pBase ) {
        printf("动态内存分配失败！\n");
        exit(-1);  // 终止整个程序
    }
    pArr->len = length;
    pArr->cnt = 0;

    return;  // 提示别人程序已经终止
}

void show_arr(struct Arr * pArr)
{
    if ( is_empty(pArr) ) {
        printf("数组为空！\n");
    } else {
        for (int i = 0; i < pArr->cnt; i++ ) {
            printf("%d ", pArr->pBase[i]);  // 数组元素表示要注意：pArr->pBase[i]
        }  // 或者：*(pArr->pBase+i)
        printf("\n");
    }
}

bool is_empty(struct Arr * pArr)
{
    if ( 0 == pArr->cnt ) {
        return true;
    } else {
        return false;
    }
}