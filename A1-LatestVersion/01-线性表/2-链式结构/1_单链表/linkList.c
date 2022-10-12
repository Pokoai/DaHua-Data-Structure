/*
 * 功能: 单链表-线性表的链式结构
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-09-14
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*------------------------------- 单链表结构定义 -------------------------------*/

typedef int ElemType;

// 定义链表中节点的数据类型
typedef struct node {
    ElemType data;
    struct node * pNext;
} Node, *pNode;

typedef pNode LinkList;  // 有了头指针，就有了整个链表，即头指针代表一个链表

// 链表图示：https://img.arctee.cn/one/202209162309895.png

/*------------------------------- 单链表结构定义 -------------------------------*/


// 函数前置申明
void InitList(LinkList * pL);
bool InsertList(LinkList L, int position, ElemType elem);
void TraverseList(LinkList L, void (* func)(ElemType elem) );
void print(ElemType elem);
bool DeleteList(LinkList L, int position, ElemType * pElem);
int LengthList(LinkList L);
void DestoryList(LinkList L);
void ClearList(LinkList L);


// 主函数
int main(void)
{
    LinkList L = NULL;  // 定义一个头指针，指向空

    InitList(&L);  // 这里的L是一个指针变量，而非 sqList.c 中的L，所有不用使用 &L

    InsertList(L, 1, 1);
    InsertList(L, 2, 2);
    InsertList(L, 3, 3);
    InsertList(L, 4, 4);
    InsertList(L, 5, 5);
    TraverseList(L, print);

    // InsertList(L, 7, 5);
    InsertList(L, 1, 10);
    TraverseList(L, print);

    ElemType e;
    // DeleteList(L, 0, &e);
    DeleteList(L, 1, &e);
    TraverseList(L, print);
    // DeleteList(L, 6, &e);

    printf("链表长度：%d\n", LengthList(L));

    ClearList(L);
    printf("链表长度：%d\n", LengthList(L));

    return 0;
}

// 初始化
// 会改变头指针的值，故采用 *pL
void InitList(LinkList * pL)
{
    // 创建头节点，并将头指针指向头节点
    *pL = (pNode)malloc(sizeof(Node));
    if ( NULL == *pL ) {
        printf("内存分配失败！\n");
        exit(-1);
    }

    // 头节点的数据域不存储有效数据，所有不用管，而其指针域指向空
    (*pL)->pNext = NULL;
}

// 插入元素
// position >= 1
bool InsertList(LinkList L, int position, ElemType elem)
{
    int i = 0;
    pNode p = L;  // p用来存储第position位置的前驱节点指针

    // 找到第 position 位置的前驱节点，p指向该节点
    while ( i < position-1 && p != NULL ) {
        p = p->pNext;
        i++;
    }

    // 异常处理
    if ( i > position-1 || p == NULL ) {
        printf("插入位置超过范围！\n");
        return false;
    }
    
    // 创建新节点
    pNode pNew = (pNode)malloc(sizeof(Node));
    if ( NULL == pNew ) {
        printf("内存分配失败，无法增添元素！\n");
        return false;
    }
    pNew->data = elem;
    pNew->pNext = NULL;

    // 插入新节点
    pNew->pNext = p->pNext;
    p->pNext = pNew;

    return true;
}

// 辅助函数-遍历过程中打印链表
void print(ElemType elem)
{
    printf("%d ", elem);
}

// 遍历
void TraverseList(LinkList L, void (* func)(ElemType elem) )
{
    pNode p = L->pNext;  // p指向第一个有效节点

    while ( p != NULL ) {
        func(p->data);
        p = p->pNext;
    }
    printf("\n");
}

bool IsEmpty(LinkList L)
{
    return ( NULL == L->pNext );
}

// 删除元素
bool DeleteList(LinkList L, int position, ElemType * pElem)
{
    // 判断是否为空
    if ( IsEmpty(L) ) {
        printf("链表为空，无法删除！\n");
        return false;
    }

    int i = 0;
    pNode p = L;  // p用来存储指向第position位置前驱节点的指针

    // 定位到position位置前驱节点，将p指向它
    while ( i < position-1 && p->pNext != NULL ) {  // 与插入的细微差别：p->pNext != NULL，插入时是p != NULL
        p = p->pNext;
        i++;
    }

    // 异常处理
    if ( i > position-1 || p->pNext == NULL ) {  // 与插入的细微差别：p->pNext == NULL，插入时是p == NULL
        printf("删除位置超出范围！\n");
        return false;
    }

    // 开始删除系列操作
    pNode q = p->pNext;  // q指向 postion 位置节点
    *pElem = q->data;

    p->pNext = q->pNext;  // 将postion位置的前驱和后驱节点相连

    free(q);
    q = NULL;

    return true;
}

// 链表长度
int LengthList(LinkList L)
{
    pNode p = L->pNext;
    int len = 0;

    while ( p != NULL ) {
        ++len;
        p = p->pNext;
    }

    return len;
}

// 销毁链表
// 从头节点开始，释放掉所有节点内存
void DestoryList(LinkList L)
{
    LinkList p = L;

    while (L != NULL ) {
        p = L->pNext;
        free(L);
        L = p;
    }
}

// 清空链表
// 保留头节点，从第一个有效节点开始销毁
void ClearList(LinkList L)
{
    pNode p = L->pNext;

    DestoryList(p);
    L->pNext = NULL;  // 头节点指针域为空
}