/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-11-18 19:46:36
 * @FilePath: \DaHua\Chapter9_Sort\swap.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include "sort.h"

// 交换list中的两个元素
void swap(SqList * L, int i, int j)
{
    int temp;

    temp = L->arr[i];
    L->arr[i] = L->arr[j];
    L->arr[j] = temp;
}