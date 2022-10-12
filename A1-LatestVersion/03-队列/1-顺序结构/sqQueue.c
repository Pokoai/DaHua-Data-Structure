/*
 * 功能: 循环队列-顺序结构
 * 作者: Guyue
 * 微信公众号(破壳Ai): https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-08-26
 */


/*
 * 1. 为什么要使用循环队列？ 
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


/*-------------------- 循环队列结构定义 ----------------------*/

#define MAXSIZE 10  // 队列长度

typedef int ElemType;

typedef struct queue {
    ElemType * pBase;  // 数组（用指针表示）
    int front;
    int rear;
} Queue, *pQueue;

// 示意图：https://img.arctee.cn/one/202208271516620.png

/*-------------------- 循环队列结构定义 ----------------------*/


// 函数前置声明
void InitQueue(pQueue pQ);
bool IsFull(pQueue pQ);
bool EnQueue(pQueue pQ, ElemType e);
bool IsEmpty(pQueue pQ);
bool TraverQe(pQueue pQ);
bool DeQueue(pQueue pQ, ElemType * pE);


// 主函数
int main(void)
{
    Queue Q;

    InitQueue(&Q);

    printf("入队：");
    EnQueue(&Q, 1);
    EnQueue(&Q, 2);
    EnQueue(&Q, 3);
    EnQueue(&Q, 4);
    EnQueue(&Q, 5);
    EnQueue(&Q, 6);
    // EnQueue(&Q, 7);

    TraverQe(&Q);

    ElemType e;
    DeQueue(&Q, &e);
    printf("出队：%d\n", e);
    DeQueue(&Q, &e);
    printf("出队：%d\n", e);
    DeQueue(&Q, &e);
    printf("出队：%d\n", e);

    TraverQe(&Q);

    return 0;

}

// 初始化
void InitQueue(pQueue pQ)
{
    // 创建动态数组
    pQ->pBase = (ElemType*)malloc( MAXSIZE * sizeof(ElemType) );
    pQ->front = 0;
    pQ->rear = 0;
}

// 是否已满
bool IsFull(pQueue pQ)
{
    return ( (pQ->rear+1) % MAXSIZE ==  pQ->front );
}

// 入队
bool EnQueue(pQueue pQ, ElemType e)
{
    if ( IsFull(pQ) ) {
        printf("队列已满！无法入队！");
        return false;
    }

    pQ->pBase[pQ->rear] = e;
    pQ->rear = (pQ->rear + 1) % MAXSIZE;

    return true;
}

// 是否空
bool IsEmpty(pQueue pQ)
{
    return ( pQ->front == pQ->rear );
}

// 遍历队列
bool TraverQe(pQueue pQ)
{
    if ( IsEmpty(pQ) ) {
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
bool DeQueue(pQueue pQ, ElemType * pE)
{
    if ( IsEmpty(pQ) ) {
        printf("队列为空！");
        return false;
    }

    *pE = pQ->pBase[pQ->front];
    pQ->front = (pQ->front + 1) % MAXSIZE;

    return true;
}

// 清空

// 销毁