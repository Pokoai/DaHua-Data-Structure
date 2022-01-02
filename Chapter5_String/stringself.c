/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-09-26 20:19:47
 * @LastEditTime: 2021-11-02 04:34:33
 * @FilePath: \DaHua\Chapter5_String\stringself.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include <string.h>
#include "stringself.h"

//生成一个其值等于chars的串T
bool StrAssign(String T, char * chars)
{
    //T是否能装下chars
    if (strlen(chars) > MAXSIZE)
        return false;
    //先装长度值
    T[0] = strlen(chars);
    //再装chars
    for (int i = 1; i <= T[0]; i++) {
        T[i] = *(chars + i - 1);
    }

    return true;
}

//判空
bool StrIsEmpty(String S)
{
    if (StrLength(S) == 0)   
        return true;
    else    
        return false;
}

//长度
int StrLength(String S)
{
    return S[0];  //串的首位置存储着串的长度
}

//增
// 初始条件: 串S和T存在,1≤pos≤StrLength(S)+1 */
// 操作结果: 在串S的第pos个字符之前插入串T。完全插入返回TRUE,否则返回FALSE
bool StrInsert(String S, int pos, String T)
{
    int slen = StrLength(S);
    int tlen = StrLength(T);

    //1.pos异常处理
    //pos约束在1~slen+1范围内
    if (pos < 1 || pos > slen + 1) 
        return false;
    //2.长度超限异常处理
    if (slen + tlen > MAXSIZE)
        return false;

    //3.从pos位置开始的字符整体往后移动T的长度个单位
    //从最后的字符开始移动   
    if (pos >= 1 && pos <= slen) {
        for (int i = slen; i >= pos; i--) {
            S[i + tlen] = S[i];
        }
    }
    //4.T插进来
    for (int i = 1; i <= tlen; i++) {
        S[pos + i - 1] = T[i];
    }
    //5.更新长度
    S[0] += tlen;

    return true;
}

//删
bool StrDelete(String S, int pos, int len)
{
    int slen = StrLength(S);

    //1.pos异常处理
    if (pos < 1 || pos > slen)
        return false;
    //2.len异常处理
    if (pos + len > slen)
        return false;
    //3.移位，只有删除的部分位于S内部（还没到末尾元素）才需要移位
    if (pos >=1 && pos + len < slen) {
            for (int i = pos + len; i <= slen; i++)
                S[i - len] = S[i];
    }
    //4.更新长度
    S[0] -= len;

    return true;
}


//由串S复制得到串T
bool StrCopy(String T, String S)
{
    int slen = StrLength(S);
    // int tlen = StrLength(T);

    // //S长度大于T的异常处理
    // if (slen > tlen)
    //     return false;

    for (int i = 1; i <= slen; i++) {
        T[i] = S[i];
        //printf("%d ", i);
    }

    T[0] = slen;

    return true;
}


//用T返回S1和S2联接而成的新串。若未截断，则返回TRUE，否则FALSE
bool Concat(String T, String S1, String S2)
{
    int slen1 = StrLength(S1);
    int slen2 = StrLength(S2);

    //先清空T
    //ClearString(T);

    StrCopy(T, S1);
    StrInsert(T, slen1 + 1, S2);

    T[0] = slen1 + slen2;
    
    //异常处理
    if (slen1 + slen2 > MAXSIZE)    
        return false;
    else 
        return true;
}


//比较s和T
//若S>T,则返回值>0;若S=T,则返回值=0;若S<T,则返回值<0
int StrCompare(String S, String T)
{
    int slen = StrLength(S);
    int tlen = StrLength(T);
    int max;

    // max = slen >= tlen ? slen : tlen;
    // for (int i = 1; i <= max; i++) {
    //     if (S[i] == T[i]) //多余的
    //         continue;
    //     else if (S[i] > T[i])
    //         return 1;
    //     else 
    //         return -1;
    // } 以上代码存在问题，长度短的串后面的值未知，不应该参与比较

    for (int i = 1; i <= slen && i <= tlen; i++) {
        if (S[i] != T[i])
            return S[i] - T[i];
    }

    return (slen - tlen);
}


//用Sub返回串S的第pos个字符起长度为len的子串
bool SubString(String Sub, String S, int pos, int len)
{
    int slen = StrLength(S);

    //异常处理
    if (pos < 1 || pos > slen)
        return false;
    if (pos + len > slen)
        return false;
    
    for (int i = pos; i <= pos + len; i++)
        Sub[i - pos + 1] = S[i];
    Sub[0] = len;

    return true;
}


/* 返回子串T在主串S中第pos个字符之后的位置。若不存在,则函数返回值为0。 */
/* 其中,T非空,1≤pos≤StrLength(S)。 */
int Index(String S, String T, int pos)
{
    int slen = StrLength(S);
    int tlen = StrLength(T);

    String sub;

    //pos异常处理
    if (pos < 1 || pos > slen) 
        return false;

    for (int i = pos; i <= slen - tlen + 1; i++) {
        SubString(sub, S, i, tlen);
        if (!StrCompare(sub, T))
            return i;
    }

    return 0;
}


//初始条件: 串S,T和V存在,T是非空串（此函数与串的存储结构无关） 
//操作结果: 用V替换主串S中出现的所有与T相等的不重叠的子串 
bool Replace(String S, String T, String V)
{
    int i = 1; //从第一个字符开始查找
    int tlen = StrLength(T);
    int vlen = StrLength(V);

    //S中不存在T的异常处理
    // if ((Index(S, T, 1)) == 0)
    //     return false;
    // while ((n = Index(S, T, 1))) {
    //     StrDelete(S, n, tlen);
    //     StrInsert(S, n + 1, V);
    // } 
    //以上代码存在问题：1.没有考虑正确如何处理不重叠问题
    //2.Index(S, T, 1)重复，对于先执行后判断的情况应该使用 do...while...模式
    do {
        i = Index(S, T, i);

        if (i) {
            StrDelete(S, i, tlen);
            StrInsert(S, i, V);
            i += vlen;
        }
    }while(i);
    
    return true;
}


void ClearString(String S)
{
    S[0] = 0;
}

//输出字符串T
void StrPrint(String S)
{ 
	for(int i = 1; i <= S[0]; i++) {
        //printf("%d:", i);
		printf("%c", S[i]);
    }

	printf("\n");
}
