Status ListInsert(StaticLinkList L, int i, ElemType e)   
{  
	int j, k, l;   
	k = MAXSIZE - 1;   					/* ע��k���������һ��Ԫ�ص��±� */
	if (i < 1 || i > ListLength(L) + 1)   
		return ERROR;   
	j = Malloc_SSL(L);   				/* ��ÿ��з������±� */
	if (j)   
	{   
		L[j].data = e;   				/* �����ݸ�ֵ���˷�����data */
		for(l = 1; l <= i - 1; l++)   	/* �ҵ���i��Ԫ��֮ǰ��λ�� */
		   k = L[k].cur;           
		L[j].cur = L[k].cur;    		/* �ѵ�i��Ԫ��֮ǰ��cur��ֵ����Ԫ�ص�cur */
		L[k].cur = j;           		/* ����Ԫ�ص��±긳ֵ����i��Ԫ��֮ǰԪ�ص�ur */
		return OK;   
	}   
	return ERROR;   
}

/*�����е������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��*/
void unionL(SqList *La,SqList Lb)
{
	int La_len,Lb_len,i;
	ElemType e;                        /*������La��Lb��ͬ������Ԫ��e*/
	La_len=ListLength(*La);            /*�����Ա�ĳ��� */
	Lb_len=ListLength(Lb);
	for (i=1;i<=Lb_len;i++)
	{
		GetElem(Lb,i,&e);              /*ȡLb�е�i������Ԫ�ظ���e*/
		if (!LocateElem(*La,e))        /*La�в����ں�e��ͬ����Ԫ��*/
			ListInsert(La,++La_len,e); /*����*/
	}
}



#define MAXSIZE 20          /* �洢�ռ��ʼ������ */
typedef int ElemType;       /* ElemType���͸���ʵ���������������Ϊint */
typedef struct
{
	ElemType data[MAXSIZE]; /* ���飬�洢����Ԫ�� */
	int length;             /* ���Ա�ǰ���� */
}SqList;


#define OK 1
#define ERROR 0
/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int Status;         

/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ��ע��i��ָλ�ã���1��λ�õ������Ǵ�0��ʼ */
Status GetElem(SqList L,int i,ElemType *e)
{
	if(L.length==0 || i<1 || i>L.length)
		return ERROR;
	*e=L.data[i-1];

	return OK;
}

/* ��ʼ������˳�����Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status ListInsert(SqList *L,int i,ElemType e)
{ 
	int k;
	if (L->length==MAXSIZE)  			/* ˳�����Ա��Ѿ��� */
		return ERROR;
	if (i<1 || i>L->length+1)			/* ��i�ȵ�һλ��С���߱����һλ�ú�һλ�û�Ҫ��ʱ */
		return ERROR;				

	if (i<=L->length)        			/* ����������λ�ò��ڱ�β */
	{
		for(k=L->length-1;k>=i-1;k--)  	/* ��Ҫ����λ�ú��Ԫ�������һλ */
			L->data[k+1]=L->data[k];
	}
	L->data[i-1]=e;          			/* ����Ԫ�ز��� */
	L->length++;

	return OK;
}


/* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(SqList *L,int i,ElemType *e) 
{ 
	int k;
	if (L->length==0)               /* ���Ա�Ϊ�� */
		return ERROR;
	if (i<1 || i>L->length)         /* ɾ��λ�ò���ȷ */
		return ERROR;
	*e=L->data[i-1];
	if (i<L->length)                /* ���ɾ���������λ�� */
	{
		for(k=i;k<L->length;k++)	/* ��ɾ��λ�ú��Ԫ��ǰ�� */
			L->data[k-1]=L->data[k];
	}
	L->length--;
	return OK;
}

/* ���Ա�ĵ�����洢�ṹ */
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node;
typedef struct Node *LinkList; /* ����LinkList */


/* ��ʼ��������ʽ���Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* �����������e����L�е�i������Ԫ�ص�ֵ */
Status GetElem(LinkList L,int i,ElemType *e)
{
	int j;
	LinkList p;		/* ����һ���p */
	p = L->next;		/* ��pָ������L�ĵ�һ����� */
	j = 1;		/*  jΪ������ */
	while (p && j<i)  /* p��Ϊ�ջ��߼�����j��û�е���iʱ��ѭ������ */
	{   
		p = p->next;  /* ��pָ����һ����� */
		++j;
	}
	if ( !p || j>i ) 
		return ERROR;  /*  ��i��Ԫ�ز����� */
	*e = p->data;   /*  ȡ��i��Ԫ�ص����� */
	return OK;
}


s->next = p->next;    /* ��p�ĺ�̽�㸳ֵ��s�ĺ��  */
p->next = s;          /* ��s��ֵ��p�ĺ�� */


/* ��ʼ��������ʽ���Ա�L�Ѵ���,1��i��ListLength(L)�� */
/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status ListInsert(LinkList *L,int i,ElemType e)
{ 
	int j;
	LinkList p,s;
	p = *L;   
	j = 1;
	while (p && j < i)     				/* Ѱ�ҵ�i����� */
	{
		p = p->next;
		++j;
	} 
	if (!p || j > i) 
		return ERROR;   				/* ��i��Ԫ�ز����� */

	s = (LinkList)malloc(sizeof(Node)); /* �����½��(C���Ա�׼����) */
	s->data = e;  
	s->next = p->next;    				/* ��p�ĺ�̽�㸳ֵ��s�ĺ�� */
	p->next = s;          				/* ��s��ֵ��p�ĺ�� */
	return OK;
}

q = p->next;
p->next = q->next;			/* ��q�ĺ�̸�ֵ��p�ĺ�� */


/* ��ʼ��������ʽ���Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(LinkList *L,int i,ElemType *e) 
{ 
	int j;
	LinkList p,q;
	p = *L;
	j = 1;
	while (p->next && j < i)	/* ����Ѱ�ҵ�i��Ԫ�� */
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i) 
		return ERROR;           /* ��i��Ԫ�ز����� */
	q = p->next;
	p->next = q->next;			/* ��q�ĺ�̸�ֵ��p�ĺ�� */
	*e = q->data;               /* ��q����е����ݸ�e */
	free(q);                    /* ��ϵͳ���մ˽�㣬�ͷ��ڴ� */
	return OK;
}

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��ͷ�巨�� */
void CreateListHead(LinkList *L, int n) 
{
	LinkList p;
	int i;
	srand(time(0));                         /* ��ʼ����������� */
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;                      /* �Ƚ���һ����ͷ���ĵ����� */
	for (i=0; i<n; i++) 
	{
		p = (LinkList)malloc(sizeof(Node)); /* �����½�� */
		p->data = rand()%100+1;             /* �������100���ڵ����� */
		p->next = (*L)->next;    
		(*L)->next = p;						/* ���뵽��ͷ */
	}
}

/*  �������n��Ԫ�ص�ֵ����������ͷ���ĵ������Ա�L��β�巨�� */
void CreateListTail(LinkList *L, int n) 
{
	LinkList p,r;
	int i;
	srand(time(0));                     	/* ��ʼ����������� */
	*L = (LinkList)malloc(sizeof(Node)); 	/* LΪ�������Ա� */
	r=*L;                                	/* rΪָ��β���Ľ�� */
	for (i=0; i<n; i++) 
	{
		p = (Node *)malloc(sizeof(Node)); 	/* �����½�� */
		p->data = rand()%100+1;           	/* �������100���ڵ����� */
		r->next=p;                        	/* ����β�ն˽���ָ��ָ���½�� */
		r = p;                            	/* ����ǰ���½�㶨��Ϊ��β�ն˽�� */
	}
	r->next = NULL;                       	/* ��ʾ��ǰ������� */
}


/* ��ʼ��������ʽ���Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
Status ClearList(LinkList *L)
{ 
	LinkList p,q;
	p=(*L)->next;           /*  pָ���һ����� */
	while(p)                /*  û����β */
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*L)->next=NULL;        /* ͷ���ָ����Ϊ�� */
	return OK;
}


#define MAXSIZE 1000 	/* �洢�ռ��ʼ������ */

/* ���Ա�ľ�̬����洢�ṹ */
typedef struct 
{
	ElemType data;
	int cur;  			/* �α�(Cursor) ��Ϊ0ʱ��ʾ��ָ�� */
} Component,StaticLinkList[MAXSIZE];



/* ��һά����space�и���������һ����������space[0].curΪͷָ�룬"0"��ʾ��ָ�� */
Status InitList(StaticLinkList space) 
{
	int i;
	for (i=0; i<MAXSIZE-1; i++)  
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0; 	/* Ŀǰ��̬����Ϊ�գ����һ��Ԫ�ص�curΪ0 */
	return OK;
}

/* �����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬���򷵻�0 */
int Malloc_SSL(StaticLinkList space) 
{ 
	int i = space[0].cur;           		/* ��ǰ�����һ��Ԫ�ص�cur���ֵ */
											/* ����Ҫ���صĵ�һ�����ÿ��е��±� */
	if (space[0]. cur)         
		space[0]. cur = space[i].cur;       /* ����Ҫ�ó�һ��������ʹ���ˣ� */
											/* �������Ǿ͵ð�������һ�� */
											/* �������������� */
	return i;
}

/*  ɾ����L�е�i������Ԫ��   */
Status ListDelete(StaticLinkList L, int i)   
{ 
	int j, k;   
	if (i < 1 || i > ListLength(L))   
		return ERROR;   
	k = MAXSIZE - 1;   
	for (j = 1; j <= i - 1; j++)   
		k = L[k].cur;   
	j = L[k].cur;   
	L[k].cur = L[j].cur;   
	Free_SSL(L, j);   
	return OK;   
} 

/*  ���±�Ϊk�Ŀ��н����յ��������� */
void Free_SSL(StaticLinkList space, int k) 
{  
	space[k].cur = space[0].cur;    /* �ѵ�һ��Ԫ�ص�curֵ����Ҫɾ���ķ���cur */
	space[0].cur = k;               /* ��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص�cur */
}

/* ��ʼ��������̬����L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
int ListLength(StaticLinkList L)
{
	int j=0;
	int i=L[MAXSIZE-1].cur;
	while(i)
	{
		i=L[i].cur;
		j++;
	}
	return j;
}

p=rearA->next;   			    /* ����A���ͷ��㣬���� */
rearA->next=rearB->next->next;	/* ������ָ��B��ĵ�һ����㣨����ͷ��㣩*/
                 				/* ��ֵ��reaA->next������ */
q=rearB->next;
rearB->next=p;				   	/* ��ԭA���ͷ��㸳ֵ��rearB->next������ */
free��q��;					   	/* �ͷ�q */



/*���Ա��˫������洢�ṹ*/
typedef struct DulNode
{
		ElemType data;
		struct DuLNode *prior;    	/*ֱ��ǰ��ָ��*/
		struct DuLNode *next;		/*ֱ�Ӻ��ָ��*/
} DulNode, *DuLinkList;


p->next->prior = p = p->prior->next

s - >prior = p;   			/*��p��ֵ��s��ǰ������ͼ�Т�*/
s -> next = p -> next;		/*��p->next��ֵ��s�ĺ�̣���ͼ�Т�*/
p -> next -> prior = s;		/*��s��ֵ��p->next��ǰ������ͼ�Т�*/
p -> next = s;				/*��s��ֵ��p�ĺ�̣���ͼ�Т�*/


p->prior->next=p->next;   	/*��p->next��ֵ��p->prior�ĺ�̣���ͼ�Т�*/
p->next->prior=p->prior;	/*��p->prior��ֵ��p->next��ǰ������ͼ�Т�*/
free��p��;					/*�ͷŽ��*/














































































































































































































































































































































































































































































































































































































































































































































































