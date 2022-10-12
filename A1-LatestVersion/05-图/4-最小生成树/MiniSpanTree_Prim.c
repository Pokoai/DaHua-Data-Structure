/*
 * 功能: 图-最小生成树
 * 作者: Guyue
 * 微信公众号(破壳Ai): https://img.arctee.cn/one/pokeai-wechat.png
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


// 函数前置声明
void CreateAMGraph(AMGraph *G);
void DFS_Traverse(AMGraph * G);
void MiniSpanTree_Prim(AMGraph *G);


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