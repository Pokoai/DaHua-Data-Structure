// 线性表顺序存储结构

#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100
typedef int ElemType;

// 定义存储结构
typedef struct {
    ElemType array[MAXSIZE];
    int Length;
} SqList;

// 初始化
void Init(SqList * L)
{
    L->Length = 0;
}

// 是否为空
bool IsEmpty(SqList L)
{
    return L.Length == 0 ? true : false;
}

// 是否已满
bool IsFull(SqList L)
{
    return L.Length == MAXSIZE ? true : false;
}

// 元素个数
int Length(SqList L)
{
    return L.Length;
}

// 插入元素
bool Insert(SqList * L, int pos, ElemType e)
{
    // 数组已满
    if (IsFull(*L)) {
        PrintListf("数组已满！");
        return false;
    }
        
    // pos 异常检查
    if (pos < 0 || pos > MAXSIZE-1) {
        PrintListf("插入位置异常！");
        return false;
    }

    // 首先将后部分元素均往后移动一位
    if (pos < L->Length) { // 不包含最后一个位置
        for (int i = L->Length-1; i >= pos; i--) {
            L->array[i+1] = L->array[i];
        }
    }
    L->array[pos] = e; // 插入
    
    // 更新 Length
    L->Length++;

    return true;
        
}

// 删除指定位置的元素，存入 e 中
bool Delete(SqList * L, int pos, ElemType * e) 
{
    //数组为空异常
    if( IsEmpty(*L) ) {
        puts( "数组为空！" );
        return false;
    }

    //pos 异常处理
    if( pos < 0 || pos >= L->Length) {
        puts("删除位置错误！");
        return false;
    }

    //取出要删除的值
    *e = L->array[pos];

    //如果删除的是最后一个元素，就不用移动覆盖，直接 Length 减一即可
    if( pos != L->Length - 1 ) {
        for( int i = pos + 1; i < L->Length; i++ ) {
            L->array[i-1] = L->array[i];
        }
    }

    L->Length--;

    return true;
}

// 替换
bool Change( SqList * L, int pos, ElemType e )
{
    //非空检查
    if( IsEmpty(*L) ) {
        puts( "数组为空!" );
        return false;
    }

    //pos 异常处理
    if ( pos < 0 || pos > L->Length-1 ) {
        puts( "pos 超出范围！" );
        return false;
    }

    // 将 pos 位置元素替换为 e
    L->array[pos] = e;

    return true; 
}

// 查询第 pos 位置的值
bool Query( SqList L, int pos, ElemType * e) 
{
    //非空检查
    if( IsEmpty(L) ) {
        puts( "数组为空!" );
        return false;
    }

    //pos 异常处理
    if ( pos < 0 || pos > L.Length-1 ) {
        puts( "pos 超出范围！" );
        return false;
    }

    *e = L.array[pos];

    return true;
}


// 遍历
void Traverse(SqList L, void (*func)(ElemType e))
{
    for (int i = 0; i < L.Length; i++)
        {
            (*func)(L.array[i]);
        }
}

// 打印线性表
void PrintList( ElemType e ) 
{
    PrintListf( "%d ", e );
}

// 清空线性表
void Clear( SqList * L)
{
    L->Length = 0;
}


//主函数
int main(void)
{
    SqList list;
    ElemType de;

    Init(&list);

    for( int i = 0; i < 10; i++ ) {
        Insert(&list, i, i * i );
    }
    puts( "\n遍历线性表：" );
    Traverse( list, PrintList );
    PrintListf( "\n元素个数：%d\n", Length(list) );

    Delete( &list, 2, &de );
    PrintListf( "删除的是：%d\n", de );
    puts( "遍历线性表：" );
    Traverse( list, PrintList );
    PrintListf( "\n元素个数：%d\n", Length(list) );

    Change( &list, 1, 999);
    puts( "\n遍历线性表：" );
    Traverse( list, PrintList );

    Clear(&list);
    puts( "\n\n遍历线性表：" );
    Traverse( list, PrintList );
    PrintListf( "元素个数：%d\n", Length(list) );

    Insert( &list, 0, 100 );
    Insert( &list, 1, 98);
    Insert( &list, 1, 99);
    Insert( &list, 0, 1);
    puts( "\n遍历线性表：" );
    Traverse( list, PrintList );
    PrintListf( "\n元素个数：%d\n", Length(list) );

    return 0;
}




