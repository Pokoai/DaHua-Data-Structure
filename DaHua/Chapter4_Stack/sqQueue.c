/*
 * @Description: 《大话数据结构》循环队列-顺序结构-实现
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-24 17:55:16
 * @LastEditTime: 2021-09-25 10:32:17
 * @FilePath: \DaHua\Chapter4_Stack\sqQueue.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include "sqQueue.h"

//初空满个 增删改查 取遍清

//初
void InitQueue(SqQueue * Q)
{
    Q->front = 0;
    Q->rear = 0;
}

//空
bool QueueIsEmpty(SqQueue Q)
{
    if (Q.front == Q.rear) 
        return true;
    else 
        return false;
}

//满
bool QueueIsFull(SqQueue Q)
{
    if ((Q.rear + 1) % MAXSIZE == Q.front)
        return true;
    else 
        return false;
}

//个
int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

//增
bool EnQueue(SqQueue * Q, ElemType e)
{
    //1.判满
    if (QueueIsFull(*Q))
        return false;
    
    //2.插入
    Q->data[Q->rear] = e;

    //3.尾指针移位，要考虑到从末尾移到首位的情况
    Q->rear = (Q->rear + 1) % MAXSIZE;

    //4.返回成功的信号
    return true;
}

//删
bool DeQueue(SqQueue * Q, ElemType * e)
{
    //1.判空
    if (QueueIsEmpty(*Q))
        return false;
    
    //2.移出
    *e = Q->data[Q->front];

    //3.头指针移位，要考虑从末尾移到首位的情况
    Q->front = (Q->front + 1) % MAXSIZE;

    //4.返回成功信号
    return true;
}

//取
bool GetHead(SqQueue Q, ElemType * e)
{
    //1.判空
    if (QueueIsEmpty(Q))
        return false;
    
    //2.取
    *e = Q.data[Q.front];

    return true;
}

//遍
bool QueueTraverse(SqQueue Q, void (*func)(ElemType e))
{
    //1.判空
    if (QueueIsEmpty(Q))
        return false;
    //2.遍历
    int p = Q.front;
    while (p != Q.rear) {
        (*func)(Q.data[p]);
        p = (p + 1) % MAXSIZE;
    }

    return true;
}
// bool QueueTraverse(SqQueue Q, void (*func)(ElemType e))
// {
//     //1.判空
//     if (QueueIsEmpty(Q))
//         return false;
    
//     //2.尾指针在头指针后面，好办
//     else if (Q.rear > Q.front) {
//         for (int i = Q.front; i < Q.rear; i++)
//             (*func)(Q.data[i]);
//     }
//     //尾指针跑到头指针前面去了，分两步遍历
//     else {
//         // - 从头指针到末尾
//         for (int i = Q.front; i < MAXSIZE; i++)
//             (*func)(Q.data[i]);
//         // - 从头到尾指针
//         for (int i = 0; i < Q.rear; i++)
//             (*func)(Q.data[i]);
//     }

//     //返回成功的信号 (题外话：每到这里打的飞快，心情愉悦)
//     return true;
// }

//清
void ClearQueue(SqQueue * Q)
{
    Q->front = 0;
    Q->rear = 0;
}
