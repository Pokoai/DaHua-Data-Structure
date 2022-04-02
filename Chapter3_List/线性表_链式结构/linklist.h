/*
 * @Description: 《大话数据结构》线性表-链式存储结构-头文件（接口）
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-09-20 16:50:57
 * @LastEditTime: 2021-10-14 18:33:44
 * @FilePath: \DaHua\Chapter3_List\linklist.h
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */


#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdbool.h>

typedef int ElemType;

//定义链式数据结构的节点
typedef struct node {
    ElemType data;
    struct node * next;
}Node;

typedef Node * LinkList; //定义结点指针

//初空个 增删改查 取遍清


// 1、初始化
bool InitList(LinkList * list);

// 2、判断是否空
bool ListIsEmpty(LinkList list);

//判断是否已满
bool ListIsFull(LinkList list);

// 3、元素个数
int ListLength(LinkList list);

// 4、增
bool ListInsert(LinkList * list, int i, ElemType e);

// 5、删
bool ListDelet(LinkList * list, int i, ElemType * e);

// 6、改
bool ListChange(LinkList * list, int i, ElemType e);

// 7、查
int LocateElem(LinkList list, ElemType e);

// 8、取
bool GetElem(LinkList list, int i, ElemType * e);

// 9、遍
void ListTraverse(LinkList list, void (*func)(ElemType elem));

// 10、清空
void ClearList(LinkList * list);

#endif
