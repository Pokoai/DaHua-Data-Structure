// 数据结构

typedef int ElemType;

typedef struct node {
    ElemType data;
    struct node * next;
} Node;

typedef struct {
    Node * top;
    int length;
} LinkStack;

