/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-22 21:30:36
 * @LastEditTime: 2021-09-22 21:46:58
 * @FilePath: \DaHua\Chapter4_Stack\main4.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include "linkstack.h"

void printList(ElemType elem);

int main(void)
{
    LinkStack s;
    ElemType e;

    InitStack(&s);
    
    for (int j = 0; j < 10; j++) {
        Push(&s, j);
    }

    printf("栈中元素依次为：");
    StackTraverse(s, printList);

    Pop(&s, &e);
    printf("弹出的栈顶元素 e=%d\n",e);

    printf("栈空否：%d(1:空 0:否)\n", StackIsEmpty(s));

    GetTop(s,&e);
    printf("栈顶元素 e=%d 栈的长度为%d\n", e, StackLength(s));

    ClearStack(&s);
    printf("清空栈后，栈空否：%d(1:空 0:否)\n", StackIsEmpty(s));

    return 0;
}

// 打印元素
void printList(ElemType elem)
{
    printf("%d ", elem);
}
