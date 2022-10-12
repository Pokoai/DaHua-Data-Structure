/*
 * 功能: 线性表-顺序结构
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-09-14
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/*-------------------- 线性表顺序结构定义 ---------------------*/

#define MAXSIZE 100  // 数组最大容量

typedef int ElemType;

// 定义线性表的结构类型
typedef struct sqlist {
    ElemType * pBase;  // 数组首元素的地址
    int length;  // 当前长度
    int size;  // 线性表存储容量
} SqList, *pSqList;  // 约定：小写p表示为一个指针变量

/*-------------------- 线性表顺序结构定义 ---------------------*/


// 函数前置声明
void InitList(pSqList L);
bool AppendList(pSqList L, ElemType elem);
bool ShowList(pSqList L);
bool InsertList(pSqList L, int position, ElemType elem);
bool DeleteList(pSqList L, int position, ElemType * pElem);
void ClearList(pSqList L);
void DestoryList(pSqList L);


// 主函数
int main(void)
{
    SqList L;  // 定义了一个线性表变量 L

    InitList(&L);

    AppendList(&L, 1);
    AppendList(&L, 2);
    AppendList(&L, 3);
    AppendList(&L, 4);
    AppendList(&L, 5);
    ShowList(&L);

    InsertList(&L, 1, 10);
    InsertList(&L, 2, 20);
    InsertList(&L, 7, 70);
    InsertList(&L, 9, 90);
    ShowList(&L);

    ElemType e;
    DeleteList(&L, 1, &e);
    DeleteList(&L, 1, &e);
    DeleteList(&L, 5, &e);
    DeleteList(&L, 6, &e);
    ShowList(&L);

    ClearList(&L);
    ShowList(&L);

    DestoryList(&L);
    AppendList(&L, 1);
    
    return 0;
}

// 初始化
void InitList(pSqList L)
{
    // 创建数组，动态内存分配
    L->pBase = (ElemType *)malloc(sizeof(SqList) * MAXSIZE);
    if ( NULL == L->pBase ) {
        printf("内存分配失败！");
        exit(-1);
    }

    // 线性表结构内部变量初始化
    L->length = 0;
    L->size = MAXSIZE;
}

// 线性表是否已满
bool IsFull(pSqList L)
{
    return (L->length == L->size );
}

// 从末尾增添数据
bool AppendList(pSqList L, ElemType elem)
{
    // 异常处理
    if ( IsFull(L) ) {
        printf("线性表已满，无法增添数据！");
        return false;
    }

    // 增添数据
    L->pBase[L->length] = elem;

    // 线性表结构内部变量更新
    L->length++;

    return true;
}

// 线性表是否为空
bool IsEmpty(pSqList L)
{
    return (0 == L->length);
}

// 显示线性表内数据
bool ShowList(pSqList L)
{
    // 异常处理
    if ( IsEmpty(L) ) {
        printf("线性表为空！");
        return false;
    }

    // 遍历线性表
    for ( int i = 0; i < L->length; i++ ) {
        printf("%d ", L->pBase[i]);  // %d 根据 typedef int ElemType; 而定
    }
    printf("\n");

    return true;
}

// 插入元素
// position取值范围：1 ~ L->length+1
bool InsertList(pSqList L, int position, ElemType elem)
{
    // 异常处理
    if ( position < 1 || position > L->length + 1 ) {
        printf("插入位置超出合理范围！");
        return false;
    }

    // 这里可以优化：当线性表已满时，为其增加内存分配，使用 realloc() 函数
    if ( IsFull(L) ) {
        printf("线性表已满，无法插入！");
        return false;
    }

    // 从最后一个元素开始(数组下标为 L->length-1)
    // 到第 position个元素（数组下标为 position-1）结束
    // 依次往后移动一位
    for ( int i = L->length-1; i >= position-1; i-- ) {
        L->pBase[i+1] = L->pBase[i];
    }

    // 插入新元素
    L->pBase[position-1] = elem;

    L->length++;

    return true;
}

// 删除元素
// position取值范围：1 ~ L->length
bool DeleteList(pSqList L, int position, ElemType * pElem)
{
    // 异常处理
    if ( position < 1 || position > L->length ) {
        printf("插入位置超出合理范围！");
        return false;
    }

    if ( IsEmpty(L) ) {
        printf("线性表为空，无法删除！");
        return false;
    }

    // 存储待删除的元素
    *pElem = L->pBase[position-1];

    // 从位置 postion 开始将元素往前移动一位，直接覆盖掉待删除的元素
    for ( int i = position; i < L->length; i++ ) {
        L->pBase[i-1] = L->pBase[i];
    }

    L->length--;

    return true;

}

// 清空线性表
// 线性表存储空间依然保留，只是将其中的数据清空
void ClearList(pSqList L)
{
    // 直接将其长度置为0即可
    L->length = 0;
}

// 销毁线性表
// 释放线性表所占内存空间
void DestoryList(pSqList L)
{
    free(L->pBase);
    L->pBase = NULL;

    L->length = 0;
    L->size = 0;
}