/*
 * @Description: 《大话数据结构》-图-邻接表结构实现（无向网）
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-10-09 21:13:48
 * @LastEditTime: 2021-10-14 18:37:39
 * @FilePath: \DaHua\Chapter7_Graph\02CreateALGraph.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VEX 100

//顶点类型
typedef char VertexType;

//边的权值类型
typedef int EdgeType;

//图的邻接表结构
//1.边表的结点
typedef struct edgeNode {
    int adjvex; //边顶点的下标值
    EdgeType weight; //边的权值
    struct edgeNode * next;
}EdgeNode;

/*
//2.顶点的结点
typedef struct vertexNode {
    VertexType data; //顶点信息
    EdgeNode * firstedge; //指向顶点的第一个边结点
}VertexNode, vexs[MAX_VEX]; //这里变量名用vexs不符合实际含义，因为这是顶点数组，而非邻接表数组

//3.邻接表
typedef struct {
    vexs vexs; //邻接表
    int numNodes, numEdges;
}ALGraph;
*/

//修改版：2.顶点
//之所以不叫结点，是因为这里的顶点仍然是一个数组，并非链式结构，所以不要当成结点去理解，
//当成数组的其中一个元素去理解更符合、也更容易理解
typedef struct {
    VertexType data;
    EdgeNode * firstedge;
}Vertex; //顶点类型


//修改版：3.最终的邻接表结构实现
//仅包含顶点数组就行了，因为顶点结构中有一个边指针，那么只要知道了顶点，其实就知道了整个邻接表，
//类似于链表结构，知道了头指针就知道了整个链表一样
typedef struct {
    Vertex vexs[MAX_VEX]; //仅包含顶点数组就已经可以表示邻接表了
    int numNodes, numEdges; //这两项起辅助作用
}ALGraph;

/*----------------------------至此，邻接表数据结构 构造完成-------------------------------*/


//创建无向图的邻接矩阵结构
bool CreateALGraph(ALGraph * G)
{
    int i, j, w;
    EdgeNode * e; 

    printf("请输入顶点数和边数(以空格分隔)：");
    scanf("%d%d", &G->numNodes, &G->numEdges);
    while(getchar() != '\n')
        continue;

    printf("请输入顶点（连续输入，勿空格）：");
    for (i = 0; i < G->numNodes; i++) {
        scanf("%c", &G->vexs[i].data); //装入顶点信息
        G->vexs[i].firstedge = NULL; //边表头指针先置为空
    }
    while(getchar() != '\n')
        continue;

    //创建边表
    for (int k = 0; k < G->numEdges; k++) {
        printf ("请输入边（vi, vj）的下标i、j以及权值w（以空格分隔）：");
        scanf("%d%d%d", &i, &j, &w);

        //因为是链表结构，所以要先给边结点分配空间
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        if (e == NULL)
            return false;  
        //插入到边表头
        e->adjvex = j;
        e->weight = w;
        e->next = G->vexs[i].firstedge;
        //更新表头指针
        G->vexs[i].firstedge = e;

        //因为是无向图，调换i、j再来一次
        e = (EdgeNode*)malloc(sizeof(EdgeNode));
        if (e == NULL)
            return false;  
        //插入到边表头
        e->adjvex = i;
        e->weight = w;
        e->next = G->vexs[j].firstedge;
        //更新表头指针
        G->vexs[j].firstedge = e;
    }

    return true;
}

int main(void)
{
    ALGraph G;
    int i;

    CreateALGraph(&G);
    printf("顶点数:%d, 边数:%d\n", G.numNodes, G.numEdges);
    printf("边（%c, %c）的权值：%d", G.vexs[0].data, G.vexs[(G.vexs[0].firstedge->adjvex)].data, G.vexs[0].firstedge->weight);
    
    return 0;
}