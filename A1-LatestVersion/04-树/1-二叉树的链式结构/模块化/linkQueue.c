/*
 * 功能: 队列-链式结构
 * 作者: Guyue
 * 微信公众号(破壳Ai): https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-09-16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linkQueue.h"


// 初始化
void InitQueue(pLinkQueue Q)
{
    // 创建头节点
    pQNode pHead = (pQNode)malloc(sizeof(QNode));
    if ( NULL == pHead ) {
        printf("内存分配失败！");
        exit(-1);
    }
    pHead->pNext = NULL;

    // 头指针、尾指针均指向头节点
    Q->pFront = Q->pRear = pHead;
}

// 入队
bool EnQueue(pLinkQueue Q, QElemType elem)
{
    // 创建新节点
    pQNode pNew = (pQNode)malloc(sizeof(QNode));
    if ( NULL == pNew ) {
        printf("内存分配失败，无法入队！");
        return false;
    }
    pNew->data = elem;
    pNew->pNext = NULL;

    // 将新节点连接到队列尾部，然后将尾指针指向新节点
    Q->pRear->pNext = pNew;
    Q->pRear = pNew;

    return true;
}

// 遍历队列
void Traverse(pLinkQueue Q)
{
    pQNode p = Q->pFront;  

    while ( p != Q->pRear ) {
        // 头指针的后驱节点才是第一个有效数据
        printf("%d ", p->pNext->data);
        p = p->pNext;
    }
    printf("\n");
}

// 是否为空
bool QueueIsEmpty(pLinkQueue Q)
{
    return (Q->pFront == Q->pRear );
}

// 出队
bool DeQueue(pLinkQueue Q, QElemType * pElem)
{
    if ( QueueIsEmpty(Q) ) {
        printf("队列为空，出队失败！");
        return false;
    }

    pQNode p = Q->pFront;

    *pElem = p->pNext->data;
    Q->pFront = p->pNext;  // 将头指针往后移动一位

    free(p);
    p = NULL;

    return true;
}

// 销毁队列
void DestoryQueue(pLinkQueue Q)
{
    pQNode p = Q->pFront;


    while( p != NULL ) {
        Q->pFront = p->pNext;
        free(p);
        p = Q->pFront;
    }
}

// 清空队列
// 保留头节点
void ClearQueue(pLinkQueue Q)
{
    DestoryQueue(Q);
    InitQueue(Q);
}