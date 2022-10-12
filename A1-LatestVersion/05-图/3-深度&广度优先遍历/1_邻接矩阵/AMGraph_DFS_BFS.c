/*
 * 功能: 图-邻接矩阵深度广度优先遍历
 * 作者: Guyue
 * 微信公众号: https://img.edgetee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-10-01
 */


// 深度优先：类似于树的前序遍历
// 广度优先：类似于树的层序遍历（借助队列实现）


#include <stdio.h>
#include <stdbool.h>

#include "linkQueue.h"

/*------------------------- 图-邻接矩阵结构定义 ------------------------*/

#define MAXVEX 100        // 最大顶点数
// #define INFINITY 65535    // 用整数最大值代表无穷大

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
static void DFS(AMGraph * G, int i);
void DFS_Traverse(AMGraph *G);
void BFS_Traverse(AMGraph *G);


// 主函数
int main(void)
{
    AMGraph G;

    CreateAMGraph(&G);

    printf("顶点数: %d，边数: %d\n", G.numVex, G.numEdge);
    printf("边(%c,%c)的权值: %d\n", G.vex[4], G.vex[3], G.edge[4][3]);

    printf("深度优先遍历：");
    DFS_Traverse(&G);
    printf("\n");

    printf("广度优先遍历：");
    BFS_Traverse(&G);

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

// 邻接矩阵的广度优先遍历
// void BFS_Traverse(AMGraph *G)
// {
//     // 初始化标记数组
//     for ( int i = 0; i < G->numVex; i++ ) {
//         visited[i] = false;
//     }

//     LinkQueue q;
//     int idx;

//     InitQueue(&q);
//     for ( int j = 0; j < G->numVex; j++ ) {
//         if ( !visited[j] ) {
//             EnQueue(&q, j);
//             while ( !QueueIsEmpty(&q) ) {
//                 DeQueue(&q, &idx);
//                 printf("%c ", G->vex[idx]);
//                 visited[idx] = true;         // 出队时再标记，错误！应该进队时就要标记！

//                 // 将其所有未访问的邻接点入队
//                 for ( int k = 0; k < G->numVex; k++ ) {
//                     if ( G->edge[idx][k] == 1 && !visited[k] ) {
//                         EnQueue(&q, k);
//                     }
//                 }
//             }
//         }
//     }
//     DestoryQueue(&q);
// }


// 邻接矩阵的广度优先遍历
void BFS_Traverse(AMGraph *G)
{
    // 初始化标记数组
    for ( int i = 0; i < G->numVex; i++ ) {
        visited[i] = false;
    }

    LinkQueue q;
    int idx;

    InitQueue(&q);
    for ( int j = 0; j < G->numVex; j++ ) {
        if ( !visited[j] ) {
            EnQueue(&q, j);
            visited[j] = true;  // 入队时就要马上进行标记
            while ( !QueueIsEmpty(&q) ) {
                DeQueue(&q, &idx);
                printf("%c ", G->vex[idx]);  // 避免后面再写一句 printf，故出队时再访问
                
                // 将其所有未访问的邻接点入队
                for ( int k = 0; k < G->numVex; k++ ) {
                    if ( G->edge[idx][k] == 1 && !visited[k] ) {
                        EnQueue(&q, k);
                        visited[k] = true;  // 入队时就要马上进行标记
                    }
                }
            }
        }
    }
    DestoryQueue(&q);  // 跟 InitQueue() 配套
}