/*
 * 功能: 简单排序-插入排序
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Qtructure/tree/main/%E6%9C%80%E6%96%B0%E4%BC%98%E5%8C%96%E7%89%88%E4%BB%A3%E7%A0%81
 * Date: 2022-10-11
 */


// 思想：每次将一个元素插入到已经排好序的有序表中，重点在于如何确定往前插入的位置（或者叫如何往后移动元素）
// 冒泡排序：每次循环都要两两元素比较；
// 选择排序：每次循环拿一个元素与其他所有剩余元素比较；
// 插入排序：每次循环拿一个元素与已经排好序的元素表比较；
// 由上可见，虽然时间复杂度均为 O(n*n)，但插入排序性能优于冒泡和选择排序


#include <stdio.h>


// -------------------顺序表结构----------------------
#define MAXSIZE 1000  // 顺序表中数组元素最大个数

// 顺序表结构
typedef struct {
    int arr[MAXSIZE+1];  // arr[0]用作哨兵或临时变量
    int length;          // 顺序表有效长度，从1计起，如length=5时，实际上有6个元素（包含arr[0]）
} SqList;
// -------------------顺序表结构----------------------


static void swap(SqList *L, int i, int j);
void InsertSort(SqList *L);  // 直接插入排序


int main(void)
{
    SqList L;

    L.length = 10;

    L.arr[1] = 3;
    L.arr[2] = 2;
    L.arr[3] = 13;
    L.arr[4] = 22;
    L.arr[5] = 11;
    L.arr[6] = 6;
    L.arr[7] = 9;
    L.arr[8] = 4;
    L.arr[9] = 19;
    L.arr[10] = 24;

    printf("原始数组：");
    for ( int i = 1; i <= L.length; i++ ) {
        printf("%d ", L.arr[i]);
    }
    printf("\n");

    printf("插入排序：");
    InsertSort(&L);
    for ( int i = 1; i <= L.length; i++ ) {
        printf("%d ", L.arr[i]);
    }
    printf("\n");

    return 0;
}

// 直接插入排序
void InsertSort(SqList *L)
{
    // i=2: 第1个元素已经默认放在那里，从第2个元素开始按照大小关系往其中插入
    // 大于则自然插到后面一位
    // 小于时复杂些，知道往前插入，但是往前几位插入，需要进行逐位比较后确定插入位置
    for ( int i = 2; i <= L->length; i++ ) {  
        if ( L->arr[i] < L->arr[i-1] ) {  // L->arr[i]: 本次需要插入的元素； L1->a[i-]：有序表最后一个元素
            // （旧解释：开始往前逐位比较）
            // 新解释（更好理解）：将比插入值大的元素都往后移动一位，确定往前待插入位置
            L->arr[0] = L->arr[i];  // 设置哨兵，首先将需要插入的值保存起来

            int j;  // （旧解释：j为待插入的位置，从 i-1位置开始，逐次往前进(j--)，直到遇到比待插入值小的元素(L->arr[j] < L->arr[0])时结束，此时最终确定了往前插入位置j+1）
            for ( j = i-1; L->arr[j] > L->arr[0]; j-- ) {  // 新解释（更好理解）：从最后一个（i-1）元素开始，直到比待插入值小的元素为止，均往后移动一位，空出的位置留给待插入元素
                L->arr[j+1] = L->arr[j];  // 将比待插入值大的值往后移动，腾出一个位置给待插入元素
            }  // 至此，往后移动完毕，确定了插入位置
            // 开始插入
            L->arr[j+1] = L->arr[0];  // 为何是j+1而非j？因为其他元素已经往后移动了一位，把自身的位置留出来了。如最开始j = i-1时，如果只有这一元素（第i位置）比插入值大，那么实际插入位置是i，而非i-1，因为第i位置元素往后移动了一位，将自身位置让给了插入值
        }
    }
}