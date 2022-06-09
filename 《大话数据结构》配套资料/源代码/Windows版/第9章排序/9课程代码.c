


#define MAXSIZE 10000  	/* ����Ҫ��������������ֵ���ɸ�����Ҫ�޸� */
typedef struct
{
	int r[MAXSIZE+1];	/* ���ڴ洢Ҫ�������飬r[0]�����ڱ�����ʱ���� */
	int length;			/* ���ڼ�¼˳���ĳ��� */
}SqList;


/* ����L������r���±�Ϊi��j��ֵ */
void swap(SqList *L,int i,int j) 
{ 
	int temp=L->r[i]; 
	L->r[i]=L->r[j]; 
	L->r[j]=temp; 
}

/* ��˳���L����������ð����������棩 */
void BubbleSort0(SqList *L)
{ 
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=i+1;j<=L->length;j++)
		{
			if(L->r[i]>L->r[j])
			{
				 swap(L,i,j);	/* ����L->r[i]��L->r[j]��ֵ */
			}
		}
	}
}

/* ��˳���L��ð������ */
void BubbleSort(SqList *L)
{ 
	int i,j;
	for(i=1;i<L->length;i++)
	{
		for(j=L->length-1;j>=i;j--) /* ע��j�ǴӺ���ǰѭ�� */
		{
			if(L->r[j]>L->r[j+1]) 	/* ��ǰ�ߴ��ں��ߣ�ע����������һ�㷨�Ĳ��죩*/
			{
				 swap(L,j,j+1);		/* ����L->r[j]��L->r[j+1]��ֵ */
			}
		}
	}
}

/* ��˳���L���Ľ�ð���㷨 */
void BubbleSort2(SqList *L)
{ 
	int i,j;
	Status flag=TRUE;					/* flag������Ϊ��� */
	for(i=1;i<L->length && flag;i++) 	/* ��flagΪtrue�����ݽ����������˳�ѭ�� */
	{
		flag=FALSE;						/* ��ʼΪFalse */
		for(j=L->length-1;j>=i;j--)
		{
			if(L->r[j]>L->r[j+1])
			{
				swap(L,j,j+1);			/* ����L->r[j]��L->r[j+1]��ֵ */
				flag=TRUE;				/* ��������ݽ�������flagΪtrue */
			}
		}
	}
}

/* ��˳���L����ѡ������ */
void SelectSort(SqList *L)
{
	int i,j,min;
	for(i=1;i<L->length;i++)
	{ 
		min = i;						/* ����ǰ�±궨��Ϊ��Сֵ�±� */
		for (j = i+1;j<=L->length;j++)	/* ѭ��֮������� */
        {
			if (L->r[min]>L->r[j])		/* �����С�ڵ�ǰ��Сֵ�Ĺؼ��� */
                min = j;				/* ���˹ؼ��ֵ��±긳ֵ��min */
        }
		if(i!=min)						/* ��min������i��˵���ҵ���Сֵ������ */
			swap(L,i,min);				/* ����L->r[i]��L->r[min]��ֵ */
	}
}

void InsertSort(SqList *L) 			/* ��˳���L��ֱ�Ӳ������� */
{ 
	int i,j;
	for(i=2;i<=L->length;i++)
	{
		if (L->r[i]<L->r[i-1]) 		/* �轫L->r[i]���������ӱ� */
		{
			L->r[0]=L->r[i]; 		/* �����ڱ� */
			for(j=i-1;L->r[j]>L->r[0];j--)
				L->r[j+1]=L->r[j]; 	/* ��¼���� */
			L->r[j+1]=L->r[0]; 		/* ���뵽��ȷλ�� */
		}
	}
}

void ShellSort(SqList *L) 					/* ��˳���L��ϣ������ */
{
	int i,j,k=0;
	int increment=L->length;
	do
	{
		increment=increment/3+1;			/* �������� */
		for(i=increment+1;i<=L->length;i++)
		{
			if (L->r[i]<L->r[i-increment])	/* �轫L->r[i]�������������ӱ� */ 
			{ 
				L->r[0]=L->r[i]; 			/* �ݴ���L->r[0] */
				for(j=i-increment;j>0 && L->r[0]<L->r[j];j-=increment)
					L->r[j+increment]=L->r[j]; /*  ��¼���ƣ����Ҳ���λ�� */
				L->r[j+increment]=L->r[0]; 	/*  ���� */
			}
		}
	}
	while(increment>1);
}



void HeapSort(SqList *L)		/* ��˳���L���ж����� */
{
	int i;
	for(i=L->length/2;i>0;i--) 	/* ��L�е�r������һ���󶥶� */
		HeapAdjust(L,i,L->length);
	for(i=L->length;i>1;i--)
	{ 
		swap(L,1,i); 			/* ���Ѷ���¼�͵�ǰδ���������������һ��¼���� */
		HeapAdjust(L,1,i-1); 	/* ��L->r[1..i-1]���µ���Ϊ�󶥶� */
	}
}

void HeapAdjust(SqList *L,int s,int m)
{ /* ����������L->r[s]�Ĺؼ��֣�ʹL->r[s..m]��Ϊһ���󶥶� */
	int temp,j;
	temp=L->r[s];
	for(j=2*s;j<=m;j*=2) 	/* �عؼ��ֽϴ�ĺ��ӽ������ɸѡ */
	{
		if(j<m && L->r[j]<L->r[j+1])
			++j; 			/* jΪ�ؼ����нϴ�ļ�¼���±� */
		if(temp>=L->r[j])
			break; 			/* rcӦ������λ��s�� */
		L->r[s]=L->r[j];
		s=j;
	}
	L->r[s]=temp; 			/* ���� */
}

/* ��˳���L���鲢���� */
void MergeSort(SqList *L)
{ 
 	MSort(L->r,L->r,1,L->length);
}

/* ��SR[s..t]�鲢����ΪTR1[s..t] */
void MSort(int SR[],int TR1[],int s, int t)
{
	int m;
	int TR2[MAXSIZE+1];
	if(s==t)
		TR1[s]=SR[s];
	else
	{
		m=(s+t)/2;				/* ��SR[s..t]ƽ��ΪSR[s..m]��SR[m+1..t] */
		MSort(SR,TR2,s,m);		/* �ݹ�ؽ�SR[s..m]�鲢Ϊ�����TR2[s..m] */
		MSort(SR,TR2,m+1,t);	/* �ݹ�ؽ�SR[m+1..t]�鲢Ϊ�����TR2[m+1..t] */
		Merge(TR2,TR1,s,m,t);	/* ��TR2[s..m]��TR2[m+1..t]�鲢��TR1[s..t] */
	}
}


void Merge(int SR[],int TR[],int i,int m,int n)
{ /* �������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n] */
	int j,k,l;
	for(j=m+1,k=i;i<=m && j<=n;k++)	/* ��SR�м�¼��С����ز���TR */
	{
		if (SR[i]<SR[j])
			TR[k]=SR[i++];
		else
			TR[k]=SR[j++];
	}
	if(i<=m)
	{
		for(l=0;l<=m-i;l++)
			TR[k+l]=SR[i+l];		/* ��ʣ���SR[i..m]���Ƶ�TR */
	}
	if(j<=n)
	{
		for(l=0;l<=n-j;l++)
			TR[k+l]=SR[j+l];		/* ��ʣ���SR[j..n]���Ƶ�TR */
	}
}


void MergeSort2(SqList *L) 				 /* ��˳���L���鲢�ǵݹ����� */
{
	int* TR=(int*)malloc(L->length * sizeof(int));	/* �������ռ� */
    int k=1;
	while(k<L->length)
	{
		MergePass(L->r,TR,k,L->length);
		k=2*k;										/* �����г��ȼӱ� */
		MergePass(TR,L->r,k,L->length);
		k=2*k;										/* �����г��ȼӱ� */       
	}
}


void MergePass(int SR[],int TR[],int s,int n)
{/* ��SR[]�����ڳ���Ϊs�������������鲢��TR[] */
	int i=1;
	int j;
	while(i <= n-2*s+1)					/* �����鲢 */
	{
		Merge(SR,TR,i,i+s-1,i+2*s-1);
		i=i+2*s;        
	}
	if(i<n-s+1) 						/* �鲢����������� */
		Merge(SR,TR,i,i+s-1,n);
	else 								/* �����ֻʣ�µ��������� */
		for(j =i;j <= n;j++)
			TR[j] = SR[j];
}

/* ��˳���L���������� */
void QuickSort(SqList *L)
{ 
	QSort(L,1,L->length);
}

/* ��˳���L�е�������L->r[low..high]���������� */
void QSort(SqList *L,int low,int high)
{ 
	int pivot;
	if(low<high)
	{
		/* ��L->r[low..high]һ��Ϊ�����������ֵpivot */
		pivot=Partition(L,low,high); 
		QSort(L,low,pivot-1);		 /*  �Ե��ӱ�ݹ����� */
		QSort(L,pivot+1,high);		 /*  �Ը��ӱ�ݹ����� */
	}
}

int Partition(SqList *L,int low,int high)
{/* ����˳���L���ӱ�ļ�¼��ʹ�����¼��λ��������������λ�ã���ʱ����֮ǰ(��)������(С)������*/
	int pivotkey;

	pivotkey=L->r[low]; 	/* ���ӱ�ĵ�һ����¼�������¼ */
	while(low<high) 		/* �ӱ�����˽�������м�ɨ�� */
	{ 
		 while(low<high&&L->r[high]>=pivotkey)
			high--;
		 swap(L,low,high);	/* ���������¼С�ļ�¼�������Ͷ� */
		 while(low<high&&L->r[low]<=pivotkey)
			low++;
		 swap(L,low,high);	/* ���������¼��ļ�¼�������߶� */
	}
	return low; 			/* ������������λ�� */
}

int pivotkey;

int m = low + (high - low) / 2; 	/* ���������м��Ԫ�ص��±� */  
if (L->r[low]>L->r[high])			
	swap(L,low,high);				/* ����������Ҷ����ݣ���֤��˽�С */
if (L->r[m]>L->r[high])
	swap(L,high,m);					/* �����м����Ҷ����ݣ���֤�м��С */
if (L->r[m]>L->r[low])
	swap(L,m,low);					/* �����м���������ݣ���֤��˽�С */

/* ��ʱL.r[low]�Ѿ�Ϊ�������������������ؼ��ֵ��м�ֵ��*/

pivotkey=L->r[low]; 				/* ���ӱ�ĵ�һ����¼�������¼ */

/* ���������Ż��㷨 */
int Partition1(SqList *L,int low,int high)
{ 
	int pivotkey;

	int m = low + (high - low) / 2; /* ���������м��Ԫ�ص��±� */  
	if (L->r[low]>L->r[high])			
		swap(L,low,high);			/* ����������Ҷ����ݣ���֤��˽�С */
	if (L->r[m]>L->r[high])
		swap(L,high,m);				/* �����м����Ҷ����ݣ���֤�м��С */
	if (L->r[m]>L->r[low])
		swap(L,m,low);				/* �����м���������ݣ���֤��˽�С */
	
	pivotkey=L->r[low]; 			/* ���ӱ�ĵ�һ����¼�������¼ */
	L->r[0]=pivotkey;  				/* ������ؼ��ֱ��ݵ�L->r[0] */
	while(low<high) 				/*  �ӱ�����˽�������м�ɨ�� */
	{ 
		while(low<high&&L->r[high]>=pivotkey)
			high--;
		L->r[low]=L->r[high];		/* �����滻�����ǽ����ķ�ʽ���в��� */
		while(low<high&&L->r[low]<=pivotkey)
			low++;
		L->r[high]=L->r[low];		/* �����滻�����ǽ����ķ�ʽ���в��� */
	}
	L->r[low]=L->r[0];				/* ��������ֵ�滻��L.r[low] */
	return low; 					/* ������������λ�� */
}

#define MAX_LENGTH_INSERT_SORT 7 /* ���ڿ�������ʱ�ж��Ƿ�ѡ�ò���������ֵ */
/* ��˳���L�е�������L.r[low..high]���������� */
void QSort1(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		pivot=Partition1(L,low,high); 	/* ��L->r[low..high]һ��Ϊ�����������ֵpivot */
		QSort1(L,low,pivot-1);			/* �Ե��ӱ�ݹ����� */
		QSort1(L,pivot+1,high);			/* �Ը��ӱ�ݹ����� */
	}
	else
		InsertSort(L);					/* ��high-lowС�ڵ��ڳ���ʱ��ֱ�Ӳ������� */
}

/* β�ݹ� */
void QSort2(SqList *L,int low,int high)
{ 
	int pivot;
	if((high-low)>MAX_LENGTH_INSERT_SORT)
	{
		while(low<high)
		{
			pivot=Partition1(L,low,high); /* ��L->r[low..high]һ��Ϊ�����������ֵpivot */
			QSort2(L,low,pivot-1);		/* �Ե��ӱ�ݹ����� */
			low=pivot+1;				/* β�ݹ� */
		}
	}
	else
		InsertSort(L);					/* ��high-lowС�ڵ��ڳ���ʱ��ֱ�Ӳ������� */
}

