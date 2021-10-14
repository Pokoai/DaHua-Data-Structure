/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-10-08 19:56:00
 * @LastEditTime: 2021-10-14 18:36:53
 * @FilePath: \DaHua\Chapter6_Tree\linkbitree.h
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#ifndef _LINKBITREE_H_
#define _LINKBITREE_H_

#include <stdbool.h>

typedef int ElemType;

//二叉树节点
typedef struct treeNode {
    ElemType data;
    struct treeNode *lchild, *rchild;
}TreeNode, *LinkBiTree;

//初始化一个二叉树
bool InitBiTree(LinkBiTree * T);

//创建二叉树，按前序顺序输入结点值
//#代表空
bool CreateBiTree(LinkBiTree * T);

//判空
bool BiTreeIsEmpty(LinkBiTree T);

//获取二叉树的深度，要理解该方法
int BiTreeDepth(LinkBiTree T);

//节点赋值
void Assign(LinkBiTree p, ElemType value);

//获取根节点的值
ElemType Root(LinkBiTree p);

//返回节点位置为p的值 p(层，序号)
ElemType Value(LinkBiTree p);

//清空二叉树
#define ClearBiTree InitBiTree

//前序遍历
bool PreOrderTraverse(LinkBiTree T, void (*func)(ElemType e));

//中序遍历
bool InOrderTraverse(LinkBiTree T, void (*func)(ElemType e));

//后序遍历
bool PostOrderTraverse(LinkBiTree T, void (*func)(ElemType e));

#endif
