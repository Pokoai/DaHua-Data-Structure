/*
 * 功能: 动态查找-二叉排序树
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-10-11
 */

#include <stdio.h>
#include <stdbool.h>

// --------------定义二叉树结构-------------
typedef int ElemType;

typedef struct biTNode {
    ElemType data;
    struct biTNode * pLChild;
    struct biTNode * pRChild;
} BiTNode, *pBiTNode;

typedef pBiTNode BiTree;
// --------------定义二叉树结构-------------


// 二叉排序树搜索
// T：要检索的二叉树
// key：关键字
// p：若找到则返回指向关键字所在节点的指针，若查找失败则返回查找路径上最后访问的节点指针
// parent：parent指向T的父节点，一开始T指向根节点，则f的初值为NULL，递归程序中修改。该参数主要用于插入程序中
bool BiSortTree_Search(BiTree T, int key, pBiTNode * p, pBiTNode parent)
{
    // T == NULL 有两层含义，一是T树为空，二是递归到最后一个分支为空；总之都是未找到key 
    if ( NULL == T ) {  // 递归到最后一个分支为空，查找失败
        *p = parent;    // 将空分支的父节点保存起来，后续插入时需要用到
        return false;   // 查找失败，返回false
    }
    else {
        if ( key == T->data ) {  // 找到了key
            *p = T;
            return true;
        }
        else if ( key < T->data ) {  // key小于T节点，则继续在T左子树中查找
            return BiSortTree_Search(T->pLChild, key, p, T);  // 注意这里的parent参数更改为了T
        }
        else {  // key大于T节点，则继续在T右子树中查找
            return BiSortTree_Search(T->pRChild, key, p, T);
        }
    }
    
}

// 二叉排序树的插入
bool BiSortTree_Insert(BiTree *T, int key)
{
    pBiTNode p;  // 存储查找到的位置

    // parent指向T的父节点，一开始T指向根节点，则f的初值为NULL
    if ( !BiSortTree_Search(*T, key, &p, NULL) ) {  // 未找到，需要插入新值
        // 1.为新节点分配内存空间并初始化
        pBiTNode pNew = (pBiTNode)malloc(sizeof(BiTNode));
        if ( NULL == pNew ) {
            printf("内存分配失败！\n");
            return false;
        }
        pNew->data = key;
        pNew->pLChild = pNew->pRChild = NULL;

        // 2.若T是空树（即p为NULL），则pNew作为根节点
        if ( p == NULL ) {
            *T = pNew;  // 这里修改了T，故函数形参应该使用BiTree *T
        }
        else {  // 3.T非空，则p指向最后访问的一个父节点
            if ( key < p->data ) {  
                p->pLChild = pNew;  // 将pNew节点插入到p节点左子树
            }
            else {
                p->pRChild = pNew;  // 将pNew节点插入到p节点右子树
            }
        }
        return true;
    } 
    return false;  // 找到了，就不用插入了，返回false即可
} 

// 二叉排序树的删除
bool BiSortTree_Delete(BiTree * T, int key)
{
    if ( NULL == *T ) {
        return false;
    }
    else {
        if ( key == (*T)->data ) {
            return Delete(T);  // 除了这一句与二叉树的查找不同外，其他均相似
        }
        else if ( key < (*T)->data ) {
            return BiSortTree_Delete(&(*T)->pLChild, key);
        }
        else {
            return BiSortTree_Delete(&(*T)->pRChild, key);
        }
    }
}

// 删除某个节点
static bool Delete(pBiTNode *p)
{
    pBiTNode q;
    // 若该节点的左子树为空，则重接其右子树，将指针改为指向其右子树即可
    if ( NULL == (*p)->pLChild ) {
        q = *p;  // 最后要释放 *p，但是中间又会修改 *p，那么就将原始的 *p 用临时变量 q 保存下来
        *p = (*p)->pRChild;
        free(q);
    }
    else if ( NULL == (*p)->pRChild ) {  // 右子树为空，重接左子树
        q = *p;
        *p = (*p)->pLChild;
        free(q);
    }
    else {  // 左右子树均非空
        q = *p;
        pBiTNode s = (*p)->pLChild;  // q是s的父节点
        while ( s->pRChild ) {  // 一直向右到头
            q = s;
            s = s->pRChild;
        }
        (*p)->data = s->data;  // 要删除的节点用前驱节点的值替换
        if ( q == *p ) {  // while ( s->pRChild )走来就跳出循环了，即*p的左子树没有右分支
            q->pLChild = s->pLChild; 
        }
        else {
            q->pRChild = s->pLChild;
        }
        free(s);  
    }
    return true;
}