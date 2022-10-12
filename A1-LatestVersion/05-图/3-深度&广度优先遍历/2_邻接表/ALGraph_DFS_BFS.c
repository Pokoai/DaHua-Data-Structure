/*
 * 功能: 图-邻接表的深度&广度优先遍历
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-10-01
 */


// 深度优先：类似于树的前序遍历
// 广度优先：类似于树的层序遍历（借助队列实现）



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "linkQueue.h"


/*---------------------------- 图-邻接表结构定义 -----------------------------*/

#define MAXVEX 100        // 最大顶点数

typedef char VertexType;  // 顶点数据类型
typedef int EdgeType;     // 边/弧权值数据类型

// 首先定义边表节点，后续顶点表节点需要用
typedef struct edgeNode {
    int adjvex;         // 存储某顶点的邻接点在顶点表中的下标
    EdgeType weight;    // 存储权值
    struct edgeNode * next;  
} EdgeNode;

// 定义顶点表节点
typedef struct vertexNode {
    VertexType data;
    EdgeNode * firstEdge;
} VertexNode;

// 有了顶点表节点构成的数组，即确定了邻接表
// 类似于有了头指针，即确定了链表一样
typedef VertexNode AdjList[MAXVEX];  // 在这里为顶点表分配了内存，就无需动态分配了

// 最终定义图的邻接表结构
typedef struct {
    AdjList adjList;
    int numVex, numEdge;
} ALGraph;

//上面可以改为：
// typedef struct {
//     VertexNode adjList[MAXVEX];
//     int numVex, numEdge;
// } ALGraph;

/*---------------------------- 图-邻接表结构定义 -----------------------------*/


bool visited[MAXVEX];  // 标记数组


// 函数前置声明
void CreateALGraph(ALGraph *G);
static void DFS(ALGraph *G, int i);
void DFS_Traverse(ALGraph *G);
void BFS_Traverse(ALGraph * G);


// 主函数
int main(void)
{
    ALGraph G;

    CreateALGraph(&G);

    printf("顶点数: %d，边数: %d\n", G.numVex, G.numEdge);

    VertexType v0 = G.adjList[0].data;            // v0顶点
    int idx = G.adjList[0].firstEdge->adjvex;     // v0顶点的邻接点的下标
    EdgeType w1 = G.adjList[0].firstEdge->weight;  // （v0,v1）边权值
    VertexType v1 = G.adjList[idx].data;          // v0的邻接点v1
    printf("边(%c,%c)的权值: %d\n", v0, v1, w1);

    VertexType v2 = G.adjList[2].data;            // v0顶点
    int idx2 = G.adjList[2].firstEdge->adjvex;     // v0顶点的邻接点的下标
    EdgeType w2 = G.adjList[2].firstEdge->weight;  // （v0,v1）边权值
    VertexType v3 = G.adjList[idx].data;          // v0的邻接点v1
    printf("边(%c,%c)的权值: %d\n", v2, v3, w2);

    printf("深度优先遍历：");
    DFS_Traverse(&G);
    printf("广度优先遍历：");
    BFS_Traverse(&G);
    
    return 0;
}


// 创建无向图的邻接表
void CreateALGraph(ALGraph *G)
{
    int i, j, k, w;

    // 读入顶点数和边数
    printf("请输入顶点数和边数（以空格分割）：");
    scanf("%d %d", &G->numVex, &G->numEdge);
    while( getchar() != '\n' );  // 消除回车符及多余字符

    // 读入顶点信息，构建顶点表
    printf("请输入顶点信息（连续输入，勿空格）：");
    for ( i = 0; i < G->numVex; i++ ) {
        scanf("%c", &G->adjList[i].data);  
        G->adjList[i].firstEdge = NULL;  // 将边表置为空
    }
    while( getchar() != '\n' );  // 消除回车符及多余字符

    // 构建边表
    for ( k = 0; k < G->numEdge; k++ ) {
        printf("请输入边(Vi,Vj)的下标i、小标j和权值（以空格分割）：");
        scanf("%d %d %d", &i, &j, &w);
        
        // 为边表节点分配内存空间
        EdgeNode * e = (EdgeNode*)malloc(sizeof(EdgeNode));
        if ( NULL == e) {
            printf("内存分配失败！");
            exit(-1);
        }
        e->weight = w;  // 边表节点的权值域初始化
        e->adjvex = j;  // 记录下边(Vi.Vj)的前节点下标
        e->next = G->adjList[i].firstEdge;  // 头插法，首先将新节点的尾巴指针指向 firstEdge 边节点
        G->adjList[i].firstEdge = e;        // 再将新节点的头练手顶节点 

        // 因为是无向图，调换i、j再操作一遍
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        if ( NULL == e) {
            printf("内存分配失败！");
            exit(-1);
        }
        e->weight = w;  // 边表节点的权值域初始化
        e->adjvex = i;  // 记录下边(Vi.Vj)的后节点下标
        e->next = G->adjList[j].firstEdge;  
        G->adjList[j].firstEdge = e;        
    }
}

// 邻接表的深度优先递归算法
// 从某个顶点开始，深入挖掘其邻接顶点，完成递归
static void DFS(ALGraph *G, int i)
{
    printf("%c ", G->adjList[i].data);
    visited[i] = true;

    EdgeNode * p = G->adjList[i].firstEdge;  // 第一个邻接顶点  
    while ( p != NULL ) {  // 循环遍历其所有邻接顶点
        if ( !visited[p->adjvex] ) {  
            DFS(G, p->adjvex);
        }
        p = p->next;  // 下一个邻接顶点
    }
}

// 邻接表的深度优先遍历
void DFS_Traverse(ALGraph *G)
{
    // 初始化标记数组
    for ( int i = 0; i < G->numVex; i++ ) {
        visited[i] = false;
    }

    for ( int j = 0; j < G->numVex; j++ ) {  // 适用于非连通图
        if ( !visited[j] ) {
            DFS(G, j);
        }
    }
}

// 邻接表的广度优先遍历
void BFS_Traverse(ALGraph * G)
{
    // 将标记数组初始化
    for ( int i = 0; i < G->numVex; i++ ) {
        visited[i] = false;
    }

    LinkQueue q; 
    int idx;

    InitQueue(&q);
    for ( int j = 0; j < G->numVex; j++ ) {  // 适用于非连通图
        if ( !visited[j] ) {
            EnQueue(&q, j);  // 第一个顶点下标入队
            visited[j] = true;
            while ( QueueIsEmpty(&q) ) {
                DeQueue(&q, &idx);    // 出队
                printf("%c ", G->adjList[idx].data);  // 访问顶点
                
                // 出队的同时将其所有未访问邻接点入队
                EdgeNode *p = G->adjList[idx].firstEdge;
                while ( p != NULL ) {
                    if ( !visited[p->adjvex] ) {  // 勿忘这一句，筛选出尚未访问的顶点
                        EnQueue(&q, p->adjvex);  
                        visited[p->adjvex] = true;
                    }
                    p = p->next;
                }
            }
        }
        
    }
    DestoryQueue(&q);  // 与 InitQueue() 成对出现
}
