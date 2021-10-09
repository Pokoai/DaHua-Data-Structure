/*
 * @Description: 《大话数据结构》-图-邻接表
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/adairhu
 * @Date: 2021-10-09 21:13:48
 * @LastEditTime: 2021-10-09 22:40:26
 * @FilePath: \DaHua\Chapter7_Graph\02CreateALGraph.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VEX 100

//顶点类型
typedef char VertexType;

//边的权值的类型
typedef int EdgeType;

//图的邻接表结构
//1.边表的结点
typedef struct edgeNode {
    int adjvex; //边顶点的下标值
    EdgeType weight; //边的权值
    struct edgeNode * next;
}EdgeNode;

//2.顶点的结点
typedef struct vertexNode {
    VertexType data; //顶点信息
    EdgeNode * firstedge; //指向顶点的第一个边结点
}VertexNode, AdjList[MAX_VEX];

//3.邻接表
typedef struct {
    AdjList adjList; //邻接表
    int numNodes, numEdges;
}ALGraph;


//创建无向图的邻接矩阵结构
bool CreateALGraph(ALGraph * G)
{
    int i, j, w;
    EdgeNode * e; //

    printf("请输入顶点数和边数：");
    scanf("%d%d", &G->numNodes, &G->numEdges);
    while(getchar() != '\n')
        continue;

    printf("请输入顶点：");
    for (i = 0; i < G->numNodes; i++) {
        scanf("%c", &G->adjList[i].data); //装入顶点信息
        G->adjList[i].firstedge = NULL; //边表头指针先置为空
    }
    while(getchar() != '\n')
        continue;

    //创建边表
    for (int k = 0; k < G->numEdges; k++) {
        printf ("请输入边（vi, vj）的下标i、j以及权值w：");
        scanf("%d%d%d", &i, &j, &w);

        //分配空间
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        if (e == NULL)
            return false;  
        //插入到边表头
        e->adjvex = j;
        e->weight = w;
        e->next = G->adjList[i].firstedge;
        //更新表头指针
        G->adjList[i].firstedge = e;

        //因为是无向图，调换i、j再来一次
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        if (e == NULL)
            return false;  
        //插入到边表头
        e->adjvex = i;
        e->weight = w;
        e->next = G->adjList[j].firstedge;
        //更新表头指针
        G->adjList[j].firstedge = e;
    }

    return true;
}

int main(void)
{
    ALGraph G;
    int i;

    CreateALGraph(&G);
    printf("顶点数:%d, 边数:%d\n", G.numNodes, G.numEdges);
    printf("边（%c, %c）的权值：%d", G.adjList[0].data, G.adjList[(G.adjList[0].firstedge->adjvex)].data, G.adjList[0].firstedge->weight);
    
    return 0;
}