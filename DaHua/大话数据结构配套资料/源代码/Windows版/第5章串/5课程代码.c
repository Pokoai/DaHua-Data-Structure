/*  TΪ�ǿմ���������S�е�pos���ַ�֮�������T��ȵ��Ӵ��� */
/*  �򷵻ص�һ���������Ӵ���S�е�λ�ã����򷵻�0 */
int Index(String S, String T, int pos) 
{
	int n,m,i;
	String sub;
	if (pos > 0) 
	{
		n = StrLength(S);				/* �õ�����S�ĳ��� */
		m = StrLength(T);				/* �õ��Ӵ�T�ĳ��� */
		i = pos;
		while (i <= n-m+1) 
		{
			SubString(sub, S, i, m);	/* ȡ�����е�i��λ�ó�����T��ȵ��Ӵ���sub */
			if (StrCompare(sub,T) != 0) /* ������������ */
				++i;
			else 						/* ���������� */
				return i;				/* �򷵻�iֵ */
		}
	}
	return 0;							/* �����Ӵ���T��ȣ�����0 */
}

/* �����Ӵ�T������S�е�pos���ַ�֮���λ�á���������,��������ֵΪ0�� */
/* ����,T�ǿ�,1��pos��StrLength(S)�� */
int Index(String S, String T, int pos) 
{
	int i = pos;					/* i��������S�е�ǰλ���±�ֵ����posλ�ÿ�ʼƥ�� */
	int j = 1;						/* j�����Ӵ�T�е�ǰλ���±�ֵ */
	while (i <= S[0] && j <= T[0]) 	/* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
	{
		if (S[i] == T[j]) 			/* ����ĸ�������� */
      	{
			++i;
         	++j; 
      	} 
      	else 						/* ָ��������¿�ʼƥ�� */
      	{  
         	i = i-j+2;				/* i�˻ص��ϴ�ƥ����λ����һλ */
         	j = 1; 					/* j�˻ص��Ӵ�T����λ */
      	}      
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
	int i = pos;					/* i��������S�е�ǰλ���±�ֵ����posλ�ÿ�ʼƥ�� */
	int j = 1;						/* j�����Ӵ�T�е�ǰλ���±�ֵ */
	int next[255];					/* ����һnext���� */
	get_next(T, next);				/* �Դ�T���������õ�next���� */
	while (i <= S[0] && j <= T[0]) 	/* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
	{
		if (j==0 || S[i] == T[j]) 	/* ����ĸ�����������������㷨������j=0�ж� */
      	{
         	++i;
         	++j; 
      	} 
      	else						/* ָ��������¿�ʼƥ�� */
      	{ 						
      	 	j = next[j];			/* j�˻غ��ʵ�λ�ã�iֵ���� */
      	}
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
  	while (i<T[0])  				/* �˴�T[0]��ʾ��T�ĳ��� */
 	{
    	if(k==0 || T[i]== T[k]) 	/* T[i]��ʾ��׺�ĵ����ַ���T[k]��ʾǰ׺�ĵ����ַ� */
		{
      		++i;  
			++k;  
			if (T[i]!=T[k])      	/* ����ǰ�ַ���ǰ׺�ַ���ͬ */
				nextval[i] = k;		/* ��ǰ��kΪnextval��iλ�õ�ֵ */
      		else 
				nextval[i] = nextval[k];	/* �����ǰ׺�ַ���ͬ����ǰ׺�ַ��� */
											/* nextvalֵ��ֵ��nextval��iλ�õ�ֵ */
    	} 
		else 
			k= nextval[k];			/* ���ַ�����ͬ����kֵ���� */
  	}
}

