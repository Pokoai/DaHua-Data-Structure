/*
 * @Description: 《大话数据结构》- 线索二叉树
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/adairhu
 * @Date: 2021-10-09 00:33:51
 * @LastEditTime: 2021-10-09 02:11:44
 * @FilePath: \DaHua\Chapter6_Tree\threadbitree.h
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#ifndef _THREADBITREE_H_
#define _THREADBITREE_H_

#include <stdbool.h>

typedef char ElemType;
ElemType Nil = '#'; //字符'#'表示空

//Link:指向孩子的指针   Thread:指向前驱或后继的指针
typedef enum {Link, Thread} PointerTag;

//线索二叉树的节点结构
typedef struct biThrNode {
    ElemType data;
    struct biThrNode *lchild, *rchild;
    PointerTag lTag, rTag;
}BiThrNode, *BiThrTree;

//前序创建线索二叉树
bool CreateBiThrTree(BiThrTree * T);

//中序遍历进行二叉树线索化
void InThreading(BiThrTree T);

//中序遍历线索二叉树（非递归方法）
bool InOrderTraverse_Thr(BiThrTree T, void (*func)(ElemType e));

#endif