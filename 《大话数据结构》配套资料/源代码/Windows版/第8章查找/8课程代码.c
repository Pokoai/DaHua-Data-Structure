Status InsertAVL(BiTree *T,int e,Status *taller)
{  
	if(!*T)						/* �����½�㣬�������ߡ�����tallerΪTRUE */ 
	{ 
		*T=(BiTree)malloc(sizeof(BiTNode));
		(*T)->data=e; 
		(*T)->lchild=(*T)->rchild=NULL; 
		(*T)->bf=EH;
		*taller=TRUE;
	}
	else
	{
		if (e==(*T)->data)		/* �����Ѵ��ں�e����ͬ�ؼ��ֵĽ�����ٲ��� */
		{  
			*taller=FALSE; 
			return FALSE;
		}
		if (e<(*T)->data)		/* Ӧ������T���������н������� */
		{  
			if(!InsertAVL(&(*T)->lchild,e,taller)) /*  δ���� */ 
				return FALSE;
			if(*taller) 		/* �Ѳ��뵽T�����������������������ߡ� */ 
			{
				switch((*T)->bf)/* ���T��ƽ��� */ 
				{
					case LH: 	/* ԭ�����������������ߣ���Ҫ����ƽ�⴦�� */ 
						LeftBalance(T);	
						*taller=FALSE; 
						break;
					case EH: 	/* ԭ�����������ȸߣ��������������߶�ʹ������ */ 
						(*T)->bf=LH; 
						*taller=TRUE; 
						break;
					case RH: 	/* ԭ�����������������ߣ������������ȸ� */  
						(*T)->bf=EH; 
						*taller=FALSE; 
						break;
				}
			}
		}
		else					/*  Ӧ������T���������н������� */ 
		{ 
			if(!InsertAVL(&(*T)->rchild,e,taller)) /* δ���� */ 
				return FALSE;
			if(*taller) 		/* �Ѳ��뵽T���������������������ߡ� */ 
			{
				switch((*T)->bf)/* ���T��ƽ��� */ 
				{
					case LH: 	/* ԭ�����������������ߣ������������ȸ� */ 
						(*T)->bf=EH; 
						*taller=FALSE;	
						break;
					case EH: 	/* ԭ�����������ȸߣ��������������߶�ʹ������ */
						(*T)->bf=RH; 
						*taller=TRUE; 
						break;
					case RH: 	/* ԭ�����������������ߣ���Ҫ����ƽ�⴦�� */ 
						RightBalance(T); 
						*taller=FALSE; 
						break;
				}
			}
		}
	}
	return TRUE;
}

void LeftBalance(BiTree *T)
{ 
	BiTree L,Lr;
	L=(*T)->lchild; 					/* Lָ��T������������� */ 
	switch(L->bf)		/* ���T����������ƽ��ȣ�������Ӧƽ�⴦�� */ 
	{ 
		 case LH:     	/* �½�������T�����ӵ��������ϣ�Ҫ������������ */ 
			(*T)->bf=L->bf=EH;
			R_Rotate(T);
			break;
		 case RH:     	/* �½�������T�����ӵ��������ϣ�Ҫ��˫������ */ 
			Lr=L->rchild; 				/* Lrָ��T�����ӵ��������� */ 
			switch(Lr->bf)				/* �޸�T�������ӵ�ƽ������ */ 
			{ 							
				case LH: (*T)->bf=RH;
						 L->bf=EH;
						 break;
				case EH: (*T)->bf=L->bf=EH;
						 break;
				case RH: (*T)->bf=EH;
						 L->bf=LH;
						 break;
			}
			Lr->bf=EH;
			L_Rotate(&(*T)->lchild); 	/* ��T��������������ƽ�⴦�� */ 
			R_Rotate(T); 				/* ��T������ƽ�⴦�� */ 
	}
}

Status Delete(BiTree *p)
{/* �Ӷ�����������ɾ�����p�����ؽ���������������� */
	BiTree q,s;
	if((*p)->rchild==NULL) /* ����������ֻ���ؽ���������������ɾ�����Ҷ��Ҳ�ߴ˷�֧) */
	{
		q=*p; *p=(*p)->lchild; free(q);
	}
	else if((*p)->lchild==NULL) /* ֻ���ؽ����������� */
	{
		q=*p; *p=(*p)->rchild; free(q);
	}
	else 						/* �������������� */
	{
		q=*p; s=(*p)->lchild;
		while(s->rchild) 		/* ת��Ȼ�����ҵ���ͷ���Ҵ�ɾ����ǰ����*/
		{
			q=s; s=s->rchild;
		}
		(*p)->data=s->data; /* sָ��ɾ���ֱ��ǰ��(����ɾ���ǰ����ֵȡ����ɾ����ֵ) */
		if(q!=*p)
			q->rchild=s->lchild;/*  �ؽ�q�������� */ 
		else
			q->lchild=s->lchild;/*  �ؽ�q�������� */
		free(s);
	}
	return TRUE;
}

Status DeleteBST(BiTree *T,int key)
{/* ������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ�������ݽ�� */
	if(!*T) 					/* �����ڹؼ��ֵ���key������Ԫ�� */ 
		return FALSE;
	else
	{
		if (key==(*T)->data) 	/* �ҵ��ؼ��ֵ���key������Ԫ�� */ 
			return Delete(T);
		else if (key<(*T)->data)
			return DeleteBST(&(*T)->lchild,key);
		else
			return DeleteBST(&(*T)->rchild,key);
		 
	}
}

Status SearchBST(BiTree T, int key, BiTree f, BiTree *p) 
{ /* �ݹ���Ҷ���������T���Ƿ����key, */ 
	if (!T)		/* �����Ҳ��ɹ���ָ��pָ�����·���Ϸ��ʵ����һ����㲢����FALSE */
	{ 
		*p = f;  
		return FALSE; 
	}
	else if (key==T->data) /* �����ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE */
	{ 
		*p = T;  
		return TRUE; 
	} 
	else if (key<T->data) 
		return SearchBST(T->lchild, key, T, p);  	/* ���������м������� */
	else  
		return SearchBST(T->rchild, key, T, p);  	/* ���������м������� */
}

int Fibonacci_Search(int *a,int n,int key) /* 쳲��������� */
{
	int low,high,mid,i,k;
	low=1;						/* ��������±�Ϊ��¼��λ */
	high=n;						/* ��������±�Ϊ��¼ĩλ */
	k=0;
	while(n>F[k]-1)				/* ����nλ��쳲��������е�λ�� */
		k++;
	for (i=n;i<F[k]-1;i++)		/* ����������ֵ��ȫ */
		a[i]=a[n];
	while(low<=high)
	{
		mid=low+F[k-1]-1;		/* ���㵱ǰ�ָ����±� */
		if (key<a[mid])			/* �����Ҽ�¼С�ڵ�ǰ�ָ���¼ */
		{
			high=mid-1;			/* ����±�������ָ��±�mid-1�� */
			k=k-1;				/* 쳲����������±��һλ */
		}
		else if (key>a[mid])	/* �����Ҽ�¼���ڵ�ǰ�ָ���¼ */
		{
			low=mid+1;			/* ����±�������ָ��±�mid+1�� */
			k=k-2;				/* 쳲����������±����λ */
		}
		else
		{
			if (mid<=n)
				return mid;		/* �������˵��mid��Ϊ���ҵ���λ�� */
			else 
				return n;		/* ��mid>n˵���ǲ�ȫ��ֵ������n */
		}
	}
	return 0;
}

/* ˳����ң�aΪ���飬nΪҪ���ҵ����������keyΪҪ���ҵĹؼ��� */
int Sequential_Search(int *a,int n,int key)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if (a[i]==key)
			return i;
	}
	return 0;
}

/* ���ڱ�˳����� */
int Sequential_Search2(int *a,int n,int key)
{
	int i;
	a[0]=key;			/* ����a[0]Ϊ�ؼ���ֵ�����ǳ�֮Ϊ���ڱ���*/
	i=n;				/* ѭ��������β����ʼ */
	while(a[i]!=key)
	{
		i--;
	}
	return i;			/* ����0��˵������ʧ�� */
}

/* �۰���� */
int Binary_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;					/* ��������±�Ϊ��¼��λ */
	high=n;					/* ��������±�Ϊ��¼ĩλ */
	while(low<=high)
	{
		mid=(low+high)/2;	/* �۰� */
		if (key<a[mid])		/* ������ֵ����ֵС */
			high=mid-1;		/* ����±��������λ�±�Сһλ */
		else if (key>a[mid])/* ������ֵ����ֵ�� */
			low=mid+1;		/* ����±��������λ�±��һλ */
		else
		{
			return mid;		/* �������˵��mid��Ϊ���ҵ���λ�� */
		}
	}
	return 0;
}

/* ��ֵ���� */
int Interpolation_Search(int *a,int n,int key)
{
	int low,high,mid;
	low=1;	/* ��������±�Ϊ��¼��λ */
	high=n;	/* ��������±�Ϊ��¼ĩλ */
	while(low<=high)
	{
		mid=low+ (high-low)*(key-a[low])/(a[high]-a[low]); /* ��ֵ */
		if (key<a[mid])		/* ������ֵ�Ȳ�ֵС */
			high=mid-1;		/* ����±��������ֵ�±�Сһλ */
		else if (key>a[mid])/* ������ֵ�Ȳ�ֵ�� */
			low=mid+1;		/* ����±��������ֵ�±��һλ */
		else
			return mid;		/* �������˵��mid��Ϊ���ҵ���λ�� */
	}
	return 0;
}

/* �������Ķ���������ṹ���� */
typedef  struct BiTNode					/* ���ṹ */
{
	int data;							/* ������� */
	struct BiTNode *lchild, *rchild;	/* ���Һ���ָ�� */
} BiTNode, *BiTree;


Status InsertBST(BiTree *T, int key) 
{  
	BiTree p,s;
	if (!SearchBST(*T, key, NULL, &p)) 	/* ���Ҳ��ɹ� */
	{
		s = (BiTree)malloc(sizeof(BiTNode));
		s->data = key;  
		s->lchild = s->rchild = NULL;  
		if (!p) 
			*T = s;						/*  ����sΪ�µĸ���� */
		else if (key<p->data) 
			p->lchild = s;				/*  ����sΪ���� */
		else 
			p->rchild = s;  			/*  ����sΪ�Һ��� */
		return TRUE;
	} 
	else 
		return FALSE;  					/*  �������йؼ�����ͬ�Ľ�㣬���ٲ��� */
}


int i;
int a[10]={62,88,58,47,35,73,51,99,37,93};
BiTree T=NULL;
for(i=0;i<10;i++)
{
	InsertBST(&T, a[i]);
}



/* �������Ķ���������ṹ���� */
typedef  struct BiTNode					/* ���ṹ */
{
	int data;							/* ������� */
	int bf; 							/*  ����ƽ������ */ 
	struct BiTNode *lchild, *rchild;	/* ���Һ���ָ�� */
} BiTNode, *BiTree;


/* ����pΪ���Ķ������������������� */
/* ����֮��pָ���µ�������㣬����ת����֮ǰ���������ĸ���� */
void R_Rotate(BiTree *P)
{ 
	BiTree L;
	L=(*P)->lchild; 		/*  Lָ��P������������� */ 
	(*P)->lchild=L->rchild; /*  L���������ҽ�ΪP�������� */ 
	L->rchild=(*P);
	*P=L; 					/*  Pָ���µĸ���� */ 
}

/* ����PΪ���Ķ������������������� */
/* ����֮��Pָ���µ�������㣬����ת����֮ǰ���������ĸ����0  */
void L_Rotate(BiTree *P)
{ 
	BiTree R;
	R=(*P)->rchild; 		/*  Rָ��P������������� */ 
	(*P)->rchild=R->lchild; /* R���������ҽ�ΪP�������� */ 
	R->lchild=(*P);
	*P=R; 					/*  Pָ���µĸ���� */ 
}

#define LH +1 /*  ��� */ 
#define EH 0  /*  �ȸ� */ 
#define RH -1 /*  �Ҹ� */ 

/*  ����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת���� */
/*  ���㷨����ʱ��ָ��Tָ���µĸ���� */



/*  ����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת���� */ 
/*  ���㷨����ʱ��ָ��Tָ���µĸ���� */ 
void RightBalance(BiTree *T)
{ 
	BiTree R,Rl;
	R=(*T)->rchild; 					/* Rָ��T������������� */ 
	switch(R->bf)
	{ /* ���T����������ƽ��ȣ�������Ӧƽ�⴦�� */ 
	 case RH: /* �½�������T���Һ��ӵ��������ϣ�Ҫ������������ */ 
			  (*T)->bf=R->bf=EH;
			  L_Rotate(T);
			  break;
	 case LH: /* �½�������T���Һ��ӵ��������ϣ�Ҫ��˫������ */ 
			  Rl=R->lchild; 			/* Rlָ��T���Һ��ӵ��������� */ 
			  switch(Rl->bf)			/* �޸�T�����Һ��ӵ�ƽ������ */ 
			  { 						
				case RH: (*T)->bf=LH;
						 R->bf=EH;
						 break;
				case EH: (*T)->bf=R->bf=EH;
						 break;
				case LH: (*T)->bf=EH;
						 R->bf=RH;
						 break;
			  }
			  Rl->bf=EH;
			  R_Rotate(&(*T)->rchild); 	/* ��T��������������ƽ�⴦�� */ 
			  L_Rotate(T); 				/* ��T������ƽ�⴦�� */ 
	}
}



int i;
int a[10]={3,2,1,4,5,6,7,10,9,8};
BiTree T=NULL;
Status taller;
for(i=0;i<10;i++)
{
	InsertAVL(&T,a[i],&taller);
}


#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12 	/* ����ɢ�б�Ϊ����ĳ��� */
#define NULLKEY -32768 

typedef struct
{
   int *elem; 			/* ����Ԫ�ش洢��ַ����̬�������� */
   int count; 			/*  ��ǰ����Ԫ�ظ��� */
}HashTable;

int m=0; 				/* ɢ�б����ȫ�ֱ��� */

/* ��ʼ��ɢ�б� */
Status InitHashTable(HashTable *H)
{
	int i;
	m=HASHSIZE;
	H->count=m;
	H->elem=(int *)malloc(m*sizeof(int));
	for(i=0;i<m;i++)
		H->elem[i]=NULLKEY; 
	return OK;
}

/* ɢ�к��� */
int Hash(int key)
{
	return key % m; /* ���������� */
}

/* ����ؼ��ֽ�ɢ�б� */
void InsertHash(HashTable *H,int key)
{
	int addr = Hash(key); 				/* ��ɢ�е�ַ */
	while (H->elem[addr] != NULLKEY) 	/* �����Ϊ�գ����ͻ */
	{
		addr = (addr+1) % m; 			/* ���Ŷ�ַ��������̽�� */
	}
	H->elem[addr] = key; 				/* ֱ���п�λ�����ؼ��� */
}


/* ɢ�б���ҹؼ��� */
Status SearchHash(HashTable H,int key,int *addr)
{
	*addr = Hash(key);  									/* ��ɢ�е�ַ */
	while(H.elem[*addr] != key) 							/* �����Ϊ�գ����ͻ */
	{
		*addr = (*addr+1) % m; 								/* ���Ŷ�ַ��������̽�� */
		if (H.elem[*addr] == NULLKEY || *addr == Hash(key)) /* ���ѭ���ص�ԭ�� */
			return UNSUCCESS;								/* ��˵���ؼ��ֲ����� */
	}
	return SUCCESS;
}






