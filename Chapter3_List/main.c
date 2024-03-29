/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @Github: https://github.com/pokoai
 * @Date: 2021-09-17 22:34:23
 * @LastEditTime: 2021-10-14 18:34:02
 * @FilePath: \DaHua\Chapter3_List\main.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include "linklist.h"

void printList(ElemType elem);

int main(void)
{   
    LinkList newList;
    ElemType e;

    InitList(&newList);

    ListInsert(&newList, 1, 5);
    ListInsert(&newList, 2, 10);
    ListInsert(&newList, 3, 1);
    ListInsert(&newList, 4, 90);
    ListInsert(&newList, 5, 15);
    ListInsert(&newList, 6, 123);

    ListDelet(&newList, 4, &e);

    ListChange(&newList, 1, 0);

    if (ListIsEmpty(newList)) {
        printf("List is empty!");
        exit(1);
    }
    ListTraverse(newList, *printList);
    printf("Number of Elements: %d\n", ListLength(newList));

    return 0;
}

// 打印元素
void printList(ElemType elem)
{
    printf("%d ", elem);
}
