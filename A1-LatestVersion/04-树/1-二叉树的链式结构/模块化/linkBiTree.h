/*
 * 功能: 二叉树-二叉链表
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-09-19
 */

#ifndef _LINKBITREE_H_
#define _LINKBITREE_H_

#include <stdbool.h>

#define Nil '#'

/*------------------------- 二叉树链式结构定义 ------------------------*/

typedef char TElemType;

// 二叉链表节点
typedef struct biTNode {
    TElemType data;
    struct biTNode * pLChild;
    struct biTNode * pRChild;
} BiTNode, *pBiTNode;

// 定义二叉树结构
// 二叉树只要有一个头指针即可确定，与链表定义相同
typedef pBiTNode LinkBiTree;

/*------------------------- 二叉树链式结构定义 ------------------------*/



extern void InitBiTree(LinkBiTree * T);
extern void CreatBiTree(LinkBiTree * T);

extern void PreOrderTraverse(LinkBiTree T);
extern void InOrderTraverse(LinkBiTree T);                      // 递归
extern void InOrderTraverse_stack(LinkBiTree T);                // 借助栈
extern void PostOrderTraverse(LinkBiTree T);
extern void LevelOrderTraverse(LinkBiTree T);                   // 借助队列

extern bool BiTreeIsEmpty(LinkBiTree T);

extern TElemType Root(LinkBiTree T);
extern int BiTreeDepth(LinkBiTree T);
extern TElemType Value(pBiTNode p);
extern void Assign(pBiTNode p, TElemType elem);
extern pBiTNode Point(LinkBiTree T, TElemType elem);            // 借助队列
extern TElemType Parent(LinkBiTree T, TElemType elem);          // 借助队列
extern TElemType LeftChild(LinkBiTree T, TElemType elem);       // 借助 Point()
extern TElemType RightChild(LinkBiTree T, TElemType elem);      // 借助 Point()
extern TElemType LeftSibling(LinkBiTree T, TElemType elem);     // 借助 Parent() 和 Point
extern TElemType RightSibling(LinkBiTree T, TElemType elem);    // 借助 Point()

extern void DestoryBiTree(LinkBiTree T);


#endif