/*
 * @Description: 《大话数据结构》栈-顺序(数组)实现
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-21 00:27:04
 * @LastEditTime: 2021-09-22 10:43:42
 * @FilePath: \DaHua\Chapter4_Stack\sqstack.h
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#ifndef _SQSTACK_H_
#define _SQSTACK_H_

#include <stdbool.h>
#define MAXSIZE 100

typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int top;
}SqStack;


//初始化
void InitStack(SqStack * s);

//空
bool StackIsEmpty(SqStack s);

//个
int StackLength(SqStack s);

//增
bool push(SqStack * s, ElemType e);

//删
bool pop(SqStack * s, ElemType * e);

//取
bool GetElem(SqStack s, ElemType *e);

//遍
void StackTraverse(SqStack s, void (*func)(ElemType e));

//清
void ClearStack(SqStack * s);

#endif