/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-11-18 16:08:24
 * @FilePath: \DaHua\Chapter9_Sort\main.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include "sort.h"

#define N 9

int main(void)
{
    int d[N] = {237, 43, 56, 34, 343, 546, 232, 545, 65};
    SqList L;
    
    for (int i = 0; i < N; i++)     
        L.arr[i+1] = d[i];
    L.length = N;

    for (int i = 1; i <= N; i++)        
        printf("%d ", L.arr[i]);
	
    printf("\n");
    //BubbleSort1(&L);
    //SelectSort(&L);
    InsertSort(&L);
    for (int i = 1; i <= N; i++)        
        printf("%d ", L.arr[i]);

    return 0;
}