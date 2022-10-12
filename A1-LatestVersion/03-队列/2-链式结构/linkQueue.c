/*
 * 功能: 队列-链式结构
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Qtructure/tree/main/%E6%9C%80%E6%96%B0%E4%BC%98%E5%8C%96%E7%89%88%E4%BB%A3%E7%A0%81
 * Date: 2022-09-16
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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


void InitQueue(pLinkQueue Q);
bool EnQueue(pLinkQueue Q, ElemType elem);
void Traverse(pLinkQueue Q);
bool IsEmpty(pLinkQueue Q);
bool DeQueue(pLinkQueue Q, ElemType * pElem);
void DestoryQueue(pLinkQueue Q);
void ClearQueue(pLinkQueue Q);



int main(void)
{
    LinkQueue Q;

    InitQueue(&Q);

    printf("入队：");
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    EnQueue(&Q, 4);
    EnQueue(&Q, 5);
    Traverse(&Q);

    printf("出队：");
    ElemType e;
    DeQueue(&Q, &e);
    DeQueue(&Q, &e);
    DeQueue(&Q, &e);
    Traverse(&Q);

    return 0;
}

// 初始化
void InitQueue(pLinkQueue Q)
{
    // 创建头节点
    pNode pHead = (pNode)malloc(sizeof(Node));
    if ( NULL == pHead ) {
        printf("内存分配失败！");
        exit(-1);
    }
    pHead->pNext = NULL;

    // 头指针、尾指针均指向头节点
    Q->pFront = Q->pRear = pHead;
}

// 入队
bool EnQueue(pLinkQueue Q, ElemType elem)
{
    // 创建新节点
    pNode pNew = (pNode)malloc(sizeof(Node));
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
    pNode p = Q->pFront;  

    while ( p != Q->pRear ) {
        // 头指针的后驱节点才是第一个有效数据
        printf("%d ", p->pNext->data);
        p = p->pNext;
    }
    printf("\n");
}

// 是否为空
bool IsEmpty(pLinkQueue Q)
{
    return (Q->pFront == Q->pRear );
}

// 出队
bool DeQueue(pLinkQueue Q, ElemType * pElem)
{
    if ( IsEmpty(Q) ) {
        printf("队列为空，出队失败！");
        return false;
    }

    pNode p = Q->pFront;

    *pElem = p->pNext->data;
    Q->pFront = p->pNext;  // 将头指针往后移动一位

    free(p);
    p = NULL;

    return true;
}

// 销毁队列
void DestoryQueue(pLinkQueue Q)
{
    pNode p = Q->pFront;

    while( p != NULL ) {
        Q = p->pNext;
        free(p);
        p = Q;
    }
}

// 清空队列
// 保留头节点
void ClearQueue(pLinkQueue Q)
{
    pNode p = Q->pFront->pNext;

    DestoryQueue(p);
    Q->pRear = Q->pFront;
    Q->pFront->pNext = NULL;
}