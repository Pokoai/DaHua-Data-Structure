/*
 * 功能: 单链表
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/%E6%9C%80%E6%96%B0%E4%BC%98%E5%8C%96%E7%89%88%E4%BB%A3%E7%A0%81
 * Date: 2022-08-20
 */


/*
 * 链表示意图：https://img.arctee.cn/one/202208221551214.png
 * 首节点：第一个有效节点
 * 头节点：首节点前面的哪个节点；不存放有效数据；目的是为了方便对首节点的操作，保持链表操作的一致性；
 * 尾节点：最后一个节点
 * 尾指针：指向最后一个节点的变量
 * 头指针：指向头节点的变量，知道了头指针就确定了一个链表； 
 * 
 * free(p): 删除p所指向节点的内存（堆内存），不是删除p本身所占内存（栈内存）；
*/ 


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ElemType;

// 节点定义
typedef struct node {
    ElemType data;
    struct node * pNext; 
}NODE, *PNODE;  // NODE等价于struct node, *PNODE等价于struct node *


// 函数声明
PNODE createList();
bool traverseList(PNODE pHead);
bool isEmpty(PNODE pHead);
int lengthList(PNODE pHead);
bool insertList(PNODE pHead, int pos, ElemType elem);
bool deleteList(PNODE pHead, int pos, ElemType * elem);
void sortList(PNODE pHead);


int main(void)
{
    PNODE pHead = createList();  // 创建一个链表，并返回头节点的地址给头指针pHead
    traverseList(pHead);  // 打印链表

    int len = lengthList(pHead);
    printf("链表长度：%d\n", len);

    printf("---插入元素---\n");
    insertList(pHead, 0, 555);
    traverseList(pHead);

    len = lengthList(pHead);
    printf("链表长度：%d\n", len);

    printf("---删除元素---\n");
    ElemType e;
    deleteList(pHead, 0, &e);
    traverseList(pHead);

    printf("---排序---\n");
    sortList(pHead);
    traverseList(pHead);

}

// 创建链表
PNODE createList()
{
    int len;
    int val;  

    // 首先创建一个头指针
    PNODE pHead = (PNODE)malloc(sizeof(NODE));  
    if ( NULL == pHead ) {
        printf("头节点内存分配失败，程序终止！");
        exit(-1);
    }
    // printf("%p\n", pHead);
    // 定义尾节点
    PNODE pTail = pHead;
    pTail->pNext = NULL;

    printf("请输入要创建链表的节点数：len = ");
    scanf("%d", &len);
    for ( int i = 0; i < len; i++ ) {
        printf("请输入第%d个节点的值：", i+1);
        scanf("%d", &val);
        // 为新节点分配内存
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if ( NULL == pNew ) {
            printf("节点内存分配失败，程序终止！");
            exit(-1);
        }
        // 新节点初始化
        pNew->data = val;
        pNew->pNext = NULL;
        // 将新节点挂到尾节点后面
        pTail->pNext = pNew;
        // 更新尾节点
        pTail = pNew;
    }
    // printf("%p\n", pTail);
    return pHead;
}

// 遍历链表
bool traverseList(PNODE pHead)
{
    if ( isEmpty(pHead) ) {
        printf("链表为空!");
        return false;
    }

    // q指向第一个有效节点
    PNODE q = pHead->pNext;
    
    printf("遍历链表：");
    while ( q != NULL ) {
        printf("%d ", q->data);
        q = q->pNext;
    }
    printf("\n");

    return true;
}

// 是否为空
bool isEmpty(PNODE pHead)
{
    return ( NULL == pHead->pNext );
}

// 链表长度
int lengthList(PNODE pHead)
{
    int len = 0;
    PNODE p = pHead->pNext;

    while ( p != NULL ) {
        len++;
        p = p->pNext;
    }
    return len;
}

// 插入元素
// pos >= 1
// 该操作涉及到两个节点：pos前驱、pos本身
// 所以先遍历到 pos前驱，然后利用 pos前驱表示出 pos本身
bool insertList(PNODE pHead, int pos, ElemType elem)
{
    // 异常处理
    // if ( pos > 1 + lengthList(pHead) ) {
    //     printf("插入位置超过有效范围!\n");
    //     return false;
    // }
    
    // lengthList(pHead)要遍历链表，后面代码 while ( i++ < pos-1 ) { p = p->pNext; }也遍历链表，相当于遍历了两次，故效率低下
    // 优化：将两者结合起来，while( (i++ < pos-1) && p != NULL ) { p = p->pNext; }

    PNODE p = pHead;
    int i = 0;

    while ( (i++ < pos-1) && p != NULL ) {
        p = p->pNext;
    }

    if ( (i > pos-1) || NULL == p ) {  // NULL==p: pos>n+1; i>pos-1: pos<1
        printf("插入位置超过有效范围!\n");
        return false;
    }

    // 为新节点分配内存空间
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if ( NULL == pNew ) {
        printf("内存分配失败！");
        exit(-1);
    }
    pNew->data = elem;

    // 定位到pos位置的前驱节点，p指向该前驱节点
    // PNODE p = pHead;  
    // int i = 0;
    // while ( i++ < pos-1 ) {
    //     p = p->pNext;
    // }

    PNODE q = p->pNext;  // q指向pos位置的节点
    pNew->pNext = q;   // 先将新节点后端与pos节点连起来
    p->pNext = pNew;  // 再将新节点前端与pos前驱节点连起来

    return true;
}

// 删除元素
// 该操作涉及到三个节点：pos前驱、pos本身、pos后驱
// 所以先遍历到 pos前驱，然后利用pos前驱依次表示出 pos本身和pos后驱
bool deleteList(PNODE pHead, int pos, ElemType * elem)
{
    // 异常处理
    if ( isEmpty(pHead) ) {
        printf("链表为空！");
        return false;
    }
    // if ( pos > lengthList(pHead) ) {
    //     printf("pos超出有效范围！");
    //     return false;
    // } 

    // 定位到pos位置的前驱节点，p指向该前驱节点
    // PNODE p = pHead;
    // int i = 0;
    // while ( i++ < pos-1 ) {
    //     p = p->pNext;
    // }

    PNODE p = pHead;
    int i = 0;

    while ( (i++ < pos-1) && p != NULL ) {
        p = p->pNext;
    }

    if ( (i > pos-1) || NULL == p ) {
        printf("删除位置超过有效范围!\n");
        return false;
    }

    // 删除pos位置节点
    PNODE q = p->pNext;  // q指向pos位置的节点
    *elem = q->data;

    p->pNext = q->pNext;  // 将pos位置的前驱节点与后驱节点（q->pNext）连接起来
    // printf("p->pNext:%p\n", p->pNext);
    // printf("q:%p\n", q);
    free(q);  // 释放q所指的那个变量所占的内存，但是q变量仍然存在
    q = NULL;  // 将q指向空，否则q就变成了野指针，存在危险

    return true;
}

// 排序
void sortList(PNODE pHead)
{
    ElemType t; 

    for ( PNODE p = pHead; p != NULL; p = p->pNext ) {
        for ( PNODE q = p->pNext; q != NULL; q = q->pNext ) {
            if ( p->data > q->data ) {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
}