typedef int SElemType; 	/* SElemType���͸���ʵ������������������Ϊint */

/* ˳��ջ�ṹ */
typedef struct
{
        SElemType data[MAXSIZE];
        int top; 		/* ����ջ��ָ�� */
}SqStack;

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(SqStack *S,SElemType e)
{
    if(S->top == MAXSIZE -1) 	/* ջ�� */
    {
    	return ERROR;
    }
    S->top++;					/* ջ��ָ������һ */
    S->data[S->top]=e;  		/* ���²���Ԫ�ظ�ֵ��ջ���ռ� */
    return OK;
}

/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
Status Pop(SqStack *S,SElemType *e)
{ 
    if(S->top==-1)
    	return ERROR;
    *e=S->data[S->top];		/* ��Ҫɾ����ջ��Ԫ�ظ�ֵ��e */
    S->top--;				/* ջ��ָ���һ */
    return OK;
}

/* ��ջ����ռ�ṹ */
typedef struct 
{
        SElemType data[MAXSIZE];
        int top1;	/* ջ1ջ��ָ�� */
        int top2;	/* ջ2ջ��ָ�� */
}SqDoubleStack;

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(SqDoubleStack *S,SElemType e,int stackNumber)
{
    if (S->top1+1==S->top2)		/* ջ������������push��Ԫ���� */
    	return ERROR;	
    if (stackNumber==1)			/* ջ1��Ԫ�ؽ�ջ */
        S->data[++S->top1]=e; 	/* ����ջ1����top1+1�������Ԫ�ظ�ֵ�� */
    else if (stackNumber==2)	/* ջ2��Ԫ�ؽ�ջ */
        S->data[--S->top2]=e; 	/* ����ջ2����top2-1�������Ԫ�ظ�ֵ�� */
    return OK;
}

/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
Status Pop(SqDoubleStack *S,SElemType *e,int stackNumber)
{ 
    if (stackNumber==1) 
    {
        if (S->top1==-1) 
            return ERROR; 		/* ˵��ջ1�Ѿ��ǿ�ջ����� */
        *e=S->data[S->top1--]; 	/* ��ջ1��ջ��Ԫ�س�ջ */
    }
    else if (stackNumber==2)
    { 
        if (S->top2==MAXSIZE) 
            return ERROR; 		/* ˵��ջ2�Ѿ��ǿ�ջ����� */
        *e=S->data[S->top2++]; 	/* ��ջ2��ջ��Ԫ�س�ջ */
    }
    return OK;
}

/* ��ջ�ṹ */
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;


typedef struct
{
    LinkStackPtr top;
    int count;
}LinkStack;

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(LinkStack *S,SElemType e)
{
    LinkStackPtr s=(LinkStackPtr)malloc(sizeof(StackNode)); 
    s->data=e; 
    s->next=S->top;	/* �ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ�̣���ͼ�Т� */
    S->top=s;  		/* ���µĽ��s��ֵ��ջ��ָ�룬��ͼ�Т� */
    S->count++;
    return OK;
}

/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
Status Pop(LinkStack *S,SElemType *e)
{ 
    LinkStackPtr p;
    if(StackEmpty(*S))
    	return ERROR;
    *e=S->top->data;
    p=S->top;				/* ��ջ����㸳ֵ��p����ͼ�Т� */
    S->top=S->top->next;    /* ʹ��ջ��ָ������һλ��ָ���һ��㣬��ͼ�Т� */
    free(p);                /* �ͷŽ��p */        
    S->count--;
    return OK;
}

int main()
{
	int i;
	int a[40];  
	a[0]=0;
	a[1]=1;
	printf("%d ",a[0]);  
	printf("%d ",a[1]);  
	for(i = 2;i < 40;i++)  
	{ 
		a[i] = a[i-1] + a[i-2];  
		printf("%d ",a[i]);  
	} 
    return 0;
}

/* 쳲������ĵݹ麯�� */
int Fbi(int i)  
{
	if( i < 2 )
		return i == 0 ? 0 : 1;  
    return Fbi(i-1)+Fbi(i-2);  /* ����Fbi���Ǻ����Լ��������ڵ����Լ� */
}  

int main()
{
	int i;
	printf("�ݹ���ʾ쳲��������У�\n");
	for(i = 0;i < 40;i++)  
		printf("%d ", Fbi(i));  
    return 0;
}

typedef int QElemType; 	/* QElemType���͸���ʵ������������������Ϊint */
/* ѭ�����е�˳��洢�ṹ */
typedef struct
{
	QElemType data[MAXSIZE];
	int front;    		/* ͷָ�� */
	int rear;			/* βָ�룬�����в��գ�ָ�����βԪ�ص���һ��λ�� */
}SqQueue;

/* ��ʼ��һ���ն���Q */
Status InitQueue(SqQueue *Q)
{
	Q->front=0;
	Q->rear=0;
	return  OK;
}

/* ����Q��Ԫ�ظ�����Ҳ���Ƕ��еĵ�ǰ���� */
int QueueLength(SqQueue Q)
{
	return  (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}

/* ������δ���������Ԫ��eΪQ�µĶ�βԪ�� */
Status EnQueue(SqQueue *Q,QElemType e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front)	/* ���������ж� */
		return ERROR;
	Q->data[Q->rear]=e;						/* ��Ԫ��e��ֵ����β */
	Q->rear=(Q->rear+1)%MAXSIZE;			/* rearָ�������һλ�ã� */
											/* ���������ת������ͷ�� */
	return  OK;
}

/* �����в��գ���ɾ��Q�ж�ͷԪ�أ���e������ֵ */
Status DeQueue(SqQueue *Q,QElemType *e)
{
	if (Q->front == Q->rear)			/* ���пյ��ж� */
		return ERROR;
	*e=Q->data[Q->front];				/* ����ͷԪ�ظ�ֵ��e */
	Q->front=(Q->front+1)%MAXSIZE;		/* frontָ�������һλ�ã� */
										/* ���������ת������ͷ�� */
	return  OK;
}

typedef int QElemType; 	/* QElemType���͸���ʵ������������������Ϊint */

typedef struct QNode	/* ���ṹ */
{
   QElemType data;
   struct QNode *next;
}QNode,*QueuePtr;

typedef struct			/* ���е�����ṹ */
{
   QueuePtr front,rear; /* ��ͷ����βָ�� */
}LinkQueue;

/* ����Ԫ��eΪQ���µĶ�βԪ�� */
Status EnQueue(LinkQueue *Q,QElemType e)
{ 
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) 				/* �洢����ʧ�� */
		exit(OVERFLOW);
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;	/* ��ӵ��Ԫ��e���½��s��ֵ��ԭ��β���ĺ�̣���ͼ�Т� */
	Q->rear=s;			/* �ѵ�ǰ��s����Ϊ��β��㣬rearָ��s����ͼ�Т� */
	return OK;
}

/* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR */
Status DeQueue(LinkQueue *Q,QElemType *e)
{
	QueuePtr p;
	if(Q->front==Q->rear)
		return ERROR;
	p=Q->front->next;		/* ����ɾ���Ķ�ͷ����ݴ��p����ͼ�Т� */
	*e=p->data;				/* ����ɾ���Ķ�ͷ����ֵ��ֵ��e */
	Q->front->next=p->next;	/* ��ԭ��ͷ���ĺ��p->next��ֵ��ͷ����̣���ͼ�Т� */
	if(Q->rear==p)			/* ����ͷ���Ƕ�β����ɾ����rearָ��ͷ��㣬��ͼ�Т� */
		Q->rear=Q->front;
	free(p);
	return OK;
}


