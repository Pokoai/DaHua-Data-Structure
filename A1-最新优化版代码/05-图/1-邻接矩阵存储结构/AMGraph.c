/*
 * 功能: 图-邻接矩阵存储结构
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Qtructure/tree/main/%E6%9C%80%E6%96%B0%E4%BC%98%E5%8C%96%E7%89%88%E4%BB%A3%E7%A0%81
 * Date: 2022-09-30
 */

#include <stdio.h>

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


// 函数声明
void CreateAMGraph(AMGraph *G);


int main(void)
{
    AMGraph G;

    CreateAMGraph(&G);

    printf("顶点数: %d，边数: %d\n", G.numVex, G.numEdge);
    printf("边(%c,%c)的权值: %d\n", G.vex[2], G.vex[0], G.edge[2][0]);
    printf("边(%c,%c)的权值: %d\n", G.vex[2], G.vex[3], G.edge[2][3]);
    printf("边(%c,%c)的权值: %d\n", G.vex[3], G.vex[1], G.edge[3][1]);

    return 0;
}


// 创建无向图的邻接矩阵
void CreateAMGraph(AMGraph *G)
{
    int i, j, k, w;

    // 读入顶点数和边数
    printf("请输入顶点数和边数（以空格分隔）：");
    scanf("%d %d", &G->numVex, &G->numEdge);
    while ( getchar() != '\n');  // 消除回车符

    // 读入顶点信息，建立顶点表
    printf("请输入顶点信息（连续输入，不用空格分隔）：");
    for ( i = 0; i < G->numVex; i++ ) {
        scanf("%c", &G->vex[i]);
    }
    while ( getchar() != '\n');  // 消除回车符

    // 初始化邻接矩阵，全置为无穷大
    for ( i = 0; i < G->numVex; i++ ) {
        for ( int j = 0; j < G->numVex; j++ ) {
            G->edge[i][j] = INFINITY;
        }
    }

    // 依据图给邻接矩阵赋值
    for ( k = 0; k < G->numEdge; k++ ) {
        printf("请输入边（Vi,Vj）的下标i、下标j和权值w（以空格分隔）：");
        scanf("%d %d %d", &i, &j, &w);
        G->edge[i][j] = w;
        G->edge[j][i] = w;  // 无向图
    }
}