/*
 * 功能: 二叉树-二叉链表
 * 作者: Guyue
 * 微信公众号(破壳Ai): https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-09-19
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char TElemType;

#define Nil '#'

// 二叉链表节点
typedef struct biTNode {
    TElemType data;
    struct biTNode * pLChild;
    struct biTNode * pRChild;
} BiTNode, *pBiTNode;

// 定义二叉树结构
// 二叉树只要有一个头指针即可确定，与链表定义相同
typedef pBiTNode LinkBiTree;



void InitBiTree(LinkBiTree * T);
void CreatBiTree(LinkBiTree * T);
void PreOrderTraverse(LinkBiTree T);
void InOrderTraverse(LinkBiTree T);
void PostOrderTraverse(LinkBiTree T);
TElemType Root(LinkBiTree T);
int BiTreeDepth(LinkBiTree T);
pBiTNode Point(LinkBiTree T, TElemType elem);
TElemType Value(pBiTNode p);
void Assign(pBiTNode p, TElemType elem);


int main(void)
{
    LinkBiTree T;

    InitBiTree(&T);

    printf("请按前序输入二叉树（如：ab###，表示 a 为根节点，b 为左子树）：\n");  // abdg###e##c#f##
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
    printf("二叉树的根为：%c\n", Root(T));

    printf("二叉树的深度为：%d\n", BiTreeDepth(T));

    TElemType e;
    printf("请输入一个节点的值：");
    scanf("%c", &e);
    printf("节点的值为 %c\n", e);

    // pBiTNode p = Point(T, e);
    // printf("指向该节点的指针是：%p\n", p);
    // printf("该指针所指节点的值是：%c\n", p->data);

    return 0;
}

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

// 后序遍历二叉树
void PostOrderTraverse(LinkBiTree T)
{
    if ( T != NULL ) {
        PostOrderTraverse(T->pLChild);
        PostOrderTraverse(T->pRChild);
        printf("%c ", T->data);
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


// 递归问题无法解决的话，或者借助队列实现该函数，但是将自己编写的链式队列融合进来使用又是一个问题
// 返回二叉树中元素值为 elem 的节点的指针
pBiTNode Point(LinkBiTree T, TElemType elem)
{

}


// 返回指针p所指向的节点的值
TElemType Value(pBiTNode p)
{
    return p->data;
}

// 给p所指向的节点赋值
void Assign(pBiTNode p, TElemType elem)
{
    p->data = elem;
}

// 找父节点

// 找左孩子

// 找右孩子

// 找左兄弟

// 找右兄弟

// 销毁

// 清空







