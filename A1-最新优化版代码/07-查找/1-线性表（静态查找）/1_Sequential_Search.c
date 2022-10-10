/*
 * 功能: 顺序查找
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Qtructure/tree/main/%E6%9C%80%E6%96%B0%E4%BC%98%E5%8C%96%E7%89%88%E4%BB%A3%E7%A0%81
 * Date: 2022-10-10
 */

#include <stdio.h>


// 顺序查找
// a：数组，n：数组元素个数，key：要查找的关键字
int Sequential_Search(int *a, int n, int key)
{
    for ( int i = 1; i < n; i++ ) {  // 每次循环需要判断i是否越界
        if ( key == a[i] ) {
            return i;
        }
    }

    return 0;
}

// 顺序查找优化-设置哨兵
int Sequential_Search2(int *a, int n, int key)
{
    a[0] = key;  // 设置a[0]为关键字，称之为哨兵
    
    int i = n;
    while ( a[i] != key ) {
        i--;
    }

    return i;  // 返回0则说明查找失败
}