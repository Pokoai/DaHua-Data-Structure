/*
 * @Description: 《大话数据结构》栈-链式实现
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-22 10:46:04
 * @LastEditTime: 2021-09-26 09:40:16
 * @FilePath: \DaHua\Chapter4_Stack\linkstack.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"


//初
void InitStack(LinkStack * s)
{
    s->top = NULL;
    s->count = 0;
}

//空
bool StackIsEmpty(LinkStack s)
{
    if (s.count == 0)
        return true;
    else 
        return false;
}

//个
int StackLength(LinkStack s)
{
    return s.count;
}

//增
bool Push(LinkStack * s, ElemType e)
{
    LinkStackPtr pnode;

    //分配内存空间
    pnode = (LinkStackPtr)malloc(sizeof(StackNode));
    if(pnode == NULL) {
        puts("内存分配失败");
        return false;
    }
    pnode->data = e;
    pnode->next = s->top;
    s->top = pnode;
    s->count++;

    return true;
}

//删
bool Pop(LinkStack * s, ElemType * e)
{
    LinkStackPtr p = s->top; //s->top 是指向链栈节点的指针

    //空异常处理
    if (StackIsEmpty(*s)) {
        puts("栈为空");
        return false;
    }
     
    *e = p->data;
    s->top = p->next;
    s->count--;

    free(p);
    return true;
}

//取
bool GetTop(LinkStack s, ElemType *e)
{
    if (StackIsEmpty(s)) {
        puts("栈为空.");
        return false;
    }

    *e = s.top->data;

    return true;
}

//遍
void StackTraverse(LinkStack s, void (*func)(ElemType))
{
    LinkStackPtr p = s.top;

    while (p) {
        (*func)(p->data);
        p = p->next;
    }
}

//清
void ClearStack(LinkStack * s)
{
    LinkStackPtr p = s->top;
    LinkStackPtr q;

    while (p) {
        q = p;
        p = p->next;
        free(q);
    }

    s->count = 0; //一开始忘记了这句
}
