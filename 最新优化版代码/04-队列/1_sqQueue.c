/*
 * 功能: 循环队列
 * 作者: Guyue
 * 微信公众号: httpQ://img.arctee.cn/one/pokeai-wechat.png
 * 网站：httpQ://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/%E6%9C%80%E6%96%B0%E4%BC%98%E5%8C%96%E7%89%88%E4%BB%A3%E7%A0%81
 * Date: 2022-08-26
 */


/*
 * 1. 为什么要用循环队列？ 
 * 如果用**链表**实现队列的话，很简单，只要确定一个头指针和一个尾指针即可。
 * 但这里我们选择用**数组**来实现，数组占用一块连续的内存地址，那么就要考虑内存的问题了，入队：尾指针递增，出队：头指针递增，
 * 可以看出不管是增加元素还是删除元素，指针所指的内存地址都在递增，那么前面的地址就浪费了，内存空间一直在变小。
 * 为了解决这个问题，循环队列应运而生。
 * 
 * ![](httpQ://img.arctee.cn/one/202208271516620.png)
 * 
 * 2. 实现循环队列的关键点：
 *  - 头指针 front: 指向第一个有效节点，尾指针 rear: 指向最后一个有效节点的后面一个节点
 *  - 队列长度：len, 有效节点数：len-1
 *  - 入队：rear = (rear + 1) % len;
 *  - 出队：front = (fromt + 1) % len;
 *  - 队空：front == rear
 *  - 队满：(rear + 1) % len == front
 * 
 * 3. 队列的应用：
 * 所有与时间有关的操作都会用到队列
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 7  // 队列长度

typedef int ElemType;

typedef struct queue {
    ElemType * pBase;  // 数组（用指针表示）
    int front;
    int rear;
} QUEUE, *PQUEUE;


void initQueue(PQUEUE pQ);
bool isFull(PQUEUE pQ);
bool enQueue(PQUEUE pQ, ElemType e);
bool isEmpty(PQUEUE pQ);
bool traverse(PQUEUE pQ);
bool deQueue(PQUEUE pQ, ElemType * pE);


int main(void)
{
    QUEUE S;

    initQueue(&S);

    printf("入队：");
    enQueue(&S, 1);
    enQueue(&S, 2);
    enQueue(&S, 3);
    enQueue(&S, 4);
    enQueue(&S, 5);
    enQueue(&S, 6);
    // enQueue(&S, 7);

    traverse(&S);

    ElemType e;
    deQueue(&S, &e);
    printf("出队：%d\n", e);
    deQueue(&S, &e);
    printf("出队：%d\n", e);
    deQueue(&S, &e);
    printf("出队：%d\n", e);

    traverse(&S);

    return 0;

}

// 初始化
void initQueue(PQUEUE pQ)
{
    // 创建动态数组
    pQ->pBase = (ElemType*)malloc( MAXSIZE * sizeof(ElemType) );
    pQ->front = 0;
    pQ->rear = 0;
}

// 是否已满
bool isFull(PQUEUE pQ)
{
    return ( (pQ->rear+1) % MAXSIZE ==  pQ->front );
}

// 入队
bool enQueue(PQUEUE pQ, ElemType e)
{
    if ( isFull(pQ) ) {
        printf("队列已满！无法入队！");
        return false;
    }

    pQ->pBase[pQ->rear] = e;
    pQ->rear = (pQ->rear + 1) % MAXSIZE;

    return true;
}

// 是否空
bool isEmpty(PQUEUE pQ)
{
    return ( pQ->front == pQ->rear );
}

// 遍历队列
bool traverse(PQUEUE pQ)
{
    if ( isEmpty(pQ) ) {
        printf("队列为空！");
        return false;
    }

    int i = pQ->front;
    while ( i != pQ->rear ) {
        printf("%d ", pQ->pBase[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");

    return true;
}

// 出队
bool deQueue(PQUEUE pQ, ElemType * pE)
{
    if ( isEmpty(pQ) ) {
        printf("队列为空！");
        return false;
    }

    *pE = pQ->pBase[pQ->front];
    pQ->front = (pQ->front + 1) % MAXSIZE;

    return true;
}