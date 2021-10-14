/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-10-08 22:02:51
 * @LastEditTime: 2021-10-14 18:36:57
 * @FilePath: \DaHua\Chapter6_Tree\main-linktree.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */
#include <stdio.h>
#include "linkbitree.h"

void PrintTree(ElemType e);

int main(void)
{
	int i;
	LinkBiTree T;
	ElemType e1;
	
	InitBiTree(&T);
	CreateBiTree(&T);

	printf("构造空二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", BiTreeIsEmpty(T), BiTreeDepth(T));

	e1 = Root(T);
    printf("二叉树的根为: %c\n",e1);
    printf("\n");

	printf("\n前序遍历二叉树:");
	PreOrderTraverse(T, PrintTree);
    printf("\n");

	printf("\n中序遍历二叉树:");
	InOrderTraverse(T, PrintTree);
    printf("\n");

	printf("\n后序遍历二叉树:");
	PostOrderTraverse(T, PrintTree);
    printf("\n");
    
	ClearBiTree(&T);
	printf("\n清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", BiTreeIsEmpty(T), BiTreeDepth(T));

	i = Root(T);
	if(!i)
		printf("树空，无根\n");
	
	return 0;
}

void PrintTree(ElemType e)
{
	printf("%c ", e);
}