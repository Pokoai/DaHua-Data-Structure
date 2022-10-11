/*
 * 功能: 简单排序-选择排序
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Qtructure/tree/main/%E6%9C%80%E6%96%B0%E4%BC%98%E5%8C%96%E7%89%88%E4%BB%A3%E7%A0%81
 * Date: 2022-10-11
 */


// 思想：每次循环（如第i次循环）都找出所剩元素中最小的一个，并将其放到序位（i）上。
// 相当于每次只选择出一位元素进行交换，而非冒泡排序那样，每次循环几乎所剩每个元素都要交换一次。
// 所以，虽然时间复杂度均为 O(n*n)，但是选择排序的性能还是要略优于冒泡排序。


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
void SelectSort(SqList *L);  // 简单选择排序


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

    printf("选择排序：");
    SelectSort(&L);
    for ( int i = 1; i <= L.length; i++ ) {
        printf("%d ", L.arr[i]);
    }
    printf("\n");

    return 0;
}

// 简单选择排序
void SelectSort(SqList *L)
{
    int min;  // 存储每次外层循环时准备要安置好的序位号，故每次进入外层循环后赋值为本次循环数i

    for ( int i = 1; i < L->length; i++ ) {  // 前面排好了，最后一位元素自然就排好了，所以无需排序最后一位
        min = i;
        for ( int j = i+1; j <= L->length; j++ ) {  // 从剩余未排好序的所有元素找出最小值
            if ( L->arr[j] < L->arr[min] ) {
                min = j;
            }
        }  // 至此，找到最小值的下标min

        // 将该最小值交换到它的序列位i上
        if ( min != i ) {  // 这一句不加也可以，但是加了会提高一点效率，因为如果最小值就是其本身的话，就无需自己跟自己交换了
            swap(L, i, min);  // 外层循环中只有一次swap()
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