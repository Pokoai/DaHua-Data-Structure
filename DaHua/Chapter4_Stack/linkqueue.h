/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-25 10:58:12
 * @LastEditTime: 2021-09-25 17:14:53
 * @FilePath: \DaHua\Chapter4_Stack\linkqueue.h
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#include <stdbool.h>

typedef int ElemType;

//创建链队列结构
typedef struct queueNode {   //首先构建节点模型
    ElemType data;
    struct queueNode * next;
}QueueNode, *LinkQueuePtr;

typedef struct {            //然后利用节点构建队列的链式结构
    LinkQueuePtr front;
    LinkQueuePtr rear;
    int length;
}LinkQueue;


//初空个 增删 取遍清

//初始化
void InitQueue(LinkQueue * Q);

//判空
bool QueueIsEmpty(LinkQueue Q);

//队列中元素个数
int QueueLength(LinkQueue Q);

//入队
bool EnQueue(LinkQueue * Q, ElemType e);

//出队
bool DeQueue(LinkQueue * Q, ElemType * e);

//取头元素
bool GetHead(LinkQueue Q, ElemType * e);

//遍历队列，执行 func 函数操作
void QueueTraverse(LinkQueue Q, void (*func)(ElemType e));

//清空队列
void ClearQueue(LinkQueue * Q);

#endif
