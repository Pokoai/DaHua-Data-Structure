/*
 * @Description: 《大话数据结构》线性表-顺序存储结构（数组）-头文件（接口）
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-09-17 12:26:50
 * @LastEditTime: 2021-10-31 20:56:09
 * @FilePath: \DaHua\Chapter3_List\sqlist.h
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#ifndef _SQLIST_H_
#define _SQLIST_H_

#include <stdbool.h>

#define MAXSIZE 20

typedef int ElemType;
// 线性表顺序存储结构
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;


// 记忆口诀：“初空个 增删改查 取遍清”


// 1、初始化
void InitList(SqList * list);

// 2、判断是否空
bool ListIsEmpty(SqList list);

// 3、元素个数
int ListLength(SqList list);

// 4、增
bool ListInsert(SqList * list, int i, ElemType e);

// 5、删
bool ListDelet(SqList * list, int i, ElemType * e);

// 6、改
bool ListChange(SqList * list, int i, ElemType e);

// 7、查
int LocateElem(SqList list, ElemType e);

// 8、取
bool GetElem(SqList list, int i, ElemType * e);

// 9、遍
void ListTraverse(SqList list, void (*func)(ElemType elem));

// 10、清空
void Clear(SqList * list);

//合并两个线性表
void UnionL(SqList * La, SqList Lb);


#endif