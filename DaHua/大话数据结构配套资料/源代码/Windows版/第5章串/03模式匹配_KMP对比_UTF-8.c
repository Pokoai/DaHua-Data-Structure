#include "string.h"
#include "stdio.h"    
#include "stdlib.h"   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* �洢�ռ��ʼ������ */

typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;	/* ElemType���͸���ʵ������������������Ϊint */

typedef char String[MAXSIZE+1]; /*  0�ŵ�Ԫ��Ŵ��ĳ��� */

/* ����һ����ֵ����chars�Ĵ�T */
Status StrAssign(String T,char *chars)
{ 
	int i;
	if(strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
			T[i]=*(chars+i-1);
		return OK;
	}
}

Status ClearString(String S)
{ 
	S[0]=0;/*  ���Ϊ�� */
	return OK;
}

/*  ����ַ���T�� */
void StrPrint(String T)
{ 
	int i;
	for(i=1;i<=T[0];i++)
		printf("%c",T[i]);
	printf("\n");
}

/*  ���Next����ֵ�� */
void NextPrint(int next[],int length)
{ 
	int i;
	for(i=1;i<=length;i++)
		printf("%d",next[i]);
	printf("\n");
}

/* ���ش���Ԫ�ظ��� */
int StrLength(String S)
{ 
	return S[0];
}

/* ���ص�ģʽƥ�䷨ */
int Index(String S, String T, int pos) 
{
	int n = 0;
	int i = pos;	/* i��������S�е�ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ�� */
	int j = 1;				/* j�����Ӵ�T�е�ǰλ���±�ֵ */
	while (i <= S[0] && j <= T[0]) /* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
	{
		if (S[i] == T[j]) 	/* ����ĸ�������� */
      	{
			++i;
         	++j; 
      	} 
      	else 				/* ָ��������¿�ʼƥ�� */
      	{  
         	i = i-j+2;		/* i�˻ص��ϴ�ƥ����λ����һλ */
         	j = 1; 			/* j�˻ص��Ӵ�T����λ */
      	} 
      	
		printf("n=%d i=%d j=%d\n",++n,i,j); 
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* ͨ�����㷵���Ӵ�T��next���顣 */
void get_next(String T, int *next) 
{
	int i,k;
  	i=1;
  	k=0;
  	next[1]=0;
  	while (i<T[0])  /* �˴�T[0]��ʾ��T�ĳ��� */
 	{
    	if(k==0 || T[i]== T[k]) 
		{
      		++i;  
			++k;  
			next[i] = k;
    	} 
		else 
			k= next[k];	/* ���ַ�����ͬ����kֵ���� */
  	}
}

/* �����Ӵ�T������S�е�pos���ַ�֮���λ�á��������ڣ���������ֵΪ0�� */
/*  T�ǿգ�1��pos��StrLength(S)�� */
int Index_KMP(String S, String T, int pos) 
{
	int n = 0;
	int i = pos;		/* i��������S�е�ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ�� */
	int j = 1;			/* j�����Ӵ�T�е�ǰλ���±�ֵ */
	int next[255];		/* ����һnext���� */
	get_next(T, next);	/* �Դ�T���������õ�next���� */
	while (i <= S[0] && j <= T[0]) /* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
	{
		if (j==0 || S[i] == T[j]) 	/* ����ĸ�����������������㷨������j=0�ж� */
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* ָ��������¿�ʼƥ�� */
      	 	j = next[j];/* j�˻غ��ʵ�λ�ã�iֵ���� */
      
	  	printf("n=%d i=%d j=%d\n",++n,i,j);  
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

/* ��ģʽ��T��next��������ֵ����������nextval */
void get_nextval(String T, int *nextval) 
{
  	int i,k;
  	i=1;
  	k=0;
  	nextval[1]=0;
  	while (i<T[0])  /* �˴�T[0]��ʾ��T�ĳ��� */
 	{
    	if(k==0 || T[i]== T[k]) 	/* T[i]��ʾ��׺�ĵ����ַ���T[k]��ʾǰ׺�ĵ����ַ� */
		{
      		++i;  
			++k;  
			if (T[i]!=T[k])      /* ����ǰ�ַ���ǰ׺�ַ���ͬ */
				nextval[i] = k;	/* ��ǰ��jΪnextval��iλ�õ�ֵ */
      		else 
				nextval[i] = nextval[k];	/* �����ǰ׺�ַ���ͬ����ǰ׺�ַ��� */
											/* nextvalֵ��ֵ��nextval��iλ�õ�ֵ */
    	} 
		else 
			k= nextval[k];			/* ���ַ�����ͬ����kֵ���� */
		
  	}
}

int Index_KMP1(String S, String T, int pos) 
{
	int n=0;
	int i = pos;		/* i��������S�е�ǰλ���±�ֵ����pos��Ϊ1�����posλ�ÿ�ʼƥ�� */
	int j = 1;			/* j�����Ӵ�T�е�ǰλ���±�ֵ */
	int next[255];		/* ����һnext���� */
	get_nextval(T, next);	/* �Դ�T���������õ�next���� */
	while (i <= S[0] && j <= T[0]) /* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
	{
		if (j==0 || S[i] == T[j]) 	/* ����ĸ�����������������㷨������j=0�ж� */
      	{
         	++i;
         	++j; 
      	} 
      	else 			/* ָ��������¿�ʼƥ�� */
      	 	j = next[j];/* j�˻غ��ʵ�λ�ã�iֵ���� */
      	
      	printf("n=%d i=%d j=%d\n",++n,i,j);
	}
	if (j > T[0]) 
		return i-T[0];
	else 
		return 0;
}

int main()
{
	int i,*p;
	String s1,s2;
	
	StrAssign(s1,"000000000200000000020000000002000000000200000000020000000001");
	printf("����Ϊ: ");
	StrPrint(s1);
	StrAssign(s2,"0000000001");
	printf("�Ӵ�Ϊ: ");
	StrPrint(s2);
	printf("\n");
	
	printf("\n");
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨����ģʽƥ���㷨��\n",Index(s1,s2,1));
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨KMP�㷨�� \n",Index_KMP(s1,s2,1));
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨KMP�����㷨�� \n",Index_KMP1(s1,s2,1));

	return 0;
}
