/*
 * @Description: 《大话数据结构》循环队列-顺序结构-头文件
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-09-24 17:55:02
 * @LastEditTime: 2021-10-14 18:36:11
 * @FilePath: \DaHua\Chapter4_Stack\sqQueue.h
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#ifndef _SQQUEUE_H_
#define _SQQUEUE_H_

#include <stdbool.h>

#define MAXSIZE 20

typedef int ElemType;

//循环队列的顺序存储结构
typedef struct {
    ElemType data[MAXSIZE]; 
    int front; 
    int rear;
}SqQueue;


//初空满个 增删改查 取遍清

//初
void InitQueue(SqQueue * Q);

//空
bool QueueIsEmpty(SqQueue Q);

//满
bool QueueIsFull(SqQueue Q);

//个
int QueueLength(SqQueue Q);

//增
bool EnQueue(SqQueue * Q, ElemType e);

//删
bool DeQueue(SqQueue * Q, ElemType * e);

//取
bool GetHead(SqQueue Q, ElemType * e);

//遍
bool QueueTraverse(SqQueue Q, void (*func)(ElemType e));

//清
void ClearQueue(SqQueue * Q);

#endif