/*
 * @Description: 《大话数据结构》斐波那契数列
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-24 09:07:36
 * @LastEditTime: 2021-09-24 09:22:45
 * @FilePath: \DaHua\Chapter4_Stack\Fbi.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>

int Fbi(int n)
{
    int result;

    if (n == 0)
        result = 0;
    else if (n == 1)
        result = 1;
    else
        result = Fbi(n - 1) + Fbi(n - 2);
    
    return result;
}

int main(void)
{
    for (int i = 0; i < 10; i++) {
        printf("%d ", Fbi(i));
    }

    return 0;
}