/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-24 22:41:27
 * @LastEditTime: 2021-09-24 22:58:36
 * @FilePath: \DaHua\Chapter4_Stack\main-sqqueue.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */
#include <stdio.h>
#include "sqQueue.h"

void printQueue(ElemType elem);

int main()
{
	int i = 0, l;
	ElemType d;
	SqQueue Q;

	InitQueue(&Q);
	printf("初始化队列后，队列空否？%u(1:空 0:否)\n", QueueIsEmpty(Q));

	printf("请输入整型队列元素(不超过%d个),-1为提前结束符: ", MAXSIZE - 1);
	do
	{
		/* scanf("%d",&d); */
		d = i + 100;
		if(d == -1)
			break;
		i++;
		EnQueue(&Q, d);
	}while(i<MAXSIZE-1);

	printf("队列长度为: %d\n", QueueLength(Q));
	printf("现在队列空否？%u(1:空 0:否)\n", QueueIsEmpty(Q));

	printf("连续%d次由队头删除元素,队尾插入元素:\n", MAXSIZE);
	for(l = 1; l <= MAXSIZE; l++)
	{
		DeQueue(&Q, &d);
		printf("删除的元素是%d,插入的元素:%d \n", d, l + 1000);
		/* scanf("%d",&d); */
		d = l + 1000;
		EnQueue(&Q, d);
	}
	l = QueueLength(Q);

	printf("现在队列中的元素为: \n");
	QueueTraverse(Q, printQueue);
    
	printf("共向队尾插入了%d个元素\n", i + MAXSIZE);
	if(l - 2 > 0)
		printf("现在由队头删除%d个元素:\n", l - 2);
	while(QueueLength(Q) > 2)
	{
		DeQueue(&Q, &d);
		printf("删除的元素值为%d\n", d);
	}

	if(GetHead(Q, &d))
		printf("现在队头元素为: %d\n", d);

	ClearQueue(&Q);
	printf("清空队列后, 队列空否？%u(1:空 0:否)\n", QueueIsEmpty(Q));
    
	return 0;
}

// 打印元素
void printQueue(ElemType elem)
{
    printf("%d ", elem);
}
