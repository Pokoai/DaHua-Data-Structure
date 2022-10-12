/*
 * 功能: 队列-链式结构
 * 作者: Guyue
 * 微信公众号(破壳Ai): https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-09-16
 */

#include <stdio.h>

#include "linkBiTree.h"


int main(void)
{
    LinkBiTree T;

    InitBiTree(&T);

    printf("请按前序输入二叉树（如：abdg###e##c#f##，a 为根节点，b 为左子树，# 为空节点）：\n");  // abdg###e##c#f##
    CreatBiTree(&T);
    while ( getchar() != '\n');  // 消除回车字符

    printf("前序遍历二叉树：");
    PreOrderTraverse(T);
    printf("\n");

    printf("中序遍历二叉树：");
    InOrderTraverse(T);
    printf("\n");

    printf("后序遍历二叉树：");
    PostOrderTraverse(T);
    printf("\n");

    printf("层序遍历二叉树：");
    LevelOrderTraverse(T);
    
    printf("二叉树的根为：%c\n", Root(T));

    printf("二叉树的深度为：%d\n", BiTreeDepth(T));

    TElemType e;
    printf("请输入一个节点的值：");
    scanf("%c", &e);
    while ( getchar() != '\n');  // 消除回车字符
    printf("节点的值为 %c\n", e);

    pBiTNode p = Point(T, e);
    printf("指向该节点的指针是：%p\n", p);
    printf("该指针所指节点的值是：%c\n", Value(p));
    printf("该节点的父节点值是：%c\n", Parent(T, e));
    printf("该节点的左孩子值是：%c\n", LeftChild(T, e));
    printf("该节点的右孩子值是：%c\n", RightChild(T, e));
    printf("该节点的左兄弟值是：%c\n", LeftSibling(T, e));
    printf("该节点的右兄弟值是：%c\n", RightSibling(T, e));

    printf("欲改变此节点的值，请输入新值：");
    scanf("%c", &e);
    while ( getchar() != '\n');  // 消除回车字符
    Assign(p, e);

    printf("前序遍历二叉树：");
    PreOrderTraverse(T);
    printf("\n");

    return 0;
}

