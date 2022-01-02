/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-09-26 09:55:17
 * @LastEditTime: 2021-10-14 18:35:51
 * @FilePath: \DaHua\Chapter4_Stack\main-linkqueue.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include "linkqueue.h"

void printQueue(ElemType elem);

int main(void)
{
	int i;
	ElemType d;
	LinkQueue q;
    
	i = InitQueue(&q);
	if(i)
		printf("成功地构造了一个空队列!\n");

	printf("是否空队列？%d(1:空 0:否)  ", QueueIsEmpty(q));
	printf("队列的长度为%d\n", QueueLength(q));

	EnQueue(&q, -5);
	EnQueue(&q, 5);
	EnQueue(&q, 10);
	printf("插入3个元素(-5,5,10)后,队列的长度为%d\n", QueueLength(q));

	printf("是否空队列？%d(1:空 0:否)  ", QueueIsEmpty(q));
	printf("队列的元素依次为：");
	QueueTraverse(q, printQueue);

	i = GetHead(q, &d);
	if(i)
	    printf("队头元素是：%d\n", d);

	DeQueue(&q, &d);
	printf("删除了队头元素%d\n", d);

	i = GetHead(q, &d);
	if(i)
		printf("新的队头元素是：%d\n",d);

	ClearQueue(&q);
	printf("清空队列后,q.front=%u q.rear=%u q.front->next=%u\n", q.front, q.rear, q.front->next);

	DestroyQueue(&q);
	printf("销毁队列后,q.front=%u q.rear=%u\n", q.front, q.rear);
	
	return 0;
}

// 打印元素
void printQueue(ElemType elem)
{
    printf("%d ", elem);
}
