/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-11-17 01:56:13
 * @FilePath: \DaHua\Chapter9_Sort\sort.h
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#ifndef _SORT_H_
#define _SORT_H_

#define MAXSIZE 10000

// 顺序表结构
typedef struct {
    int arr[MAXSIZE+1]; // 存储用于排序的数组，其中arr[0]用作哨兵或临时变量
    int length; // 顺序表的长度
}SqList;

void swap(SqList * L, int i, int j);
void BubbleSort1(SqList * L);
void SelectSort(SqList * L);
void InsertSort(SqList * L);


#endif