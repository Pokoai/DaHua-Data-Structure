/*
 * 功能: 有向无环图-拓扑排序
 * 作者: Guyue
 * 微信公众号(破壳Ai): https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-10-09
 */


/*拓扑排序目的：
在各为各的前提条件的无环复杂网络中，
如何在不违背所有前提条件的情况下，把各个事件依次排好序，这就是拓扑排序的目的。

拓扑排序思路：
依次找出入度为0（即没有前提条件了）的顶点（事件），然后执行该事件，并删除以该点为弧尾的弧（即弧头顶点入度减1）
为了避免每次都要循环遍历查找入度是否为0，则采用栈，将入度为0的顶点保存到栈中，后续从栈中直接取出，无需遍历查找
*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


/*------------------------- 图-邻接矩阵结构定义 ------------------------*/

#define MAXVEX 100

typedef char VertexType;
typedef int EdgeType;

// 边表节点
typedef struct edgeNode {
    int adjvex;
    // EdgeType weight;  // 拓扑排序，不需要边表节点的权值域weight
    struct edgeNode * next;
} EdgeNode;

// 带入度的顶点表节点
typedef struct vertex {
    VertexType data;
    EdgeNode * firstedge;
    int in;             // 拓扑排序，顶点表节点增加入度域in
} VertexNode;

typedef VertexNode AdjList[MAXVEX];  

// 最终定义图的邻接表结构
typedef struct {
    AdjList adjList;
    int numVex, numEdge;
} ALGraph;

/*------------------------- 图-邻接矩阵结构定义 ------------------------*/



// 拓扑排序
bool TopologicalSort(ALGraph *G)
{
    // 构建栈，用来存储入度为0的顶点下标
    int * Stack = malloc(sizeof(int) * G->numVex);
    if ( NULL == Stack ) {
        printf("建栈失败！\n");
        exit(-1);
    }
    int top = -1;  // 栈顶指针初始为 -1

    // 首先遍历所有顶点，将入度为0的顶点入栈
    for ( int i = 0; i < G->numVex; i++ ) {
        if ( 0 == G->adjList[i].in ) {
            Stack[++top] = i;  // 入栈
        }
    }

    // 出栈，并将该顶点作为弧尾的顶点入度减1
    int getTop;
    int count;  // 记录出栈次数，即拓扑排序顶点个数
    while ( top != -1 ) {
        getTop = Stack[top--];  // 出栈
        printf("%c->", G->adjList[getTop].data);  // 打印出栈顶点
        count++;

        // 找到以该顶点作为弧尾的顶点
        EdgeNode * p = G->adjList[getTop].firstedge;  // 找到第一个头顶点
        while ( p != NULL ) {  // 遍历其所有头顶点
            if ( 0 == --G->adjList[p->adjvex].in ) {  // 入度减1，若为0则入栈
                Stack[++top] = p->adjvex;
            }
            p = p->next;
        }
    }

    if ( count < G->numVex ) {
        return false;
    }
    return true;
}