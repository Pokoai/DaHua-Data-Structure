/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-10-15 23:58:53
 * @FilePath: \DaHua\Chapter8_Search\01StaticSearch.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>


//顺序查找
int Sequential_Search(int * a, int n, int key)
{
    for (int i = 1; i <=n; i++) {
        if (a[i] == key)
            return i;
    }
    return 0;
}

//顺序查找-设置哨兵
int Sequential_Search2(int * a, int n, int key)
{
    int i = n;

    a[0] = key; //a[0]为哨兵
    while (a[i] != key) {
        i--;
    }
    return i; //返回0则说明没找到
}

//二分查找
int Binary_Search(int * a, int n, int key)
{
    int low = 1;
    int high = n;
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (key < a[mid]) 
            high = mid - 1;
        else if (key > a[mid]) 
            low = mid + 1;
        else 
            return mid;
    }
    return 0;
}

//插值查找-适用于表长较大且关键字分布均匀的情况
//总结：按部就班（均匀分布）的数据就要用非按部就班（比例在变化）的插值查找算法，加速进入待查值的区间，加速查找速率
//      非按部就班（杂乱分布）的数据就要用按部就班的二分（比例固定在1/2）查找算法，以防陷入局部极值区间的小幅振荡
int InterPolation_Search(int * a, int n, int key)
{
    int low = 1;
    int high = n;
    int mid;

    while (low <= high) {
        mid = low + (high-low) * (key-a[low]) / (a[high]-a[low]);
        if (key < a[mid]) 
            high = mid - 1;
        else if (key > a[mid]) 
            low = mid + 1;
        else 
            return mid;
    }
    return 0;
}

