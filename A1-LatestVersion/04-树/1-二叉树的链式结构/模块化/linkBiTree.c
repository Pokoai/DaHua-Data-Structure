/*
 * 功能: 二叉树-二叉链表
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-09-19
 */


// 注意：非递归方式遍历尚未实现，后续补充


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linkBiTree.h"
#include "linkQueue.h"


// 初始化
// 会改变头指针的值，故采用 *pT
void InitBiTree(LinkBiTree * pT)
{
    // 构造空二叉树
    *pT = NULL;
}

// 创建二叉树
void CreatBiTree(LinkBiTree * pT)  // pT实际上是二级指针，指向根节点的指针的指针
{
    TElemType ch;
    
    scanf("%c", &ch);
    if ( Nil == ch ) {  //节点值为空
        *pT = NULL;  // *pT是指向根节点的指针
    } 
    else {  // 节点值不为空，创建根节点
       *pT = (pBiTNode)malloc(sizeof(BiTNode));
        if ( NULL == *pT ) {
            printf("内存分配失败！");
            exit(-1);
        }

        (*pT)->data = ch;
        // CreatBiTree((*pT)->pLChild);  // 这里错了！  (*pT)->pLChild仅为一级指针，而非二级指针
        // CreatBiTree((*pT)->pRChild);

        CreatBiTree(&(*pT)->pLChild);  // 要加一个取地址符&，即变为指向左子树根节点的指针的指针，二级指针
        CreatBiTree(&(*pT)->pRChild);
    }
}

// 前序遍历二叉树
// 递归实现
void PreOrderTraverse(LinkBiTree T)
{
    if ( T != NULL ) {
        printf("%c ", T->data);
        PreOrderTraverse(T->pLChild);
        PreOrderTraverse(T->pRChild);
    }
}

// 中序遍历二叉树
void InOrderTraverse(LinkBiTree T)
{
    if ( T != NULL ) {
        InOrderTraverse(T->pLChild);
        printf("%c ", T->data);
        InOrderTraverse(T->pRChild);
    }
}

// 中序遍历
// 非递归算法，利用栈实现
void InOrderTraverse_stack(LinkBiTree T)
{

}

// 后序遍历二叉树
void PostOrderTraverse(LinkBiTree T)
{
    if ( T != NULL ) {
        PostOrderTraverse(T->pLChild);
        PostOrderTraverse(T->pRChild);
        printf("%c ", T->data);
    }
}

// 层序遍历
// 借助队列实现
void LevelOrderTraverse(LinkBiTree T)
{
    LinkQueue q;
    QElemType a;

    if ( T != NULL ) {
        InitQueue(&q);  // 容易忘记初始化
        EnQueue(&q, T);
        while ( !QueueIsEmpty(&q) ) {
            DeQueue(&q, &a);               // 出队
            printf("%c ", a->data);

            if ( a->pLChild ) {
                EnQueue(&q, a->pLChild);  // 左孩子入队
            }
            if ( a->pRChild ) {
                EnQueue(&q, a->pRChild);  // 右孩子入队
            }
        }
        printf("\n");
        DestoryQueue(&q);  // 记得释放队列内存
    }
}

// 是否为空
bool BiTreeIsEmpty(LinkBiTree T)
{
    return (NULL == T);
}

// 获取根节点
TElemType Root(LinkBiTree T)
{
    if ( BiTreeIsEmpty(T) ) {
        return Nil;
    }
    else {
        return T->data;
    }
}

// 树深度
// 递归求得，好好思考一番
int BiTreeDepth(LinkBiTree T)
{
    int i, j;

    if ( NULL == T ) {
        return 0;
    }
    else {
        i = BiTreeDepth(T->pLChild);
        j = BiTreeDepth(T->pRChild);
        return i>j ? i+1 : j+1;
    }
} 

// 返回二叉树中元素值为 elem 的节点的指针
// 这个函数特别重要，后面的找孩子节点、找兄弟节点等功能都要基于该函数
// 遍历方法实现
// pBiTNode Point(LinkBiTree T, TElemType elem)
// {
//     if ( T != NULL ) {
//         if ( elem == T->data ) {
//             return T;
//         }

//         Point(T->pLChild, elem);  // 有问题，在这个递归里找到 elem 了，但是仍然会继续执行下面的 Point(T->pRChild, elem); 无法及时结束递归
//         Point(T->pRChild, elem);
//     }
// }   


// 返回二叉树中元素值为 elem 的节点的指针
// 递归问题无法解决的话，或者借助队列实现该函数，但是将自己编写的链式队列融合进来又是一个问题
pBiTNode Point(LinkBiTree T, TElemType elem)
{
    LinkQueue q;
    QElemType a;  // typedef pBiTreeNode QElemType;  已经将二叉树的节点指针作为队列元素

    if ( T != NULL ) {
        InitQueue(&q);   // 初始化队列，为头节点分配内存空间
        EnQueue(&q, T);  // 将根节点入队
        while ( !QueueIsEmpty(&q) ) {  
            DeQueue(&q, &a);  // 只要队列非空，则出队
            if ( elem == a->data ) {  
                DestoryQueue(&q);  // 结束函数前将队列内存释放，否则会造成内存泄漏
                return a;  // 找到了 elem，则返回指向其节点的指针，结束函数
            }
            else {   // 如果在根节点未找到，则继续将左右孩子节点入队
                if ( a->pLChild != NULL ) {  // 左孩子非空，入队
                    EnQueue(&q, a->pLChild);
                }
                if ( a->pRChild != NULL ) {  // 右孩子非空，入队
                    EnQueue(&q, a->pRChild);
                }
            }
            
        }
        // while() 中未找到 elem，表明二叉树中没有要找的元素
        // 那么要将队列的头节点所占空间释放掉
        DestoryQueue(&q);
    } 

    return NULL;  // 若 T 为空，则返回 NULL；或者 T 非空但是在 T 树中未找到 elem，则返回 NULL 
}


// 返回指针 p 所指向的节点的值
TElemType Value(pBiTNode p)
{
    if ( p != NULL ) {
        return p->data;
    }
    else {
        return Nil;
    }
}

// 给 p 所指向的节点赋值
void Assign(pBiTNode p, TElemType elem)
{
    if ( p != NULL ) {
        p->data = elem;
    }
    else {
        printf("节点为空，赋值失败！\n");
    }
}

// 找父节点
// 类似 Point()，只是 Parent() 返回的是其父节点的 data
TElemType Parent(LinkBiTree T, TElemType elem)
{
    LinkQueue q;
    QElemType a;

    if ( T != NULL ) {
        InitQueue(&q);
        EnQueue(&q, T);
        while ( !QueueIsEmpty(&q) ) {
            DeQueue(&q, &a);
            // if ( a->pLChild->data == elem || a->pRChild->data == elem ) {  // 这里要注意，少了左右孩子空判断
            if ( a->pLChild && a->pLChild->data == elem || a->pRChild && a->pRChild->data == elem ) {
                DestoryQueue(&q);
                return a->data;
            }
            else {
                if ( a->pLChild != NULL ) {
                    EnQueue(&q, a->pLChild);
                }
                if ( a->pRChild != NULL ) {
                    EnQueue(&q, a->pRChild);
                }
            }
        }
        DestoryQueue(&q);
    }
    return Nil;
}

// 找左孩子
// 借助 Point
TElemType LeftChild(LinkBiTree T, TElemType elem)
{
    if ( T != NULL ) {
        pBiTNode p = Point(T, elem);  // 首先找到指向该节点的指针
        if ( p != NULL && p->pLChild != NULL ) {   
            return p->pLChild->data;
        }
    }
    return Nil;
}

// 找右孩子
TElemType RightChild(LinkBiTree T, TElemType elem)
{
    if ( T != NULL ) {
        pBiTNode p = Point(T, elem);
        if ( p != NULL && p->pRChild != NULL ) {
            return p->pRChild->data;
        }
    }
    return Nil;
}

// 找左兄弟
// 借助 Parent
TElemType LeftSibling(LinkBiTree T, TElemType elem)
{
    if ( T != NULL ) {
        TElemType a = Parent(T, elem);  // 找到其父节点
        if ( a != Nil ) {  
            pBiTNode p = Point(T, a);   // 再找到父节点的指针
            if ( p->pLChild != NULL && p->pRChild != NULL && p->pRChild->data == elem) {  // 假设左右孩子的值均不相同
                return p->pLChild->data;
            }
        }
    }
    return Nil;
}

// 找右兄弟
TElemType RightSibling(LinkBiTree T, TElemType elem)
{
    if ( T != NULL ) {
        TElemType a = Parent(T, elem);
        if ( a != Nil ) {
            pBiTNode p = Point(T, a);
            if ( p->pLChild != NULL && p->pRChild != NULL && p->pLChild->data == elem) {
                return p->pRChild->data;
            }
        }
    }
    return Nil;
}

// 销毁
void DestoryBiTree(LinkBiTree T)
{
    if ( T != NULL ) {
        DestoryBiTree(T->pLChild);
        DestoryBiTree(T->pRChild);
        free(T);
        T = NULL;
    }
}