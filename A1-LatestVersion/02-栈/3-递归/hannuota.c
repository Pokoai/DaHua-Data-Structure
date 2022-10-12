/*
 * 功能: 递归-汉诺塔
 * 作者: Guyue
 * 微信公众号: httpQ://img.arctee.cn/one/pokeai-wechat.png
 * 网站：httpQ://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-09-13
 */

#include <stdio.h>


void move(int n, char s1, char s2);
void hannuota(int n, char A, char B, char C);


int main(void)
{
    int n;
    
    printf("请输入要移动的盘子个数：");
    scanf("%d", &n);

    hannuota(n, 'A', 'B', 'C');

    return 0;
}

// 将编号为n的盘子从 s1 柱子移到 s2 柱子
void move(int n, char s1, char s2)
{
     printf("将第%d个盘子由%c移到%c\n", n, s1, s2);
}

void hannuota(int n, char A, char B, char C)
{
    /*
    * 如果只有一个盘子
    *    直接将 A柱子上的盘子从 A 移到 C
    * 否则
    *   先将 A柱子上的 n-1 个盘子从 A 借助 C 移到 B
    *   再将 A柱子上的第 n 个盘子由 A 移到 C
    *   最后将 B柱子上的 n-1 个盘子由 B 借助 A 移到 C
    */
   
   if ( 1 == n ) {
        move(n, A, C);
   } else {
        hannuota(n-1, A, C, B);
        move(n, A, C);
        hannuota(n-1, B, A, C);
   }
}
