
/* ����˫�ױ�ʾ�����ṹ���� */
#define MAX_TREE_SIZE 100

typedef int TElemType;				/* �������������ͣ�Ŀǰ�ݶ�Ϊ���� */

typedef struct PTNode				/* ���ṹ */
{
	TElemType data;					/* ������� */
	int parent;						/* ˫��λ�� */
} PTNode;

typedef struct						/* ���ṹ */
{
	PTNode nodes[MAX_TREE_SIZE];	/* ������� */
	int r,n;						/* ����λ�úͽ���� */
} PTree;


/* ���ĺ��ӱ�ʾ���ṹ���� */
#define MAX_TREE_SIZE 100

typedef int TElemType;			/* �������������ͣ�Ŀǰ�ݶ�Ϊ���� */

typedef struct CTNode			/* ���ӽ�� */
{
	int child;	
	struct CTNode *next;	
} *ChildPtr;

typedef struct 					/* ��ͷ�ṹ */
{
	TElemType data;	
	ChildPtr firstchild;	
} CTBox;

typedef struct	     			/* ���ṹ */
{
	CTBox nodes[MAX_TREE_SIZE];	/* ������� */
	int r,n;					/* ����λ�úͽ���� */
} CTree;



/* ���ĺ����ֵܱ�ʾ���ṹ���� */
typedef struct CSNode
{
	TElemType data;	
	struct CSNode *firstchild,*rightsib;	
} CSNode,*CSTree;



/* �������Ķ���������ṹ���� */
typedef struct BiTNode  			/* ���ṹ */
{
   TElemType data;					/* ������� */
   struct BiTNode *lchild,*rchild; 	/* ���Һ���ָ�� */
}BiTNode,*BiTree;


/* ��������ǰ������ݹ��㷨 */
/* ��ʼ����: ������T���� */
/* �������: ǰ��ݹ����T */
void PreOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	printf("%c",T->data);		/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
	PreOrderTraverse(T->lchild);/* ��������������� */
	PreOrderTraverse(T->rchild);/* ���������������� */
}

/* ����������������ݹ��㷨 */
/* ��ʼ����: ������T���� */
/* �������: ����ݹ����T */
void InOrderTraverse(BiTree T)
{ 
	if(T==NULL)
		return;
	InOrderTraverse(T->lchild); /* ������������� */
	printf("%c",T->data);		/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
	InOrderTraverse(T->rchild); /* ���������������� */
}

/* �������ĺ�������ݹ��㷨 */
/* ��ʼ����: ������T���� */
/* �������: ����ݹ����T */
void PostOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	PostOrderTraverse(T->lchild); 	/* �Ⱥ������������  */
	PostOrderTraverse(T->rchild); 	/* �ٺ������������  */
	printf("%c",T->data);			/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
}

/* ��ǰ������������н���ֵ��һ���ַ��� */
/* #��ʾ������������������ʾ������T�� */
void CreateBiTree(BiTree *T)
{ 
	TElemType ch;
	
	scanf("%c",&ch);
	ch=str[index++];

	if(ch=='#') 
		*T=NULL;
	else
	{
		*T=(BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data=ch; 					/* ���ɸ���� */
		CreateBiTree(&(*T)->lchild); 	/* ���������� */
		CreateBiTree(&(*T)->rchild); 	/* ���������� */
	}
}

/* �������Ķ��������洢�ṹ���� */
typedef char TElemType;
typedef enum {Link,Thread} PointerTag;	/* Link=0��ʾָ�����Һ���ָ��, */
										/* Thread=1��ʾָ��ǰ�����̵����� */
typedef  struct BiThrNode				/* ���������洢���ṹ */
{
	TElemType data;						/* ������� */
	struct BiThrNode *lchild, *rchild;	/* ���Һ���ָ�� */
	PointerTag LTag;
	PointerTag RTag;					/* ���ұ�־ */
} BiThrNode, *BiThrTree;


BiThrTree pre; 					/* ȫ�ֱ���,ʼ��ָ��ոշ��ʹ��Ľ�� */
/* ��������������������� */
void InThreading(BiThrTree p)
{ 
	if(p)
	{
		InThreading(p->lchild); /* �ݹ������������� */
		if(!p->lchild) 			/* û������ */
		{
			p->LTag=Thread; 	/* ǰ������ */
			p->lchild=pre; 		/* ����ָ��ָ��ǰ�� */
		}
		if(!pre->rchild) 		/* ǰ��û���Һ��� */
		{
			pre->RTag=Thread; 	/* ������� */
			pre->rchild=p; 		/* ǰ���Һ���ָ��ָ����(��ǰ���p) */
		}
		pre=p; 					/* ����preָ��p��ǰ�� */
		InThreading(p->rchild); /* �ݹ������������� */
	}
}













































































































































































































































































































































































































































































































































































































































































































































































































































































/* Tָ��ͷ��㣬ͷ�������lchildָ�����㣬ͷ�������rchildָ�����������*/
/* ���һ����㡣��������������������ʾ�Ķ�����T */
Status InOrderTraverse_Thr(BiThrTree T)
{ 
	BiThrTree p;
	p=T->lchild; 					/* pָ������ */
	while(p!=T)						/* �������������ʱ,p==T */
	{ 
		while(p->LTag==Link)		/*��LTag==0ʱѭ�����������е�һ����� */
			p=p->lchild;
		printf��"%c",p->data��; 		/* ��ʾ������ݣ����Ը���Ϊ�����Խ����� */
		while(p->RTag==Thread && p->rchild!=T)
		{
			p=p->rchild;
			printf��"%c",p->data��;	/* ���ʺ�̽�� */
		}
		p=p->rchild;				/*  p�������������� */
	}
	return OK;
}


if ��a<60��
	b=��������;
else if ��a<70��
	b=������;
else if ��a<80��
	b=���еȣ�;
else if ��a<90��
	b=�����ã�;
else 
	b=�����㣢;



