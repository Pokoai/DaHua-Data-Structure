/*
 * @Description: 《大话数据结构》串
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-26 20:33:46
 * @LastEditTime: 2021-09-27 15:00:11
 * @FilePath: \DaHua\Chapter5_String\stringself.h
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */


#ifndef _STRINGSELF_H_
#define _STRINGSELF_H_

#include <stdbool.h>

#define MAXSIZE 40

typedef int ElemType;
//定义字符串类型 String
typedef char String[MAXSIZE + 1]; //0号单元存放串的长度

//生成一个其值等于chars的串T
bool StrAssign(String T, char * chars);

//判空
bool StrIsEmpty(String S);

//长度
int StrLength(String S);

//增
bool StrInsert(String S, int pos, String T);

//删
bool StrDelete(String S, int pos, int len);

//初始条件: 串S,T和V存在,T是非空串（此函数与串的存储结构无关） */
//操作结果: 用V替换主串S中出现的所有与T相等的不重叠的子串 */
bool Replace(String S, String T, String V);

/* 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数返回值为0。 */
/* 其中,T非空,1≤pos≤StrLength(S)。 */
int Index(String S, String T, int pos);

//由串S复制得到串T
bool StrCopy(String T, String S);

//比较s和T
//若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0
int StrCompare(String S, String T);

//用T返回S1和S2联接而成的新串。若未截断，则返回TRUE，否则FALSE
bool Concat(String T, String S1, String S2);

//用Sub返回串S的第pos个字符起长度为len的子串
bool SubString(String Sub, String S, int pos, int len);

void ClearString(String S);

void StrPrint(String T);

#endif
