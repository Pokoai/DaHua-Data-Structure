/*
 * @Description: 《大话数据结构》第八章-二叉排序树
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-11-02 20:56:46
 * @FilePath: \DaHua\Chapter8_Search\02BiSortTree.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//数据类型
typedef int ElemType;

//二叉树结点
typedef struct biTreeNode {
    ElemType data;
    struct biTreeNode *lchild, *rchild;
}BiTreeNode;

typedef BiTreeNode * BiTree; //二叉树构建完成


//查找
/**
 * @description: 
 * @param {BiTree} T: 树T
 * @param {ElemType} key: 待查找的元素
 * @param {BiTree} parent：存储树（子树）的父节点
 * @param {BiTree *} p：找的位置
 * @return {*}
 */
bool SearchBST(BiTree T, ElemType key, BiTree parent, BiTree * p)
{
    //树为空，则查找结束，跳出递归
    if (!T) {
        *p = parent;  //parent存储了访问路径上最后访问的一个结点
        return false;
    }
    //找到了
    else if (key == T->data) {
        *p = T;
        return true;
    }
    else if (key < T->data) {
        return SearchBST(T->lchild, key, T, p);
    }
    else {
        return SearchBST(T->rchild, key, T, p);
    }
}


//插入
bool InsertBST(BiTree * T, ElemType key)
{
    BiTree p, new;

    //先查找是否已存在key
    if (!SearchBST(*T, key, NULL, &p)) { //没有找到
        //p已经存储了最后访问的那个结点，将key作为其子节点即可
        //1.分配内存空间
        new = (BiTree)malloc(sizeof(BiTreeNode));
        if (!new)
            return false;
        //2.新结点赋值
        new->data = key;
        new->lchild = NULL;
        new->rchild = NULL;
        //3.若树为空，那么p为NULL
        if (!p)
            *T = new; //树为空，插入第一个结点的情况 这句容易忘记，谨记
        //4.树非空时插入
        else if (key < p->data)
            p->lchild = new;
        else 
            p->rchild = new;
        
        return true;
    }
    else
        return false;

}


//删
bool DeleteBST(BiTree * T, ElemType key)
{
    //1.既是判空也是递归没有找到key，作为结束递归的条件
    if (!(*T))
        return false;
    //2.找到key,删除结点T并返回true
    if (key == (*T)->data)
        // Delete(T); //传入指向待删除结点T的指针
        // return true; 
        return Delete(T); //将上面两句和为一句，这样Delete函数也可以有返回值
    //3.该节点的值非key，要分为两种情况去递归
    else if (key < (*T)->data)
        return DeleteBST(&(*T)->lchild, key);
    else
        return DeleteBST(&(*T)->rchild, key);
}

//DeleteBST的辅助函数，删除结点p
//1.若p只有左或右子树，那么只需释放该结点，并将其单个子树移到它的位置即可
//2.若p有左右子树，那么不能释放p，只是替换掉p的data域而已。
//用前驱或后继的data来替换，那么需要释放前驱或后继结点，释放前要考虑是如何安排其子树
bool Delete(BiTree * p)
{
    BiTree f, s; //f为前驱，s为前驱父节点

    //1.先处理简单的情况，只有单子树
    if (!(*p)->lchild)  { //无左树
        s = *p;
        *p = (*p)->rchild;
        free(s);
        // return true;
    }
    else if (!(*p)->rchild) { //无右树
        s = *p;
        *p = (*p)->lchild;
        free(s);
        // return true;
    }
    //2.左右树均存在
    else 
        {
            //前驱存在两种情况：1.p左子树根节点无右子树时，正好就是左子树根节点本身
            //2.p左子树根节点有右子树时，需要一直找到右边的最末端，即右边的最大值
            f = (*p)->lchild; //转到左子树
            s = *p; //s为前驱f的父节点
            while (f->rchild) {
                s = f; //s存储前驱结点的父节点，为了后面拿走前驱后调整其子树
                f = f->rchild;
            }
            //不管何种情况，先把p的data域替换掉，p仍保留不用释放
            (*p)->data = f->data;
            //接下来就是考虑f的子树情况
            if (s == *p) //未进入循环，说明f无右子树
                s->lchild = f->lchild;
            else //进入循环,说明f有右子树
                s->rchild = f->lchild;
            //释放f
            free(f);
            // return true;
        }
        return true; //在这里统一return，一句代替上面三句
}