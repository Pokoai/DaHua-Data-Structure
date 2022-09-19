/*
 * 功能: 队列-链式结构
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Qtructure/tree/main/%E6%9C%80%E6%96%B0%E4%BC%98%E5%8C%96%E7%89%88%E4%BB%A3%E7%A0%81
 * Date: 2022-09-16
 */

#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

typedef int ElemType;

// 定义链式节点的数据类型
typedef struct node {
    ElemType data;
    struct node * pNext;
} Node, *pNode;

// 利用链式节点构造链式队列的数据类型
typedef struct linkqueue {
    pNode pFront;
    pNode pRear;
} LinkQueue, *pLinkQueue;

// 链式队列示意图：https://img.arctee.cn/one/202209162337604.png


extern void InitQueue(pLinkQueue Q);
extern bool EnQueue(pLinkQueue Q, ElemType elem);
extern void Traverse(pLinkQueue Q);
extern bool IsEmpty(pLinkQueue Q);
extern bool DeQueue(pLinkQueue Q, ElemType * pElem);
extern void DestoryQueue(pLinkQueue Q);
extern void ClearQueue(pLinkQueue Q);


#endif