/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-11-18 19:23:25
 * @FilePath: \DaHua\Chapter9_Sort\03InsertSort.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include "sort.h"

// 插入排序   main执行时结果错误，但是未找出排序代码有什么问题，后面再看
void InsertSort(SqList * L) 
{
    int j;
    for (int i = 2; i <= L->length; i++) { // 假定第一个位置i-1是已经排好的
        if (L->arr[i] < L->arr[i-1]) { // 右侧位置的值小于已排好位置的值
            L->arr[0] = L->arr[i]; // 将小的值存入哨兵arr[0]处
            // 下面是关键所在，移动其他值。要分清楚谁要移谁不用移
            for (int j = i-1; L->arr[j] > L->arr[0]; j--) // 首先从紧邻的i-1位置开始，往前探寻，只要是比arr[0]大的都要移动
                L->arr[j+1] = L->arr[j];
            L->arr[j+1] = L->arr[0]; // 插入到合适位置
        }
    }
}