/*
 * 功能: 栈
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/%E6%9C%80%E6%96%B0%E4%BC%98%E5%8C%96%E7%89%88%E4%BB%A3%E7%A0%81
 * Date: 2022-08-24
 */

// ![](https://img.arctee.cn/one/202208241553441.png)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef int ElemType;

// 节点
typedef struct node {
    ElemType data;
    struct node * pNext;
}NODE, *PNODE;

// 栈
typedef struct stack {
    PNODE pTop;
    PNODE pBottom;
} STACK, *PSTACK;


// 函数声明
void initStack(PSTACK s);
void pushStack(PSTACK s, ElemType e);
bool traverseStack(PSTACK s);
bool popStack(PSTACK s, ElemType * e);
void clear(PSTACK pS);


int main()
{
    STACK S;

    initStack(&S);

    printf("压栈：\n");
    pushStack(&S, 1);
    pushStack(&S, 2);
    pushStack(&S, 3);
    pushStack(&S, 4);
    pushStack(&S, 5);
    pushStack(&S, 6);

    // printf("遍历栈：");
    traverseStack(&S);

    printf("出栈：\n");
    ElemType e;
    popStack(&S, &e);
    traverseStack(&S);

    popStack(&S, &e);
    traverseStack(&S);

    popStack(&S, &e);
    traverseStack(&S);

    clear(&S);
    traverseStack(&S);

    return 0;
}

// 初始化栈
void initStack(PSTACK pS)
{
    // 创建头节点
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if ( NULL == pHead ) {
        printf("内存分配失败！");
        exit(-1);
    }
    pHead->pNext = NULL;

    // 栈底、栈顶指针均指向头节点
    pS->pBottom = pHead;
    pS->pTop = pHead;
}

// 压栈
void pushStack(PSTACK pS, ElemType e)
{
    // 为新节点分配堆内存
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if ( NULL == pNew ) {
        printf("内存分配失败！");
        exit(-1);
    }

    pNew->data = e;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
}

// 是否为空
bool isEmpty(PSTACK pS)
{
    return (pS->pBottom == pS->pTop);
}

// 遍历栈
bool traverseStack(PSTACK pS)
{
    if ( isEmpty(pS) ) {
        printf("栈为空！");
        return false;
    }
    PNODE p = pS->pTop;
    while ( p != pS->pBottom ) {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");

    return true;
}

// 出栈
bool popStack(PSTACK pS, ElemType * e)
{   
    if ( isEmpty(pS) ) {
        return false;
    }

    PNODE p = pS->pTop;
    *e = p->data;
    pS->pTop = p->pNext;

    free(p);
    p = NULL;

    return true;
}

// 清空栈
void clear(PSTACK pS)
{
    PNODE p = pS->pTop;
    PNODE q = p->pNext;

    while ( p != pS->pBottom ) {
        free(p);
        p = q;
        q = q->pNext;
    }

    pS->pTop = pS->pBottom;
}