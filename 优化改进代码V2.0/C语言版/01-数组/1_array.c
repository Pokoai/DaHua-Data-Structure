/*
 * 功能: 动态数组实现
 * 作者: Guyue
 * 微信公众号: 破壳Ai
 * 网站：https://arctee.cn
 * Github: https://github.com/pokoai
 * Date: 2022-06-09
 */

// 待改进：typedef使用；const使用；
// 待完善：第一遍先把重点写完，剩余一些功能函数比较简单，后面有时间再补充

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
bool is_empty(struct Arr * pArr);
int length_arr(struct Arr * pArr);  
// 增删改查
bool append_arr(struct Arr * pArr, int elem);
bool insert_arr(struct Arr * pArr, int pos, int elem);
bool delete_arr(struct Arr * pArr, int pos, int * pElem);
bool change_arr();  // so easy
bool locate_arr();  // so easy
// 取遍清
bool get();  // so easy
bool traverse_arr(struct Arr * pArr, void (*fun)(int));
static void print_elem(int elem); 
bool clear_arr();  // 待补充
// 排反显
void sort_arr(struct Arr * pArr);  // 目前先用冒泡排序实现，后续有更多方法
void inverse_arr(struct Arr * pArr); 
void show_arr(struct Arr * pArr);


int main(void)
{
    struct Arr arr;

    init_arr(&arr, MAX_LENGTH);

    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    append_arr(&arr, 4);

    insert_arr(&arr, 1, 10);
    insert_arr(&arr, 6, 22);
    insert_arr(&arr, 7, 61);
    // if ( !insert_arr(&arr, 0, 99) ) {
    //     printf("0位置插入失败！\n");
    // }
    // if ( !insert_arr(&arr, 9, 8) ) {
    //     printf("末尾+1位置插入失败！\n");
    // }

    printf("原始：");
    show_arr(&arr);

    int elem;
    delete_arr(&arr, 4, &elem);
    printf("删除：%d\n", elem);
    printf("删除后：");
    show_arr(&arr);

    printf("数组元素个数：%d\n", length_arr(&arr));
    
    printf("正向：");
    show_arr(&arr);
    inverse_arr(&arr);
    printf("反向：");
    show_arr(&arr);

    sort_arr(&arr);
    printf("排序：");
    show_arr(&arr);

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

    //return;  // 提示别人程序已经终止
}


void show_arr(struct Arr * pArr)
{
    // if ( is_empty(pArr) ) {
    //     printf("数组为空！\n");
    // } else {
    //     for (int i = 0; i < pArr->cnt; i++ ) {
    //         printf("%d ", pArr->pBase[i]);  // 数组元素表示要注意：pArr->pBase[i]
    //     }  // 或者：*(pArr->pBase+i)
    //     printf("\n");
    // }
    traverse_arr(pArr, print_elem);
}


bool is_empty(struct Arr * pArr)
{
    if ( 0 == pArr->cnt ) {
        return true;
    } else {
        return false;
    }
}


bool is_full(struct Arr * pArr)
{
    if ( pArr->cnt == pArr->len ) {
        return true;
    } else {
        return false;
    }
}


int length_arr(struct Arr * pArr)
{
    return pArr->cnt;
}

bool append_arr(struct Arr * pArr, int elem) 
{
    if ( is_full(pArr) ) {
        return false;
    }

    pArr->pBase[pArr->cnt] = elem;
    pArr->cnt++;

    return true;
}


// pos 的值从1开始
bool insert_arr(struct Arr * pArr, int pos, int elem) 
{
    if ( is_full(pArr) ) {
        return false;
    }
    if ( pos < 1 || pos > pArr->cnt+1 ) {
        return false;
    }

    // 移位
    for (int i = pArr->cnt-1; i >= pos-1; i-- ) {
        pArr->pBase[i+1] = pArr->pBase[i];
    }
    // 插入
    pArr->pBase[pos-1] = elem;
    pArr->cnt++;
    return true;
}


// pos 从1开始
bool delete_arr(struct Arr * pArr, int pos, int * pElem) 
{
    if ( is_empty(pArr) ) {
        return false;
    }
    if ( pos < 1 || pos > pArr->cnt ) {
        return false;
    }

    *pElem = pArr->pBase[pos-1];
    // 删除
    for (int i = pos; i < pArr->cnt; i++) {
        pArr->pBase[i-1]  = pArr->pBase[i];
    }
    pArr->cnt--;
    return true;
}


bool traverse_arr(struct Arr * pArr, void (*fun)(int)) 
{
    if ( is_empty(pArr) ) {
        printf("数组为空！\n");
        return false;
    }

    for ( int i = 0; i < pArr->cnt; i++ ) {
        (*fun)(pArr->pBase[i]);
    }
    printf("\n");
    return true;
}

// 辅助函数
static void print_elem(int elem) 
{
    printf("%d ", elem);
}


void inverse_arr(struct Arr * pArr) 
{
    int i = 0, j = pArr->cnt-1;
    int temp;

    while (i < j) {
        temp = pArr->pBase[i];
        pArr->pBase[i++] = pArr->pBase[j];
        pArr->pBase[j--] = temp; 
    }
}


void sort_arr(struct Arr * pArr)
{
    int temp;

    for ( int i = 0; i < pArr->cnt; i++ ) {
        for ( int j = i+1; j < pArr->cnt; j++ ) {
            if ( pArr->pBase[i] > pArr->pBase[j] ) {
                temp = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = temp;
            }
        }
    }
}