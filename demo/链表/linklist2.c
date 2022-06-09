//单链表

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int ElemType;

//构造节点
typedef struct node {
    ElemType data;
    struct node * next;
} Node;

//利用节点构造链表
typedef Node * LinkList;  //头指针
































// 初始化
bool Init(LinkList * L)
{
    // 为哑节点分配内存
    *L = (LinkList)malloc(sizeof(Node));
    if (*L == NULL)
        return false;
    // 哑节点 next 指向 null
    (*L)->next = NULL;

    return true;
}

// 是否为空
bool IsEmpty(LinkList L)
{
    return (L->next == NULL);
}

// 是否满
bool IsFull(LinkList L)
{
    // 再分配一个节点空间
    LinkList p = (LinkList)malloc(sizeof(Node));
    
    return (p != NULL);
    free(p); // 记得释放掉测试用的内存，以防造成内存泄漏
}

// 节点数
int Length(LinkList L)
{
    int num = 0;
    Node * p = L->next; // 节点指针 p 指向第一个节点

    while (p != NULL) {
        num++;
        p = p->next;
    }

    return num;
    
}

// 增
bool Insert(LinkList * L, int pos, ElemType e)
{
    // 检测是否满
    if (IsFull(*L)) {
        printf("空间已满");
        return false;
    }

    // pos 异常处理
    if (pos < 1 || pos > Length(*L)+1)
        return false;

    // 创建新节点
   LinkList np = (LinkList)malloc(sizeof(Node));
   if (np == NULL)
        return false;
    np->data = e;
    np->next = NULL;

    // 插入
    Node * p = *L; // p 指向哑节点
    int n = 1; // 哑节点位置

    // 定位到第 pos 个节点的前一个节点
    while (n != pos) { 
        p = p->next;
        n++;
    } 
    // 插入
    np->next = p->next;
    p->next = np;

    return true;

}

// 遍历
void Traverse(LinkList L, void (*func)(ElemType e))
{
    LinkList p = L->next;

    // for (p = L->next; p != NULL; p = p->next) {
    //     (*func)(p->data);
    // }

    while (p) {
        (*func)(p->data);
        p = p->next;
    }
}

// 清空
void Clear(LinkList * L)
{
    LinkList p = (*L)->next;
    LinkList q;

    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    (*L)->next = NULL;
}
