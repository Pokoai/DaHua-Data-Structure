/*
 * 功能: 栈-链式结构
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/%E6%9C%80%E6%96%B0%E4%BC%98%E5%8C%96%E7%89%88%E4%BB%A3%E7%A0%81
 * Date: 2022-09-14
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

// 定义节点的数据类型
typedef struct node {
    ElemType data;
    struct node * pNext;
} Node, *pNode;

// 定义栈的数据类型
typedef struct linkstack {
    pNode pTop;     // 栈顶指针
    pNode pBottom;  // 栈底指针
} LinkStack, *pLinkStack;


void InitStack(pLinkStack S);
bool PushStack(pLinkStack S, ElemType elem);
void TraverseStack(pLinkStack S);
bool IsEmpty(pLinkStack S);
bool PopStack(pLinkStack S, ElemType * pElem);
void ClearStack(pLinkStack S);
void DestoryStack(pLinkStack S);



int main(void)
{
    LinkStack S;

    InitStack(&S);
    PushStack(&S, 1);
    PushStack(&S, 2);
    PushStack(&S, 3);
    PushStack(&S, 4);
    PushStack(&S, 5);
    TraverseStack(&S);

    ElemType e;
    PopStack(&S, &e);
    PopStack(&S, &e);
    PopStack(&S, &e);
    TraverseStack(&S);

    ClearStack(&S);
    DestoryStack(&S);

    return 0;

}

// 初始化
void InitStack(pLinkStack S)
{
    // 首先创建一个头节点
    pNode pHead = (pNode)malloc(sizeof(Node));
    if ( NULL == pHead ) {
        printf("内存分配失败！\n");
        exit(-1);
    }

    pHead->pNext = NULL;

    // 将栈顶、栈底指针均指向头节点
    S->pBottom = pHead;
    S->pTop = pHead;
}

// 压栈
bool PushStack(pLinkStack S, ElemType elem)
{
    // 创建新节点
    pNode pNew = (pNode)malloc(sizeof(Node));
    if ( NULL == pNew ) {
        printf("压栈失败！\n");
        return false;
    }

    pNew->data = elem;
    pNew->pNext = S->pTop;
    S->pTop = pNew;

    return true;
}

// 遍历栈
void TraverseStack(pLinkStack S)
{
    pNode p = S->pTop;

    while ( p != S->pBottom ) {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

// 是否为空
bool IsEmpty(pLinkStack S)
{
    return (S->pBottom == S->pTop );
}

// 出栈
bool PopStack(pLinkStack S, ElemType * pElem)
{
    if ( IsEmpty(S) ) {
        printf("栈空，出栈失败！\n");
        return false;
    }

    pNode p = S->pTop;

    *pElem = p->data;
    S->pTop = p->pNext;

    free(p);  // 勿忘释放栈顶
    p = NULL;

    return true;
}

// 清空栈
void ClearStack(pLinkStack S)
{
    pNode p = S->pTop;
    pNode q = p->pNext;

    while ( p != S->pBottom ) {
        free(p);
        p = q;
        q = q->pNext;
    }

    S->pTop = S->pBottom;
}

// 销毁栈（不保留头节点）
void DestoryStack(pLinkStack S)
{
    ClearStack(S);
    
    free(S->pBottom);  // 释放掉头节点
    S->pBottom = S->pTop = NULL;
}

