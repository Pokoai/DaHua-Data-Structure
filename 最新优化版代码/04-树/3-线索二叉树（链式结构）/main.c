#include <stdio.h>

#include "threadBiTree.h"


int main(void)
{
    ThreadBiTree T;

    InitThrBiTree(&T);

    printf("请按前序输入二叉树（如：abdg###e##c#f##，a 为根节点，b 为左子树，# 为空节点）：\n");  // abdg###e##c#f##
    CreateThrBiTree(&T);

    printf("中序遍历二叉树：");
    InOrderTraverse(T);
    printf("\n");

    printf("中序线索化二叉树！\n");
    InThreading(T);

    printf("中序遍历二叉树（非递归）：");
    InOrderTraverse_Thr(T);
    
    return 0;
}