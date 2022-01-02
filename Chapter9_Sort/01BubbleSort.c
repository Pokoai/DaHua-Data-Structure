/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-11-18 16:03:34
 * @FilePath: \DaHua\Chapter9_Sort\01BubbleSort.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdbool.h>
#include "sort.h"

// // 交换list中的两个元素
// void swap(SqList * L, int i, int j)
// {
//     int temp;

//     temp = L->arr[i];
//     L->arr[i] = L->arr[j];
//     L->arr[j] = temp;
// }


// 初级冒泡排序，实际上并不是两两交换，而是某个元素与之后面的所有元素比较
void BubbleSort1(SqList * L)
{
    for (int i = 1; i < L->length; i++) { // <,不需要=，因为倒数第一个排好了，最后一个自然排好
        for (int j = i+1; j <= L->length; j++) { // j<=, 这里需要包含最后一个元素
            if (L->arr[j] < L->arr[i])
                swap(L, i, j);
        }
    }
}


//正宗的冒泡排序，从最后开始两两比较
void BubbleSort(SqList * L)
{
    for (int i = 1; i < L->length; i++) { 
        for (int j = L->length-1; j >=i; j--) { // j=length-1,从倒数第二个开始，不包含最后一元素，因为下一步有 j+1
            if (L->arr[j+1] < L->arr[j])
                swap(L, j , j+1);
        }
    }
}


// 改进冒泡排序
void BubbleSort2(SqList * L)
{
    bool flag = true;

    for (int i = 1; i < L->length && flag; i++) {
        flag = false;
        for (int j = L->length-1; j >= i; j--) {
            if (L->arr[j+1] < L->arr[j]) {
                swap(L, j, j+1);
                flag = true;
            }
        }
    }
}