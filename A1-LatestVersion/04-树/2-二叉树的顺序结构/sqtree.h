/*
 * 功能: 二叉树-顺序结构
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-09-28
 */


#ifndef _SQTREE_H_
#define _SQTREE_H_ 

#include <stdbool.h>


#define MAX_TREE_SIZE 100                    // 二叉树最大节点数
typedef int TElemType;                       
typedef TElemType SqBiTree[MAX_TREE_SIZE];   //构建顺序实现的二叉树数组

TElemType Nil = 0; // Nil表示空


//节点位置
typedef struct {
    int level;    //节点层
    int order;    //本层中的序号
} Position;




extern void InitBiTree(SqBiTree T);
extern bool CreateBiTree(SqBiTree T);
extern bool BiTreeIsEmpty(SqBiTree T);
extern int BiTreeDepth(SqBiTree T);

// 因为要符合完全二叉树的形式，所以赋值要特别小心，不是每个节点都能被赋值的
extern bool Assign(SqBiTree T, Position p, TElemType value);
extern bool Root(SqBiTree T, TElemType * e);
extern TElemType Value(SqBiTree T, Position p);    //返回节点位置为p的值 p(层，序号)

extern TElemType Parent1(SqBiTree T, Position p);  //获取节点位置p的双亲
extern TElemType Parent(SqBiTree T, TElemType e);   //获取值为e的节点的双亲
extern TElemType LeftChild(SqBiTree T, TElemType e);
extern TElemType RightChild(SqBiTree T, TElemType e);
extern TElemType LeftSibling(SqBiTree T, TElemType e);
extern TElemType RightSibling(SqBiTree T, TElemType e);

// 因为T是数组，非指针，所以要设置一个变量i充当它的指针，跟随遍历节点变化
extern bool PreOrderTraverse(SqBiTree T, int i, void (*func)(TElemType e));
extern bool InOrderTraverse(SqBiTree T, int i, void (*func)(TElemType e));
extern bool PostOrderTraverse(SqBiTree T, int i, void (*func)(TElemType e));
extern bool LevelOrderTraverse(SqBiTree T, void (*func)(TElemType e));

#define ClearBiTree InitBiTree



#endif