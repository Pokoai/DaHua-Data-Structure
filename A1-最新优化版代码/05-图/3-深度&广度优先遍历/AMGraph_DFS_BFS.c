/*
 * 功能: 图-邻接矩阵深度广度优先遍历
 * 作者: Guyue
 * 微信公众号: https://img.edgetee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Qtructure/tree/main/%E6%9C%80%E6%96%B0%E4%BC%98%E5%8C%96%E7%89%88%E4%BB%A3%E7%A0%81
 * Date: 2022-10-01
 */

#include <stdio.h>
#include <stdbool.h>

#define MAXVEX 100        // 最大顶点数
// #define INFINITY 65535    // 用整数最大值代表无穷大

bool visited[MAXVEX];     // 标记数组



typedef char VertexType;  // 顶点数据类型
typedef int EdgeType;     // 边/弧权值数据类型

// 图的邻接矩阵存储结构
typedef struct {
    VertexType vex[MAXVEX];         // 顶点数组
    EdgeType edge[MAXVEX][MAXVEX];  // 边权值的二维数组
    int numVex, numEdge;            // 顶点数、边数
} AMGraph;




// 函数声明
void CreateAMGraph(AMGraph *G);
static void DFS(AMGraph * G, int i);
void DFS_Traverse(AMGraph *G);



int main(void)
{
    AMGraph G;

    CreateAMGraph(&G);

    printf("顶点数: %d，边数: %d\n", G.numVex, G.numEdge);
    printf("边(%c,%c)的权值: %d\n", G.vex[2], G.vex[0], G.edge[2][0]);

    DFS_Traverse(&G);

    return 0;
}


// 创建无向图的邻接矩阵
// 权值均为 1
void CreateAMGraph(AMGraph *G)
{
    int i, j; 

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

    // 初始化边权值
    for ( i = 0; i < G->numVex; i++ ) {
        for ( j = 0; j < G->numVex; j++ ) {
            G->edge[i][j] = 0;
        }
    }

    // 边权值赋值为1
    G->edge[0][1]=1;
	G->edge[0][5]=1;

	G->edge[1][2]=1; 
	G->edge[1][8]=1; 
	G->edge[1][6]=1; 
	
	G->edge[2][3]=1; 
	G->edge[2][8]=1; 
	
	G->edge[3][4]=1;
	G->edge[3][7]=1;
	G->edge[3][6]=1;
	G->edge[3][8]=1;

	G->edge[4][5]=1;
	G->edge[4][7]=1;

	G->edge[5][6]=1; 
	
	G->edge[6][7]=1; 

    for ( i = 0; i < G->numVex; i++ ) {
        for ( j = i; j < G->numVex; j++ ) {
            G->edge[j][i] = G->edge[i][j];
        }
    }
}

// 邻接矩阵的深度优先递归算法
// 从下标为 i 的顶点开始遍历
static void DFS(AMGraph * G, int i)
{
    printf("%c ", G->vex[i]);  // 打印顶点
    visited[i] = true;  // 标记为已遍历

    for ( int j = 0; j < G->numVex; j++ ) {
        if ( G->edge[i][j] == 1 && !visited[j] ) {
            DFS(G, j);  // 对未访问的邻接顶点进行递归访问
        }
    }
}

// 邻接矩阵的深度优先遍历
void DFS_Traverse(AMGraph *G)
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