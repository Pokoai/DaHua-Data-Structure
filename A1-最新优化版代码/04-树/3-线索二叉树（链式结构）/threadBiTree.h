#ifndef _THREADBITREE_H_
#define _THREADBITREE_H_

#include <stdbool.h>

#define Nil '#'

// 定义标志位类型，LINK: 指向孩子节点；THREAD: 指向前驱/后驱节点
typedef enum { LINK, THREAD } PointerTag;  

typedef char TElemType;

// 线索二叉树的节点类型
typedef struct thrBiTNode {
    TElemType data;
    struct thrBiTNode * pLChild;
    struct thrBiTNode * pRChild;
    PointerTag lTag, rTag;  // 指向孩子节点或者指向前驱/后驱节点 标志位
} ThrBiTNode, *pThrBiTNode;

typedef pThrBiTNode ThreadBiTree;  // 定义线索二叉树结构



extern void InitThrBiTree(ThreadBiTree *pT);
extern void CreateThrBiTree(ThreadBiTree *pT);
extern void InOrderTraverse(ThreadBiTree T);
extern void InThreading(ThreadBiTree T);
extern void InOrderTraverse_Thr(ThreadBiTree T);



#endif