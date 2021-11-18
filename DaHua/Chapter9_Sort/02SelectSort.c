/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-11-18 18:42:07
 * @FilePath: \DaHua\Chapter9_Sort\02SelectSort.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include "sort.h"

// 选择排序
void SelectSort(SqList * L)
{
    int min;

    for (int i = 1; i < L->length; i++) {
        min = i;
        for (int j = i+1; j <= L->length; j++) {
            if (L->arr[j] < L->arr[min])
                min = j;
        }
        if (min != i)
            swap(L, i, min); // 每个循环中，比较多次，仅交换一次
    }
}