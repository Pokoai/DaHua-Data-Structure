/*
 * 功能: 有序查找
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-10-10
 */

#include <stdio.h>


// 二分查找
int Binary_Search(int *a, int n, int key)
{
    int low, high, mid;

    low = 1; 
    high = n;
    while ( low <= high ) {
        mid = (low + high) / 2;
        if ( key < a[mid] ) {
            high = mid - 1;
        } 
        else if ( key > a[mid] ) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }
    return 0;
}

// 二分查找优化-插值查找
// 适用于表长较大且关键字分布均匀的情况
// 总结：按部就班（均匀分布）的数据就要用非按部就班（比例在变化）的插值查找算法，加速进入待查值的区间，加速查找速率
//      非按部就班（杂乱分布）的数据就要用按部就班的二分（比例固定在1/2）查找算法，以防陷入局部极值区间的小幅振荡
int Interpolation_Search(int *a, int n, int key)
{
    int low, high, mid;

    low = 1;
    high = n;
    while ( low <= high ) {
        mid = low + (high - low) * (key - a[low]) / (a[high] - a[low]);  // 仅此处与二分查找不同
        // mid = low + (high - low) * 1/2;  // 二分查找

        if ( key < a[mid] ) {
            high = mid - 1;
        }
        else if ( key > a[mid] ) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }
    return 0;
}

// 斐波那契查找
// 利用黄金分割原理，构造斐波那契数列作为分隔点


