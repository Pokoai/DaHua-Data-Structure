/*
 * @Description: 《大话数据结构》栈-顺序(数组)实现
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-09-21 00:26:48
 * @LastEditTime: 2021-10-14 18:36:16
 * @FilePath: \DaHua\Chapter4_Stack\sqstack.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include "sqstack.h"


//初始化
void InitStack(SqStack * s)
{
    s->top = -1;
}

//空
bool StackIsEmpty(SqStack s)
{
    if (s.top == -1)
        return true;
    else 
        return false;   
}

//个
int StackLength(SqStack s)
{
    return s.top + 1;
}

//增
bool push(SqStack * s, ElemType e)
{
    //已满异常
    if (s->top == MAXSIZE - 1)
        return false;
    
    s->top++;
    s->data[s->top] = e;

    return true;
}

//删
bool pop(SqStack * s, ElemType *e)
{
    //已空异常
    if (s->top == -1 )
        return false;
    
    *e = s->data[s->top];
    s->top--;

    return true;
}

//取
bool GetElem(SqStack s, ElemType *e)
{
    if (s.top == -1)
        return false;
    
    *e = s.data[s.top];

    return true;
}

//遍
void StackTraverse(SqStack s, void (*func)(ElemType e))
{
    for (int i = 0; i <= s.top; i++) {
        (*func)(s.data[i]);
    }
}

//清
void ClearStack(SqStack * s)
{
    s->top = -1;
}

