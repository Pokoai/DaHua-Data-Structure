/*
 * 功能: 队列-链式结构
 * 作者: Guyue
 * 微信公众号(破壳Ai): https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-09-16
 */

#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#include <stdbool.h>


/*------------------------- 链式队列结构定义 ------------------------*/

typedef int QElemType;  // 这里的 int 根据实际更改  

// 定义链式节点的数据类型
typedef struct qNode {
    QElemType data;
    struct qNode * pNext;
} QNode, *pQNode;

// 利用链式节点构造链式队列的数据类型
typedef struct linkqueue {
    pQNode pFront;
    pQNode pRear;
} LinkQueue, *pLinkQueue;

// 链式队列示意图：https://img.arctee.cn/one/202209162337604.png

/*------------------------- 链式队列结构定义 ------------------------*/


extern void InitQueue(pLinkQueue Q);
extern bool EnQueue(pLinkQueue Q, QElemType elem);
extern void Traverse(pLinkQueue Q);
extern bool QueueIsEmpty(pLinkQueue Q);
extern bool DeQueue(pLinkQueue Q, QElemType * pElem);
extern void DestoryQueue(pLinkQueue Q);
extern void ClearQueue(pLinkQueue Q);


#endif