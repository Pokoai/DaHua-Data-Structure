/*
 * 功能: 栈-顺序结构
 * 作者: Guyue
 * 微信公众号(破壳Ai): https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-09-14
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*------------------- 顺序栈结构定义 ----------------------*/

#define MAXSIZE 100

typedef int ElemType;

// 顺序栈的类型定义
typedef struct {
    ElemType * pBase;  // 数组基地址
    int top;   // 栈顶指针，起初为 -1
} SqStack, *pSqStack;

/*------------------- 顺序栈结构定义 ----------------------*/ 


// 函数前置定义
void InitStack(pSqStack S);
bool IsFull(pSqStack S);
bool PushStack(pSqStack S, ElemType elem);
void TraverseStack(pSqStack S);
bool IsEmpty(pSqStack S);
bool PopStack(pSqStack S, ElemType * pElem);
void ClearStack(pSqStack S);
void DestoryStack(pSqStack S);


// 主函数
int main(void)
{ 
    SqStack S;

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

    DestoryStack(&S);
    TraverseStack(&S);

    return 0;
}

// 初始化
void InitStack(pSqStack S)
{
    // 分配顺序存储空间
    S->pBase = (ElemType*)malloc(sizeof(ElemType) * MAXSIZE);

    S->top = -1; 
}

bool IsFull(pSqStack S)
{
    return (S->top+1 == MAXSIZE );
}

// 压栈
bool PushStack(pSqStack S, ElemType elem)
{
    if ( IsFull(S) ) {
        printf("栈已满，压栈失败！");
        return false;
    }

    S->pBase[++S->top] = elem;  // 入栈用前缀 ++

    return true;
}

// 遍历栈
void TraverseStack(pSqStack S)
{
    for ( int i = 0; i < S->top+1; i++ ) {
        printf("%d ", S->pBase[i]);
    }

    printf("\n");
}

bool IsEmpty(pSqStack S)
{
    return ( -1 == S->top );
}

// 出栈
bool PopStack(pSqStack S, ElemType * pElem)
{
    if ( IsEmpty(S) ) {
        printf("栈为空，出栈失败！");
        return false;
    }

    *pElem = S->pBase[S->top--];  // 出栈用后缀 --
}

// 清空栈
void ClearStack(pSqStack S)
{
    S->top = -1;
}

// 销毁栈
// 释放动态内存
void DestoryStack(pSqStack S)
{
    free(S->pBase);
    S->pBase = NULL;

    S->top = -1;
}



