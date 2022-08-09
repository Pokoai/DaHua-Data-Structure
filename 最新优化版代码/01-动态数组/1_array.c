/*
 * 功能: 动态数组
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/pokoai
 * Date: 2022-08-10
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100  // 数组最大容量

// 泛型
typedef int TYPE;

// 定义数组的结构类型
typedef struct arr {
    TYPE * pBase;  // 数组首元素的地址
    int len;  // 数组容量
    int cnt;  // 数组当前元素个数
} ARRAY;


void initArray(ARRAY * pArr, int length);
bool arrayIsFull(ARRAY * pArr);
bool appendArray(ARRAY * pArr, TYPE elem);
bool arrayIsEmpty(ARRAY * pArr);
void showArray(ARRAY * pArr);
int lengthArray(ARRAY * pArr);
bool insertArray(ARRAY * pArr, int pos, TYPE elem);
bool deleteArray(ARRAY * pArr, int pos, TYPE * pElem);
void inverseArray(ARRAY * pArr);

int main(void)
{
    ARRAY arr;  // 首先声明一个数组变量
    
    initArray(&arr, MAXSIZE);  // 初始化数组
    appendArray(&arr, 10);  // 数组中增加元素
    appendArray(&arr, 11);
    appendArray(&arr, 12);
    // appendArray(&arr, 13);
    // printf("数组元素个数：%d\n", arr.cnt);
    showArray(&arr);

    printf("插入元素：\n");
    insertArray(&arr, 1, 1);
    showArray(&arr);
    insertArray(&arr, 5, 2);
    showArray(&arr);
    insertArray(&arr, 2, 3);
    showArray(&arr);

    printf("删除元素：\n");
    TYPE elem;
    deleteArray(&arr, 3, &elem);
    showArray(&arr);
    deleteArray(&arr, 3, &elem);
    showArray(&arr);

    printf("倒置数组\n");
    inverseArray(&arr);
    showArray(&arr);

    return 0;
    
}

// 初始化数组
void initArray(ARRAY * pArr, int length)
{
    pArr->pBase = (TYPE *)malloc(sizeof(TYPE) * length);  // 为数组分配内存空间
    if ( NULL == pArr->pBase ) {
        printf("数组内存分配失败！\n");
        exit(-1);  // 终止整个程序
    }

    pArr->len = length;
    pArr->cnt = 0;
}

// 增添元素
bool appendArray(ARRAY * pArr, TYPE elem)
{
    // 数组是否已满
    if ( arrayIsFull(pArr) ) {
        printf("数组已满\n");
        return false;
    }

    *(pArr->pBase + pArr->cnt) = elem;
    pArr->cnt++;

    return true; 
}

// 数组是否已满
bool arrayIsFull(ARRAY * pArr)
{
    return (pArr->cnt == pArr->len);
}

// 数组是否为空
bool arrayIsEmpty(ARRAY * pArr)
{
    return (0 == pArr->cnt);
}

// 打印数组
void showArray(ARRAY * pArr)
{
    // 数组是否已满
    if ( arrayIsEmpty(pArr) ) {
        printf("数组为空\n");
    } else {
        for ( int i = 0; i < pArr->cnt; i++ ) {
            printf("%d ", *(pArr->pBase + i));
        }
        printf("\n");
    }
}

// 数组个数
int lengthArray(ARRAY * pArr)
{
    return pArr->cnt;
}

// 插入元素
// pos：从 1 开始
bool insertArray(ARRAY * pArr, int pos, TYPE elem)
{
    if ( arrayIsFull(pArr) ) {
        printf("数组已满，无法插入！\n");
        return false;
    }
    if ( pos < 1 || pos > pArr->cnt+1 ) {
        printf("插入位置超出范围！\n");
        return false;
    }

    // 在最后一个元素的后面插入
    // if ( pArr->cnt+1 == pos ) {
    //     *(pArr->pBase + pArr->cnt) = elem;
    // } else {
    //     // 先往后移动一位
    //     for ( int i = pArr->cnt-1; i >= pos-1; i-- ) {
    //         *(pArr->pBase+i+1) = *(pArr->pBase+i);
    //     }
    //     // 再插入
    //     *(pArr->pBase + pos - 1) = elem;
    // }

    // 上面的效果其实跟下面一样
    for ( int i = pArr->cnt-1; i >= pos-1; i-- ) {
        *(pArr->pBase+i+1) = *(pArr->pBase+i);
    }
    // 再插入
    *(pArr->pBase + pos - 1) = elem;
    pArr->cnt++;

    return true;
}

// 删除元素
bool deleteArray(ARRAY * pArr, int pos, TYPE * pElem)
{
    if ( arrayIsEmpty(pArr) ) {
        printf("数组为空，删除失败！\n");
        return false;
    }
    if ( pos < 1 || pos > pArr->cnt+1 ) {
        printf("删除位置超出范围！\n");
        return false;
    }

    *pElem = pArr->pBase[pos-1];
    for ( int i = pos; i < pArr->cnt; i++ ) {
        pArr->pBase[i-1] = pArr->pBase[i];
    }
    pArr->cnt--;
    
    return true;
}

// 倒置数组
void inverseArray(ARRAY * pArr)
{
    TYPE temp;
    
    for ( int i = 0; i < pArr->cnt / 2; i++ ) {
        temp = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[pArr->cnt-1-i];
        pArr->pBase[pArr->cnt-1-i] = temp;
    }
}