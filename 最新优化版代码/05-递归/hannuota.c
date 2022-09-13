/*
 * 功能: 递归-汉诺塔
 * 作者: Guyue
 * 微信公众号: httpQ://img.arctee.cn/one/pokeai-wechat.png
 * 网站：httpQ://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/%E6%9C%80%E6%96%B0%E4%BC%98%E5%8C%96%E7%89%88%E4%BB%A3%E7%A0%81
 * Date: 2022-09-13
 */

#include <stdio.h>

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
        printf("将第%d个盘子由%c移到%c\n", n, A, C);
   } else {
        hannuota(n-1, A, C, B);
        printf("将第%d个盘子由%c移到%c\n", n, A, C);
        hannuota(n-1, B, A, C);
   }
}

int main(void)
{
    int n;
    
    printf("请输入要移动的盘子个数：");
    scanf("%d", &n);

    hannuota(n, 'A', 'B', 'C');

    return 0;
}
