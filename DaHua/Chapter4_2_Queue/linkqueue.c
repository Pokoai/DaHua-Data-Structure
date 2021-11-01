/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-09-25 10:58:45
 * @LastEditTime: 2021-11-01 18:57:47
 * @FilePath: \DaHua\Chapter4_2_Queue\linkqueue.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

//初始化
bool InitQueue(LinkQueue * Q)
{
    //因为此链式结构中需要一个头节点
    //所以初始化时就要分配一个内存空间
    //如果不要头节点的话就不用这一步了
    Q->front = (LinkQueuePtr)malloc(sizeof(QueueNode)); //创建一个头节点,头结点的指针即Q->front
    if (Q->front == NULL)
        return false;
    
    //初始化: 1.首尾指针均指向头结点， 2.头结点指向null 3.长度置为0
    Q->rear = Q->front;
    Q->front->next = NULL;  //注意：这里的初始化是针对头节点的next的，而非头节点本身
    Q->length = 0;

    return true;
}

//判空
bool QueueIsEmpty(LinkQueue Q)
{
    if (Q.length == 0)
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
    LinkQueuePtr pnode, q;

    //分配内存空间
    pnode = (LinkQueuePtr)malloc(sizeof(QueueNode));
    if (pnode == NULL)
        return false;

    //新节点初始化
    pnode->data = e;
    pnode->next = NULL;
    //插入队列
    (Q->rear)->next = pnode; 
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

//取头元素
bool GetHead(LinkQueue Q, ElemType * e)
{
    LinkQueuePtr pnode = Q.front->next; //p指向第一个节点
    //判空
    if (QueueIsEmpty(Q))
        return false;

    *e = pnode->data;

    return true;
}

//遍历队列，执行 func 函数操作
void QueueTraverse(LinkQueue Q, void (*func)(ElemType e))
{
    LinkQueuePtr pnode = Q.front->next;

    while (pnode != NULL) {
        (*func)(pnode->data);
        pnode = pnode->next;
    }
}

//清空队列，保留头节点
void ClearQueue(LinkQueue * Q)
{
    LinkQueuePtr pnode = Q->front->next;  //不涉及头节点，所以从第一个节点开始
    LinkQueuePtr qnode;

    while (pnode != NULL) {
        qnode = pnode; //q指向第一个节点
        pnode = pnode->next; //p指向第二个节点

        free(qnode);
    }
    Q->front->next = NULL;
    Q->rear = Q->front;
    Q->length = 0;
}

// //销毁队列，连头节点也释放掉了
//本例，front和rear均未释放
// void DestroyQueue(LinkQueue *Q)
// {
//     LinkQueuePtr pnode = Q->front; //头节点也要释放，所以从头节点开始
//     LinkQueuePtr qnode;

// 	while(pnode != NULL)
// 	{
// 		qnode = pnode;
//         pnode = pnode->next;

// 		free(qnode);
// 	}
// }

//本例，rear未释放
// void DestroyQueue(LinkQueue *Q)
// {
//     LinkQueuePtr pnode; //头节点也要释放，所以从头节点开始

// 	while(Q->front != NULL)
// 	{
// 		pnode = Q->front->next;
// 		free(Q->front);
//         Q->front = pnode;
// 	}
// }

//本例，都释放
void DestroyQueue(LinkQueue *Q)
{
	while(Q->front)
	{
		 Q->rear = Q->front->next; //要释放front和rear,则两者都要参与进来，而非赋值给其他变量
		 free(Q->front);
		 Q->front = Q->rear;
	}
}