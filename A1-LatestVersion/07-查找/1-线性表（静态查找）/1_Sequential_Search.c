/*
 * 功能: 顺序查找
 * 作者: Guyue
 * 微信公众号(破壳Ai): https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
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