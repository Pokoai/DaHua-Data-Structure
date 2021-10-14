/*
 * @Description: 《大话数据结构》二叉树-顺序存储结构
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-09-28 14:35:56
 * @LastEditTime: 2021-10-14 18:37:10
 * @FilePath: \DaHua\Chapter6_Tree\sqtree.h
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#ifndef _SQTREE_H_
#define _SQTREE_H_ 

#include <stdbool.h>

#define MAX_TREE_SIZE 100 //二叉树的最大节点数

typedef int  ElemType; //定义存储数据类型

//构建顺序实现的二叉树数组，用来存放每个节点的数据
typedef ElemType SqBiTree[MAX_TREE_SIZE]; 

//节点位置
typedef struct {
    int level; //节点层
    int order; //本层中的序号
}Position;

//extern ElemType Nil; //在sqtree.c源文件中定义的

//初始化一个二叉树
void InitBiTree(SqBiTree T);

//创建二叉树（放入数据）
bool CreateBiTree(SqBiTree T);

//判空
bool BiTreeIsEmpty(SqBiTree T);

//获取二叉树的深度
int BiTreeDepth(SqBiTree T);

//节点赋值
//因为要符合完全二叉树的形式，所以赋值要特别小心，不是；每个节点都能被赋值的
bool Assign(SqBiTree T, Position p, ElemType value);

//获取根节点的值
bool Root(SqBiTree T, ElemType * e);

//返回节点位置为p的值 p(层，序号)
ElemType Value(SqBiTree T, Position p);

//获取节点位置p的双亲
ElemType Parent1(SqBiTree T, Position p);

//获取值为e的节点的双亲
ElemType Parent(SqBiTree T, ElemType e);

//获取某节点的左孩子
ElemType LeftChild(SqBiTree T, ElemType e);

//获取某节点的右孩子
ElemType RightChild(SqBiTree T, ElemType e);

//获取某节点的左兄弟
ElemType LeftSibling(SqBiTree T, ElemType e);

//获取某节点的右兄弟
ElemType RightSibling(SqBiTree T, ElemType e);

//清空二叉树
#define ClearBiTree InitBiTree

//前序遍历
/**
 * @description: 
 * @param {SqBiTree} T
 * @param {int} i 因为T是数组，非指针，所以要设置一个变量i充当它的指针，跟随遍历节点变化
 * @param {ElemType} e
 * @return {*}
 */
bool PreOrderTraverse(SqBiTree T, int i, void (*func)(ElemType e));

//中序遍历
bool InOrderTraverse(SqBiTree T, int i, void (*func)(ElemType e));

//后序遍历
bool PostOrderTraverse(SqBiTree T, int i, void (*func)(ElemType e));

//层序遍历
bool LevelOrderTraverse(SqBiTree T, void (*func)(ElemType e));

#endif