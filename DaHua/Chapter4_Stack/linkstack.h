/*
 * @Description: 《大话数据结构》栈-链式实现
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-22 10:46:41
 * @LastEditTime: 2021-09-25 11:29:55
 * @FilePath: \DaHua\Chapter4_Stack\linkstack.h
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

#include <stdbool.h>

typedef int ElemType;
//链栈结构
typedef struct stackNode{
    ElemType data;
    struct stackNode * next;
}StackNode;
typedef StackNode * LinkStackPtr; //指向栈节点的指针

typedef struct {
    LinkStackPtr top; //栈的头指针，即链表的头指针
    int count;
}LinkStack; //至此链栈结构搭建完毕


//初
void InitStack(LinkStack * s);

//空
bool StackIsEmpty(LinkStack s);

//个
int StackLength(LinkStack s);

//增
bool Push(LinkStack * s, ElemType e);

//删
bool Pop(LinkStack * s, ElemType * e);

//取
bool GetTop(LinkStack s, ElemType *e);

//遍
void StackTraverse(LinkStack s, void (*func)(ElemType));

//清
void ClearStack(LinkStack * s);


#endif
