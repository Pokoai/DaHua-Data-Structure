/*
 * 功能: 简单排序-冒泡排序
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-10-11
 */


// 思想：从后往前，依次比较相邻两数，将较小的值往前推进。内层循环一次，则推进一位，外层循环一次，则完成其中一个数值的排序。


#include <stdio.h>
#include <stdbool.h>


// -------------------顺序表结构----------------------
#define MAXSIZE 1000  // 顺序表中数组元素最大个数

// 顺序表结构
typedef struct {
    int arr[MAXSIZE+1];  // arr[0]用作哨兵或临时变量
    int length;          // 顺序表有效长度，从1计起，如length=5时，实际上有6个元素（包含arr[0]）
} SqList;
// -------------------顺序表结构----------------------


static void swap(SqList *L, int i, int j);
void BubbleSort0(SqList *L);  // 初级冒泡排序
void BubbleSort(SqList *L);   // 正宗冒泡排序
void BubbleSort2(SqList *L);


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
    printf("原始数组：    ");
    for ( int i = 1; i <= L.length; i++ ) {
        printf("%d ", L.arr[i]);
    }
    printf("\n");

    printf("初级冒泡排序：");
    BubbleSort0(&L);
    for ( int i = 1; i <= L.length; i++ ) {
        printf("%d ", L.arr[i]);
    }
    printf("\n");

    printf("正宗冒泡排序：");
    BubbleSort(&L);
    for ( int i = 1; i <= L.length; i++ ) {
        printf("%d ", L.arr[i]);
    }
    printf("\n");

    printf("冒泡排序优化：");
    BubbleSort2(&L);
    for ( int i = 1; i <= L.length; i++ ) {
        printf("%d ", L.arr[i]);
    }
    printf("\n");

    return 0;
}

// 初级冒泡排序（实际上并不算是冒泡排序，而是交换排序）
void BubbleSort0(SqList *L)
{
    for ( int i = 1; i < L->length; i++ ) {  // a[1] ~ a[length-1]
        for ( int j = i + 1; j <= L->length; j++ ) {  // a[i+1] ~ a[length] 
            if ( L->arr[i] > L->arr[j] ) {  // 将最小值交换到最前面第i个位置
                swap(L, i, j);
            }
        }
    }
}

// 正宗冒泡排序（比较相邻两数）
void BubbleSort(SqList *L) 
{
    for ( int i = 1; i < L->length; i++ ) {  // i < L->length，倒数第二个排好了，自然最后一个也排好了，无需 i = L->length
        for ( int j = L->length-1; j >= i; j-- ) {
            if ( L->arr[j] > L->arr[j+1] ) {
                swap(L, j, j+1);
            }
        }
    }
}

// 冒泡排序优化
// 如序列 {2, 1, 3, 4, 5, 6, 7, 8, 9}，实际上 i = 1时排序就完成了，i = 2~9是多余的
void BubbleSort2(SqList *L)
{
    bool flg = true;  // 初始值为true，为了一开始能够进入外层for循环
    
    for ( int i = 1; i < L->length && flg; i++ ) {  // flg为true时才进入循环
        flg = false;  // 一般将flg置为false，只有有交换发生时才置为true
        for ( int j = L->length-1; j >= i; j-- ) {
            if ( L->arr[j] > L->arr[j+1] ) {
                swap(L, j, j+1);
                flg = true;  // 发生了交换，故置为true
            }
        }
    }
}



// 辅助函数：较小数放到前面
static void swap(SqList *L, int i, int j)
{
    if ( L->arr[i] > L->arr[j] ) {
        int temp = L->arr[i];
        L->arr[i] = L->arr[j];
        L->arr[j] = temp;
    }
}