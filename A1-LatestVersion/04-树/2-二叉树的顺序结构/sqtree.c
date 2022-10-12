/*
 * 功能: 二叉树-顺序结构
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-09-28
 */

#include <stdio.h>
#include <math.h>

#include "sqtree.h"


// 初始化
// 构造空二叉树
void InitBiTree(SqBiTree T)
{
    for ( int i = 0; i < MAX_TREE_SIZE; i++ ) {
        T[i] = Nil;
    }
}

// 创建二叉树
// 按层序次序输入二叉树中结点的值
bool CreateBiTree(SqBiTree T)
{
    // 人为构造一些值放入数组中，其中前10个值为 1-10，后续空间存入空值
    // printf("按层序输入结点的值(整型),0表示空结点, 输入999结束.结点数<=%d\n",MAX_TREE_SIZE);
    /*
     1        -->1
     2     3    -->2
     4  5  6  7   -->3
     8  9 10        -->4

     1 2 3 4 5 6 7 8 9 10 Nil Nil Nil

     */
    int i = 0;

    while ( i < 10 ) {
        T[i] = i + 1;
        printf("%d ", T[i]); //打印出节点的数据

        //节点非空非根节点，且无双亲节点异常处理
        if ( i != 0 && T[i] != Nil && T[(i+1)/2-1] == Nil ) {
            printf("出现无双亲的非根节点%d\n", T[i]);
            return false;
        }
        i++;
    }
    while ( i++ < MAX_TREE_SIZE ) {
        T[i] = Nil;
    }
    return true;
}


// 是否为空
bool BiTreeIsEmpty(SqBiTree T)
{
    return (Nil == T[0]);
}

// 获取二叉树的深度
int BiTreeDepth(SqBiTree T)
{
    int d;  // 深度变量
    int i;  // 存储最后一个非空元素的位置

    // 首先找到最后一个非空节点的下标值
    for ( i = MAX_TREE_SIZE - 1; i >= 0; i-- ) {
        if ( T[i] != Nil )
            break;
    } //找到了

    //根据下标值取计算深度
    d = 0;
    while ( pow(2, d) <= i )
        d++;

    return d;
}

// 节点赋值
// 因为要符合完全二叉树的形式，所以赋值要特别小心，不是；每个节点都能被赋值的
bool Assign(SqBiTree T, Position p, TElemType value)
{
    /*
    赋值前要做异常处理，有两种异常情况
    1.赋值非空时，空节点的子节点是不能被赋值的
    2.赋值为空时，有非空子节点的节点是不能被赋值的
    */
    int i = (int)powl(2, p.level-1) + p.order - 2;

    //1.赋值非空时，空节点的子节点是不能被赋值的，除去头节点外
    if (value != Nil && T[(i+1)/2] == Nil && i != 0)
        return false;
    //2.赋值为空时，有非空子节点的节点是不能被赋值的
    if (value == Nil && T[2*i+1] != Nil || T[2*i+2] != Nil)
        return false;
    
    T[i] = value;

    return true;
}

//获取根节点的值
bool Root(SqBiTree T, TElemType * e)
{
    //空异常
    if (BiTreeIsEmpty(T))  
        return false;
    
    *e = T[0];

    return true;
}

//返回节点位置为p的值 p(层，序号)
TElemType Value(SqBiTree T, Position p)
{
    int i; //数组下标

    i = (int)powl(2, p.level-1) + p.order - 2;
    //为何减2：1.数组下标从0开始而非1，故减1； 2.序号从1开始而非1，故减1；加起来就要减2

    return T[i];
}


//获取节点位置p的双亲
TElemType Parent1(SqBiTree T, Position p)
{
    int i = (int)powl(2, p.level-1) + p.order - 2;

    //判空
    if (BiTreeIsEmpty(T))
        return false;
    //头节点
    if (!i)
        return false;
    
    return T[(i-1)/2];
}

//获取值为e的节点的双亲
TElemType Parent(SqBiTree T, TElemType e)
{
    //判空
    if (BiTreeIsEmpty(T))
        return Nil;
    
    for (int i = 0; i < MAX_TREE_SIZE; i++)
    {   //先找到节点e
        if (T[i] == e) 
            return T[(i-2)/2];
    }

    return Nil;
}

//获取某节点的左孩子
TElemType LeftChild(SqBiTree T, TElemType e)
{
    //判空
    if (BiTreeIsEmpty(T))
        return Nil;
    
    for (int i = 0; i < MAX_TREE_SIZE - 1; i++) //e肯定不是最后一个节点
    {   //先找到节点e
        if (T[i] == e) 
            return T[2*i+1];
    }

    return Nil; //未找到
}

//获取某节点的右孩子
TElemType RightChild(SqBiTree T, TElemType e)
{
    //判空
    if (BiTreeIsEmpty(T))
        return Nil;
    
    for (int i = 0; i < MAX_TREE_SIZE - 1; i++) //e肯定不是最后一个节点
    {   //先找到节点e
        if (T[i] == e) 
            return T[2*i+2];
    }

    return Nil; //未找到
}

//获取某节点的左兄弟
TElemType LeftSibling(SqBiTree T, TElemType e)
{
    //判空
    if (BiTreeIsEmpty(T))
        return Nil;
    
    for (int i = 0; i < MAX_TREE_SIZE; i++) 
    {   //先找到节点e，并且它是右兄弟（下标为偶数）
        if (T[i] == e && e%2 == 0) 
            return T[i-1];
    }

    return Nil; //未找到
}

//获取某节点的右兄弟
TElemType RightSibling(SqBiTree T, TElemType e)
{
    //判空
    if (BiTreeIsEmpty(T))
        return Nil;
    
    for (int i = 0; i < MAX_TREE_SIZE - 1; i++) //e肯定不是最后一个节点
    {   //先找到节点e，且它是左兄弟（下标为奇数）
        if (T[i] == e && e%2 == 1) 
            return T[i+1];
    }

    return Nil; //未找到
}

//前序遍历
/**
 * @description: 
 * @param {SqBiTree} T
 * @param {int} i 因为T是数组，非指针，所以要设置一个变量i充当它的指针，跟随遍历节点变化
 * @param {TElemType} e
 * @return {*}
 */
bool PreOrderTraverse(SqBiTree T, int i, void (*func)(TElemType e))
{
    //i = 0; //i的初始值是在main函数中传进入的，不能在该函数里赋值，否则递归调用每次都会将i赋值为0

    //首先判空异常处理，只有第一次进入函数才需要判空
    if (i == 0) {
        if (BiTreeIsEmpty(T))
            return false;
    }
    //对母节点执行操作
     (*func)(T[i]);
    //左子树非空
    if (T[2*i+1] != Nil) {
        PreOrderTraverse(T, 2*i+1, func);
    }
    //右子树非空
    if (T[2*i+2] != Nil) {
        PreOrderTraverse(T, 2*i+2, func);
    }

    return true;
}

//中序遍历
bool InOrderTraverse(SqBiTree T, int i, void (*func)(TElemType e))
{
    //i = 0;

    if (i == 0) {
        if (BiTreeIsEmpty(T))
            return false;
    }
    //左子树非空
    if (T[2*i+1] != Nil) {
        InOrderTraverse(T, 2*i+1, func);
    }
    //对母节点执行操作
    (*func)(T[i]);
    //右子树非空
    if (T[2*i+2] != Nil) {
        InOrderTraverse(T, 2*i+2, func);
    }

    return true;
}

//后序遍历
bool PostOrderTraverse(SqBiTree T, int i, void (*func)(TElemType e))
{
    //i = 0;

    if (i == 0) {
        if (BiTreeIsEmpty(T))
            return false;
    }
    //左子树非空
    if (T[2*i+1] != Nil) {
        PostOrderTraverse(T, 2*i+1, func);
    }
    //右子树非空
    if (T[2*i+2] != Nil) {
        PostOrderTraverse(T, 2*i+2, func);
    }
    //对母节点执行操作
    (*func)(T[i]);

    return true;
}

//层序遍历
bool LevelOrderTraverse(SqBiTree T, void (*func)(TElemType e))
{
    int i = 0;

    //判空异常处理
    if (BiTreeIsEmpty(T)) {
        return false;
    }
    //从头到尾去遍历，遇到非空的才执行操作
    //这种方式对于没有装满的数组会浪费时间，所以应该增加一个找到最后一个非空节点位置的步骤
    //从头遍历到非空姐节点即可
    // while (i < MAX_TREE_SIZE) {
    //     if (T[i] != Nil)
    //         (*func)(T[i]);
    //     i++;
    // }

    //找到最后的非空节点
    for (i = MAX_TREE_SIZE - 1; i >= 0; i--) {
        if (T[i] != Nil)
            break;
    }
    //开始遍历
    for (int j = 0; j <= i; j++) {
        if (T[j] != Nil) 
            (*func)(T[j]);
    }

    return true;
}

//清空二叉树
#define ClearBiTree InitBiTree