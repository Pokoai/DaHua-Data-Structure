/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-25 10:58:45
 * @LastEditTime: 2021-09-25 19:52:58
 * @FilePath: \DaHua\Chapter4_Stack\linkqueue.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include "linkqueue.h"

//初始化
void InitQueue(LinkQueue * Q)
{
    Q->front = NULL;
    Q->rear = NULL;
    Q->length = 0;
}

//判空
bool QueueIsEmpty(LinkQueue Q)
{
    if (Q->length == 0)
        return true;
    else
        return false;
}

//队列中元素个数
int QueueLength(LinkQueue Q)
{
    return Q.length;
}

//入队
bool EnQueue(LinkQueue * Q, ElemType e)
{
    LinkQueuePtr pnode;

    //分配内存空间
    pnode = (LinkQueuePtr)malloc(sizeof(QueueNode));
    if (pnode == NULL)
        return false;

    //新节点初始化
    pnode->data = e;
    pnode->next = NULL;
    //插入队列
    Q->rear->next = pnode;
    //尾指针指向新加入的节点
    Q->rear = pnode;
    //队列长度加一
    Q->length++;

    return true;
}

//出队
bool DeQueue(LinkQueue * Q, ElemType * e)
{
    LinkQueuePtr pnode;

    //判断非空
    if (QueueIsEmpty(*Q))
        return false;

    pnode = Q->front->next; //pnode指向将要出队的节点，Q->front为头节点
    *e = pnode->data;
    Q->front = pnode->next; //头节点指向第二个节点

    //若只有一个队员，那么出队后尾指针也要变化
    if (pnode == Q->rear)
        Q->rear = Q->front;

    free(pnode);  //不要忘记

    Q->length--;

    return true;
}



//出队
bool DeQueue(LinkQueue * Q, ElemType * e);

//取头元素
bool GetHead(LinkQueue Q, ElemType * e);

//遍历队列，执行 func 函数操作
void QueueTraverse(LinkQueue Q, void (*func)(ElemType e));

//清空队列
void ClearQueue(LinkQueue * Q);
