
#ifndef _LINKBITREE_H_
#define _LINKBITREE_H_

#include <stdbool.h>


typedef char TElemType;

#define Nil '#'

// 二叉链表节点
typedef struct biTNode {
    TElemType data;
    struct biTNode * pLChild;
    struct biTNode * pRChild;
} BiTNode, *pBiTNode;

// 定义二叉树结构
// 二叉树只要有一个头指针即可确定，与链表定义相同
typedef pBiTNode LinkBiTree;



extern void InitBiTree(LinkBiTree * T);
extern void CreatBiTree(LinkBiTree * T);
extern void PreOrderTraverse(LinkBiTree T);
extern void InOrderTraverse(LinkBiTree T);
extern void PostOrderTraverse(LinkBiTree T);
extern void LevelOrderTraverse(LinkBiTree T);
extern bool BiTreeIsEmpty(LinkBiTree T);
extern TElemType Root(LinkBiTree T);
extern int BiTreeDepth(LinkBiTree T);
extern pBiTNode Point(LinkBiTree T, TElemType elem);
extern TElemType Value(pBiTNode p);
extern void Assign(pBiTNode p, TElemType elem);
extern TElemType Parent(LinkBiTree T, TElemType elem);
extern TElemType LeftChild(LinkBiTree T, TElemType elem);
extern TElemType RightChild(LinkBiTree T, TElemType elem);
extern TElemType LeftSibling(LinkBiTree T, TElemType elem);
extern TElemType RightSibling(LinkBiTree T, TElemType elem);
extern void DestoryBiTree(LinkBiTree T);



#endif