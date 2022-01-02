/*
 * @Description: 《大话数据结构》线性表-顺序存储结构（数组）- 实现接口
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-09-17 12:23:16
 * @FilePath: \DaHua\Chapter3_List\sqlist.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include "sqlist.h"

// 记忆口诀：“初空个 增删改查 取遍清”

// 1、初——初始化
void InitList(SqList * list) 
{
    // for (int j = 0; j < list->length; j++) {
    //     list->data[j] = 0;
    // }

    list->length = 0;
}

// 2、空——判断是否空
bool ListIsEmpty(SqList list)
{
    if (list.length == 0)
        return true;
    else 
        return false;
}

// 3、个——获取元素个数
int ListLength(SqList list)
{
    return list.length;
}

// 4、增——在表的第i个位置插入元素e
bool ListInsert(SqList * list, int i, ElemType e)
{
    if(list->length >= MAXSIZE) //数组已满，抛出异常
        return false;
    if (i < 1 || i > list->length + 1) //插入范围错误，抛出异常
        return false;
    //插入的位置不在length+1处
    if (i <= list->length) {
        for (int j = list->length -1 ; j >= i - 1; j--) 
            list->data[j + 1] = list->data[j];
    }
    list->data[i-1] = e; //如果插入位置在length+1，这条语句也包含了这种情况
    list->length++;

    return true;
}

// 5、删——删除表中位置i的元素，并存储在e中
bool ListDelet(SqList * list, int i, ElemType * e)
{   if (list->length == 0)
        return false;
    if(i < 1 || i > list->length)
        return false;
    *e = list->data[i-1]; 
    if (i < list->length) {    //删除的不是最后位置
        for (int j = i; j <= list->length; j++) 
            list->data[j-1] = list->data[j];
    }
    list->length--; //包含了删除最后一个元素的情况

    return true;
}

// 6、改——将表中第i个元素改为e
bool ListChange(SqList * list, int i, ElemType e)
{
    if (i < 1 || i > list->length) {
        puts("i out of range.");
        return false;
    }
    list->data[i - 1] = e;
    
    return true;
}

// 7、查——查询线性表中是否存在元素e，找到返回表中序号，否则返回0
int LocateElem(SqList list, ElemType e)
{
    if (list.length == 0)
        return 0;
    for (int j = 0; j < list.length; j++) {
        if (list.data[j] == e)
            return (j+1);
    }
    return 0;
}

// 8、取——获取第i个位置的元素，并存储在e中
bool GetElem(SqList list, int i, ElemType * e)
{
    if (list.length == 0 || i < 1 || i > list.length) //异常处理
        return false;
    *e = list.data[i-1];
    
    return true;
}

// 9、遍——遍历所有元素，执行某种操作
void ListTraverse(SqList list, void (*func)(ElemType elem))
{
    for (int i = 0; i < list.length; i++) {
        (*func)(list.data[i]);
    }
}

// 10、清——清空线性表
void Clear(SqList * list)
{
    // for (int j = 0; j < list->length; j++) {
    //     list->data[j] = 0;
    // }

    list->length = 0;
}

//合并两个线性表
void UnionL(SqList * La, SqList Lb)
{
    int lbLength = ListLength(Lb);
    int laLength = ListLength(*La);
    ElemType e;

    for (int i = 0; i < lbLength; i++) {
        GetElem(Lb, i, &e);
        if (!LocateElem(*La, e)) {
            ListInsert(La, laLength++, e);
        }
    }
}