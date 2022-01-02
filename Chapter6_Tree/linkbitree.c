/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-10-08 19:55:09
 * @LastEditTime: 2021-11-02 10:32:44
 * @FilePath: \DaHua\Chapter6_Tree\linkbitree.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkbitree.h"

//存储二叉树结点值，代替手动输入
//char str[100] = "ABDH#K###E##CFI###G#J##";
char str[100] = "AB#D##C##";
int treeindex = 0;

ElemType Nil = 0;

//初始化一个二叉树
bool InitBiTree(LinkBiTree * T)
{
    /*
    //分配内存空间
    *T = (LinkBiTree)malloc(sizeof(TreeNode));
    if (*T == NULL)
        return false;
    
    (*T)->data = Nil;
    (*T)->lchild = NULL;
    (*T)->rchild = NULL;

    return true;
    */
   *T = NULL;
   
   return true;
}

//创建二叉树，按前序顺序输入结点值
//#代表空
bool CreateBiTree(LinkBiTree * T)
{
    char ch;

    //输入值
    //scanf("%c", ch);
    ch = str[treeindex++]; //用str代替输入
    //若空，直接赋NULL，不用分配空间
    if (ch == '#') {
        *T = NULL;
    }
    else {
        //先分配空间
        *T = (LinkBiTree)malloc(sizeof(TreeNode));
        if (*T == NULL)
            return false;
        //装入结点值
        (*T)->data = ch;
        //递归创建左、右子树
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }

    return true;
}

//判空
bool BiTreeIsEmpty(LinkBiTree T)
{
    if (!T)
        return true;
    else 
        return false;
}

//获取二叉树的深度，要理解该方法
int BiTreeDepth(LinkBiTree T)
{
    int i, j;

    if (!T)
        return 0;
    if (T->lchild)
        i = BiTreeDepth(T->lchild);
    else   
        i = 0;
    if (T->rchild)
        j = BiTreeDepth(T->rchild);
    else
        j = 0;
    
    return i>j ? i+1 : j+1;
}

//节点赋值
void Assign(LinkBiTree p, ElemType value)
{
    p->data = value;
}

//获取根节点的值
ElemType Root(LinkBiTree T)
{
    if (BiTreeIsEmpty(T))
        return Nil;
    else
        return T->data;
}

//p指向T中某个结点
ElemType Value(LinkBiTree p)
{
    return p->data;
}

//清空二叉树
#define ClearBiTree InitBiTree

//前序遍历
bool PreOrderTraverse(LinkBiTree T, void (*func)(ElemType e))
{
    if (T == NULL)
        return false;
    (*func)(T->data);
    PreOrderTraverse(T->lchild, func);
    PreOrderTraverse(T->rchild, func);
}

//中序遍历
bool InOrderTraverse(LinkBiTree T, void (*func)(ElemType e))
{
    if (T == NULL)
        return false;
    PreOrderTraverse(T->lchild, func);
    (*func)(T->data);
    PreOrderTraverse(T->rchild, func);
}

//后序遍历
bool PostOrderTraverse(LinkBiTree T, void (*func)(ElemType e))
{
    if (T == NULL)
        return;
    PreOrderTraverse(T->lchild, func);
    PreOrderTraverse(T->rchild, func);
    (*func)(T->data);    
}