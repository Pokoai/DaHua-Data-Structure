
#include <stdio.h>
#include <stdlib.h>

#include "threadBiTree.h"


// 注意：线索遍历尚未实现


// 初始化
void InitThrBiTree(ThreadBiTree *pT)
{
    *pT = NULL;
}

// 创建线索二叉树
void CreateThrBiTree(ThreadBiTree *pT)
{
    TElemType e;

    scanf("%c", &e);
    if ( Nil == e ) {
        *pT = NULL;
    }
    else {
        *pT = (pThrBiTNode)malloc(sizeof(ThrBiTNode));  // 为根节点分配内存
        if ( NULL == *pT) {
            printf("内存分配失败！\n");
            exit(-1);
        }
        (*pT)->data = e;  // 将输入的值赋予节点

        CreateThrBiTree(&(*pT)->pLChild);  // 递归创建左子树
        if ( (*pT)->pLChild != NULL ) {    // 若左子树非空，则将左标志位置为 LINK
            (*pT)->lTag = LINK;
        }
        CreateThrBiTree(&(*pT)->pRChild);  // 递归创建右子树
        if ( (*pT)->pRChild != NULL ) {    // 若右子树非空，则将右标志位置为 LINK
            (*pT)->rTag = LINK;
        }
    }
}

// 中序遍历
// 遍历一次就要递归一次，比较耗时
void InOrderTraverse(ThreadBiTree T)
{
    if ( T != NULL ) {
        InOrderTraverse(T->pLChild);
        printf("%c ", T->data);
        InOrderTraverse(T->pRChild);
    }
}

// 中序线索化二叉树
void InThreading(ThreadBiTree T)  
{
    static pThrBiTNode pre = NULL;  // pre用来存储前驱节点，且仅初始化一次

    if ( T != NULL ) {
        // 递归左子树
        InThreading(T->pLChild);

        // 更新前驱
        if ( T->pLChild == NULL ) {  // 本节点的左孩子为空
            T->pLChild = pre;  // 将左指针指向前驱节点
            T->lTag = THREAD;  // 左标志位做相应更改
        }
        // 更新后继
        // 因为当前遍历到T，前驱节点 pre已经遍历过，那么此时仅知道 T和 pre，而后继节点还未遍历到，就无法再程序中使用
        // 故这里用了前驱节点的右孩子，而非后继节点的右孩子
        if ( pre->pRChild == NULL ) {  // 前驱节点的右孩子为空
            pre->pRChild = T;
            pre->rTag = THREAD;
        }
        pre = T;  // 更新 pre

        // 递归右子树
        InThreading(T->pRChild);
    }
}

// 中序遍历（未完成）
// 采用后继方式遍历，非递归，复杂度仅为 O(n)
void InOrderTraverse_Thr(ThreadBiTree T)
{
    pThrBiTNode pHead;  // 创建一个头节点
    pHead->pLChild = T;  // 头节点的左指针指向根节点
    
    while ( p != T ) {  // 空树或者遍历结束时，p == T
        // 首先要找到中序遍历的第一节点
        while ( p->lTag == LINK ) {  
            p = p->pLChild;
        }
        printf("%c ", p->data);  // 找到了第一个节点

        // 利用后继依次往后遍历
        while ( p->rTag == THREAD && p->pRChild != T ) {  // p有后继节点且后继节点非空
            p = p->pRChild;
            printf("%c ", p->data);
        }

        p = p->pRChild;  // p进至其右子树跟（未理解）
    }
}