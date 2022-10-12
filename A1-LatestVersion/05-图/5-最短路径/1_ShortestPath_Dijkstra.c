/*
 * 功能: 图-最短路径（Dijkstra算法）
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-10-09
 */

#include <stdio.h>
#include <stdbool.h>


/*------------------------- 图-邻接矩阵结构定义 ------------------------*/

#define MAXVEX 100        // 最大顶点数
#define INFINITY 65535    // 用整数最大值代表无穷大

typedef char VertexType;  // 顶点数据类型
typedef int EdgeType;     // 边/弧权值数据类型

// 图的邻接矩阵存储结构
typedef struct {
    VertexType vex[MAXVEX];         // 顶点数组
    EdgeType edge[MAXVEX][MAXVEX];  // 边权值的二维数组
    int numVex, numEdge;            // 顶点数、边数
} AMGraph;

/*------------------------- 图-邻接矩阵结构定义 ------------------------*/


bool visited[MAXVEX];     // 标记数组

typedef int ShortestPathLength[MAXVEX];  // 存储V0到各顶点的最短距离
typedef int PreVex[MAXVEX];  // 存储V0到各顶点最短路径的最后一个前驱节点，依据前驱节点可依次反推出最短路径走法


// 函数前置声明
void CreateAMGraph(AMGraph *G);
void DFS_Traverse(AMGraph * G);
void MiniSpanTree_Prim(AMGraph *G);
void ShortestPath_Dijkstra(AMGraph *G, int v0, ShortestPathLength * L, PreVex * V);


// 主函数
int main(void)
{
    AMGraph G;

    CreateAMGraph(&G);

    printf("深度优先遍历：");
    DFS_Traverse(&G);
    printf("\n");

    printf("最小生成树：\n");
    MiniSpanTree_Prim(&G);

    printf("顶点A到各顶点的最短路径：");
    ShortestPathLength L;
    PreVex V;
    ShortestPath_Dijkstra(&G, 0, &L, &V);
    for ( int i = 0; i < G.numVex; i++ ) {
        printf("%d ", L[i]);
    }

    return 0;
}


// 创建无向图的邻接矩阵
void CreateAMGraph(AMGraph *G)
{
    // 读入顶点数、边数
    G->numVex =9;
    G->numEdge = 15;

    // 读入顶点信息，建立顶点表
    G->vex[0]='A';
	G->vex[1]='B';
	G->vex[2]='C';
	G->vex[3]='D';
	G->vex[4]='E';
	G->vex[5]='F';
	G->vex[6]='G';
	G->vex[7]='H';
	G->vex[8]='I';

    // 初始化邻接矩阵，全置为无穷大
    int i, j; 
    for ( i = 0; i < G->numVex; i++ ) {
        for ( j = 0; j < G->numVex; j++ ) {
            G->edge[i][j] = INFINITY;
        }
    }

    // 邻接矩阵赋值，即各边权值
    G->edge[0][1]=10;
	G->edge[0][5]=11;

	G->edge[1][2]=18; 
	G->edge[1][6]=16; 
	G->edge[1][8]=12; 
	
	G->edge[2][3]=22; 
	G->edge[2][8]=8; 
	
	G->edge[3][4]=20;
	G->edge[3][7]=24;
	G->edge[3][6]=16;
	G->edge[3][8]=21;

	G->edge[4][5]=26;
	G->edge[4][7]=7;

	G->edge[5][6]=17; 
	
	G->edge[6][7]=9; 

    for ( i = 0; i < G->numVex; i++ ) {
        for ( j = i; j < G->numVex; j++ ) {
            G->edge[j][i] = G->edge[i][j];
        }
    }
}

// 深度优先遍历递归部分
void DFS(AMGraph *G, int i)
{
    // 打印顶点信息
    printf("%c ", G->vex[i]);
    visited[i] = true;

    // 找到该顶点的所有邻接顶点
    for ( int j = 0; j < G->numVex; j++ ) {
    if ( !visited[i] && G->edge[i][j] != INFINITY )
        DFS(G, j);
    }
}

// 深度优先遍历
void DFS_Traverse(AMGraph * G)
{
    // 初始化标记数组
    for ( int i = 0; i < G->numVex; i++ ) {
        visited[i] = false;
    }

    // 开始遍历
    for ( int i = 0; i < G->numVex; i++ ) {
        if ( !visited[i] ) {
            DFS(G, i);
        }
    }
}

// 最小生成树
void MiniSpanTree_Prim(AMGraph *G)
{
    EdgeType lowcost[MAXVEX];  // 存储较小权值
    int adjvex[MAXVEX];        // 存储权值对应的头顶点下标

    // 首先假设 v0为生成树第一个点
    lowcost[0] = 0;  // lowcost[i] = 0 即表示将第 i 个顶点加入最小生成树
    adjvex[0] = 0;

    // 初始化两个数组
    for ( int i = 1; i < G->numVex; i++ ) {
        lowcost[i] = G->edge[0][i];  // 存入以 V0为顶点的边的权值  
        adjvex[i] = 0;               // 因为 lowcost[]中存入的都是 以v0为头顶点的权值，故 adjvex[]全为0
    }

    // 开始建立最小生成树
    for ( int i = 1; i < G->numVex; i++ ) {
        // 1. 找出 lowcost[]中最小值对应的尾顶点下标
        int min = INFINITY;  // 记录最小值
        int k;               // 记录最小值对应下标
        for ( int j = 1; j < G->numVex; j++ ) {
            if ( lowcost[j] != 0 && lowcost[j] < min ) {
                min = lowcost[j];
                k = j;
            }
        }  // 至此，已找到最小值min、极其对应下标k

        // 2. 将尾顶点（即第k个顶点）加入到最小生成树中
        lowcost[k] = 0;

        // 3. 打印最小生成树的最新边
        printf("(%c, %c)\n", G->vex[adjvex[k]], G->vex[k]);

        // 4. 更新lowcost[]、adjvex[]
        for ( int j = 1; j < G->numVex; j++ ) {
            // 比较两行权值取最小值存入lowcost
            if ( lowcost[j] != 0 && G->edge[k][j] < lowcost[j] ) {
                lowcost[j] = G->edge[k][j];
                adjvex[j] = k;
            }
        }
    }
}

// 最短路径-Dijkstra
// v0: 起点下标
// *L: v0到各顶点的最短路径长度
// *V: v0到各顶点的最短路径所途经的最后一个前驱节点
void ShortestPath_Dijkstra(AMGraph *G, int v0, ShortestPathLength * L, PreVex * V)
{
    // 定义一个标记数组
    int flg[MAXVEX];  // 0: 未加入到最短路径；1：已加入

    // 初始化三个数组
    for ( int i = 0; i < G->numVex; i++ ) {
        (*L)[i] = G->edge[v0][i];  // v0到各顶点的初始距离
        (*V)[i] = -1;  // 下标 > 0，初始化为-1，避免与真实下标相同
        flg[i] = 0;  // 各顶点都未加入到最短路径中
    }

    // 先将v0加入到最短路径中
    (*L)[v0] = 0;
    flg[v0] = 1;

    // 再将其他顶点加入到最短路径中
    // i 从 1 开始，因为v0已经加入了，后面从 v1开始
    for ( int i = 1; i < G->numVex; i++ ) {
        // 1. 找到离 v0 最近的顶点
        int min = INFINITY;
        int k;
        for ( int j = 0; j < G->numVex; j++ ) {
            if ( !flg[j] && (*L)[j] < min ) {
                min = (*L)[j];
                k = j;
            }
        }  // 至此，找到了距离 V0最近的顶点 Vk

        // 2. 将 Vk 加入到最短路径中
        flg[k] = 1;

        // 3. 更新(*L)[]、(*V)[]
        for ( int j = 0; j < G->numVex; j++ ) {
            // min + G->edge[k][j]: V0到Vk的最短路径 + Vk到其邻接顶点（即Vj）的权值
            // (*L)[j]            ：V0直接到Vj的权值
            if ( !flg[j] && min + G->edge[k][j] < (*L)[j] ) {
                (*L)[j] = min + G->edge[k][j];
                (*V)[j] = k;
            }
        }
    }
}