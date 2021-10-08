/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/adairhu
 * @Date: 2021-10-07 01:43:50
 * @LastEditTime: 2021-10-08 19:28:19
 * @FilePath: \DaHua\Chapter6_Tree\main-sqtree.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include <stdlib.h>
#include "sqtree.h"

void PrintTree(ElemType e);

int main(void)
{
	bool i;
	Position p;
	ElemType e;
	SqBiTree T;
    
	InitBiTree(T);
	CreateBiTree(T);
	printf("建立二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", BiTreeIsEmpty(T), BiTreeDepth(T));

	i = Root(T, &e);
	if(i)
		printf("二叉树的根为：%d\n",e);
	else
		printf("树空，无根\n");

	printf("层序遍历二叉树:\n");
	LevelOrderTraverse(T, PrintTree);
	printf("\n");

	printf("前序遍历二叉树:\n");
	PreOrderTraverse(T, 0, PrintTree);
	printf("\n");

	printf("中序遍历二叉树:\n");
	InOrderTraverse(T, 0, PrintTree);
	printf("\n");

	printf("后序遍历二叉树:\n");
	PostOrderTraverse(T, 0, PrintTree);
	printf("\n");

	printf("修改结点的层号3本层序号2。");
	p.level=3;
	p.order=2;
	e = Value(T, p);
	printf("待修改结点的原值为%d请输入新值:50 ",e);
	e = 50;
	Assign(T, p, e);

	printf("前序遍历二叉树:\n");
	PreOrderTraverse(T, 0, PrintTree);

	printf("结点%d的双亲为%d,左右孩子分别为", e, Parent(T, e));

	printf("%d, %d,左右兄弟分别为", LeftChild(T, e),RightChild(T, e));

	printf("%d, %d\n", LeftSibling(T, e),RightSibling(T, e));

	ClearBiTree(T);
	printf("清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", BiTreeIsEmpty(T),BiTreeDepth(T));
	
	i = Root(T, &e);
	if(i)
		printf("二叉树的根为：%d\n",e);
	else
		printf("树空，无根\n");
	
	return 0;
}


void PrintTree(ElemType e)
{
	printf("%d ", e);
}