/*
 * @Description: 《大话数据结构》
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/adairhu
 * @Date: 2021-09-27 01:30:50
 * @LastEditTime: 2021-09-27 03:58:15
 * @FilePath: \DaHua\Chapter5_String\main-string.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include <stdlib.h>
#include "stringself.h"

int main(void)
{
	bool k;
	int i, j;

	char s;
	String t, s1, s2;
	printf("请输入串s1: ");
	
	k = SStrAssign(s1, "abcd");
	printf("s1串为: ");
	SStrPrint(s1);
	if(!k)
	{
		printf("串长超过MAXSIZE(=%d)\n", MAXSIZE);
		exit(0);
	}
	printf("串长为%d 串空否？%d(1:是 0:否)\n", SStrLength(s1), SStrIsEmpty(s1));

	SStrCopy(s2, s1);
	printf("拷贝s1生成的串为: ");
	SStrPrint(s2);

	printf("请输入串s2: ");
	k = SStrAssign(s2, "efghijk");
	if(!k)
	{
		printf("串长超过MAXSIZE(%d)\n", MAXSIZE);
		exit(0);
	}

	i = SStrCompare(s1, s2);
	if(i < 0)
		s = '<';
	else if(i == 0)
		s = '=';
	else
		s = '>';
	printf("串s1 %c 串s2\n", s);

	printf("s1串为: ");
	SStrPrint(s1);
	printf("s2串为: ");
	SStrPrint(s2);

	// StrInsert(s1, 2, s2);
	// printf("串s2插入串s1得到的串为: ");
	// SStrPrint(s1);

	k = SConcat(t, s1, s2);
	printf("串s1联接串s2得到的串t为: ");
	SStrPrint(t);
	if(k == false)
		printf("串t有截断\n");

	SClearString(s1);
	printf("清为空串后,串s1为: ");
	SStrPrint(s1);
	printf("串长为%d 串空否？%d(1:是 0:否)\n", SStrLength(s1), SStrIsEmpty(s1));

	printf("求串t的子串,请输入子串的起始位置,子串长度: ");
	i=2;
	j=3;
	printf("%d,%d \n", i, j);

	k = SSubString(s2, t, i, j);
	if(k)
	{
		printf("子串s2为: ");
		SStrPrint(s2);
	}

	printf("从串t的第pos个字符起,删除len个字符，请输入pos,len: ");
	i=4;
	j=2;
	printf("%d,%d \n",i,j);

	SStrDelete(t, i, j);
	printf("删除后的串t为: ");
	SStrPrint(t);

	printf("s2为: ");
	SStrPrint(s2);
	i = SStrLength(s2) / 2;
	SStrInsert(s2, i, t);
	printf("在串s2的第%d个字符之前插入串t后,串s2为:\n", i);
	SStrPrint(s2);

	i = SIndex(s2, t, 1);
	printf("s2的第%d个字母起和t第一次匹配：\n", i);

	SSubString(t, s2, 1, 1);
	printf("串t为：");
	SStrPrint(t);

	// printf("串s1为：");
	// SStrPrint(s1);
	SConcat(s1, t, t);
	printf("串s1为：");
	SStrPrint(s1);

	//printf("s1与s1比较结果：%d\n", StrCompare(s1, s1));
	String s4 = "abaca";
	SReplace(s4, "a", "d");
	printf("串s4为：");
	SStrPrint(s4);

	//printf("t的长度%d", t[0]);
	SReplace(s2, t, s1);
	printf("用串s1取代串s2中和串t相同的不重叠的串后,串s2为: ");
	SStrPrint(s2);

	return 0;
}