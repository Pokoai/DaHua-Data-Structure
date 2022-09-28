/*
 * @Description: 《大话数据结构》-线索二叉树
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-10-09 00:32:58
 * @LastEditTime: 2021-10-14 18:37:14
 * @FilePath: \DaHua\Chapter6_Tree\threadbitree.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include <stdlib.h>
#include "threadbitree.h"

//前序创建线索二叉树
bool CreateBiThrTree(BiThrTree * T)
{
    ElemType ch;

    scanf("%c", ch);

    if (ch == Nil) {
        *T = NULL;
    }
    else {
        *T = (BiThrTree)malloc(sizeof(BiThrNode));
        if (*T == NULL)
            return false;
        (*T)->data = ch;
        CreateBiThrTree(&(*T)->lchild);
        if ((*T)->lchild != NULL)
            (*T)->lTag = Link;
        CreateBiThrTree(&(*T)->rchild);
        if ((*T)->rchild != NULL)
            (*T)->rTag = Link;
    }

    return true;
}

// 中序遍历进行二叉树线索化
void InThreading(BiThrTree T) //T指向头结点
{
    static BiThrTree pre; //pre指向刚刚访问的结点

    if (T) {
        //递归左孩子
        InThreading(T->lchild);
        //更新前驱
        if (T->lchild == NULL) {
            T->lTag = Thread;
            T->lchild = pre;
        }
        //更新后继
        if (pre->rchild == NULL) {
            pre->rTag = Thread;
            pre->rchild = T;
        }
        pre = T;
        //递归右孩子
        InThreading(T->rchild);
    }
}

// 中序遍历线索二叉树（非递归方法）
bool InOrderTraverse_Thr(BiThrTree T, void (*func)(ElemType e))
{
    /*
    T指向头结点
    T->lchild 指向根节点
    中序遍历的最后一个结点的右指针指向头结点T
    */
   BiThrTree p = T->lchild; //p指向根结点

   while (p != T) { //空树或遍历结束时，p==T
       //1.找到中序遍历的第一个结点
       while (p->lTag == Link) {
           p = p->lchild;
       }
       //2.操作第一个结点
       (*func)(p->data);
       //3.按照后继指针依次操作各个结点,一旦右指针指向了右孩子，就会跳出循环
       while (p->rTag == Thread && p->rchild != T) {
           p = p->rchild;
           (*func)(p->data);
       }
       //上面的循环跳出后，更新p
       p = p->rchild;

   }
}

