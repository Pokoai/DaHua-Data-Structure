/*
 * @Description: 《大话数据结构》线性表-链式存储结构-实现接口
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-09-20 16:51:13
 * @LastEditTime: 2021-11-01 16:23:45
 * @FilePath: \DaHua\Chapter3_List\linklist.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */


#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

// 1、初始化
bool InitList(LinkList * list)
{
    *list = (LinkList)malloc(sizeof(Node)); //为头节点分配内存，头指针 *list指向分配的节点
    //分配失败异常处理
    if (*list == NULL)
        return false;
    //初始化
    (*list)->next = NULL;

    return true;
}

// 2、判断是否空
bool ListIsEmpty(LinkList list) //头节点指针list
{
    if (list->next == NULL) //头节点的next字段为NULL
        return true;
    else 
        return false;
}

//判断是否已满
bool ListIsFull(LinkList list)
{
    LinkList pnode;

    pnode = (LinkList)malloc(sizeof(Node));
    if (pnode == NULL)
        return true;
    else 
        return false;
    free(pnode);
}

// 3、元素个数
int ListLength(LinkList list)
{
    int count = 0;
    LinkList pnode = list->next; //pnode指向第一个节点，这里不需要考虑头节点，故从第一个节点开始

    while (pnode) {
        ++count;
        pnode = pnode->next;
    }

    return count;
}

// 4、增
bool ListInsert(LinkList * list, int i, ElemType e) 
{   
    int j;
    LinkList pnew;
    LinkList pnode;
    
    // i范围异常处理
    if (i < 1) {
        puts("i out of range.");
        return false;
    }
    //分配内存空间
    pnew = (LinkList)malloc(sizeof(Node));
    if (pnew == NULL) {
        puts("内存分配失败.");
        return false;
    }
    //创建新节点
    pnew->data = e;
    pnew->next = NULL;
    //遍历到位置i
    pnode = *list; //如果在位置1处插入，就涉及到头节点，故这里从头节点开始
    j = 1;
    while (j < i && pnode) {
        pnode = pnode->next;
        j++;
    }
    //i范围超限
    if (!pnode)
        return false;
    //开始插入
    pnew->next = pnode->next;
    pnode->next = pnew;

    return true;
}
// 5、删
bool ListDelet(LinkList * list, int i, ElemType * e)
{
    int j;
    LinkList pnode = *list; //如果在位置1处删除，就涉及到头节点，故这里从头节点开始
    LinkList q;

    //i位置异常处理
    if (i < 1) {
        puts("i out of range. ");
        return false;
    }
    // 遍历到位置i处
    j = 1;
    while (j < i && pnode) {
        pnode = pnode->next;
        j++;
    }
    //i范围超限
    if (!pnode)
        return false;
    //开始删除
    q = pnode->next;
    pnode->next = q->next;

    *e = q->data;
    free(q);
    
    return true;
}

// 6、改
bool ListChange(LinkList * list, int i, ElemType e)
{
    int j;
    LinkList pnode = (*list)->next; //不涉及到头节点，故这里从第一个节点开始

    //i位置异常处理
    if (i < 1) {
        puts("i out of range. ");
        return false;
    }
    // 遍历到位置i处
    j = 1;
    while (j < i && pnode) {
        pnode = pnode->next;
        j++;
    }
    //i范围超限
    if (!pnode)
        return false;
    //开始修改
    pnode->data = e;

    return true;   
}

// 7、查
int LocateElem(LinkList list, ElemType e) 
{
    int j = 1;
    LinkList pnode = list->next; //pnode指向第一个节点，这里不需要考虑头节点，故从第一个节点开始

    while (pnode) {
        if (pnode->data == e)
            return j;
        pnode = pnode->next;
        j++;
    }
    return 0;
}

// 8、取
bool GetElem(LinkList list, int i, ElemType * e)
{
    
    int j;
    LinkList pnode = list->next; //pnode指向第一个节点，这里不需要考虑头节点，故从第一个节点开始

    //i位置异常处理
    if (i < 1) {
        puts("i out of range. ");
        return false;
    }
    // 遍历到位置i处
    j = 1;
    while (j < i && pnode) {
        pnode = pnode->next;
        j++;
    }
    //i范围超限
    if (!pnode)
        return false;
    //开始修改
    *e = pnode->data;

    return true;     
}

// 9、遍
void ListTraverse(LinkList list, void (*func)(ElemType elem))
{
    LinkList pnode = list->next; //pnode指向第一个节点，这里不需要考虑头节点，故从第一个节点开始

    while (pnode) {
        (*func)(pnode->data);
        pnode = pnode->next;
    }
}

// 10、清空
void ClearList(LinkList * list)
{
    LinkList psave;
    LinkList pnode = (*list)->next; //不涉及到头节点，故这里从第一个节点开始

    while (pnode) {
        psave = pnode->next; //先将下一个节点的位置保存下来
        free(pnode);
        pnode = psave;
    }
    (*list)->next = NULL; //将头节点的指针置为NULL
    //因为头结点一直存在并未释放，所以头结点的指针要手动置为NULL
}