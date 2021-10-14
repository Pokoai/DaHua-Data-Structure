/*
 * @Description: 《大话数据结构》-图-邻接矩阵创建
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-10-09 16:50:13
 * @LastEditTime: 2021-10-14 18:37:35
 * @FilePath: \DaHua\Chapter7_Graph\01CreateMGraph.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */


#include <stdio.h>

#define MAX_SIZE 100
#define INFINITY 65535 //INFINITY表示无穷大，即不存在

//顶点类型
typedef char VertexType;

//边的权值的类型
typedef int EdgeType;

//图的邻接矩阵结构
typedef struct {
    VertexType vexs[MAX_SIZE]; //顶点数组
    EdgeType arc[MAX_SIZE][MAX_SIZE]; //边/弧的二维数组
    int numNodes, numEdges; //顶点数量、边数量
}MGraph;


//创建无向图的邻接矩阵结构
void CreateMGraph(MGraph * G)
{
    int i, j, w;

    printf("请输入无向图的顶点数和边数(以空格分隔)：");
    scanf("%d%d", &G->numNodes, &G->numEdges);
    //去掉回车键产生的字符
    while(getchar() != '\n')
        continue;

    //构建顶点数组
    printf("请输入顶点(连续输入，勿空格)：");
    for (int i = 0; i < G->numNodes; i++) {
        scanf("%c", &G->vexs[i]);
    }
    //后面要读入数值，要先去掉回车键产生的字符
    while(getchar() != '\n')
        continue;

    //初始化邻接矩阵
    for (int i = 0; i < G->numNodes; i++) {
        for (int j = 0; j < G->numNodes; j++) 
            G->arc[i][j] = INFINITY;
    }

    //构建邻接矩阵
    for (int k = 0; k < G->numEdges; k++) {
        printf("请输入边（vi,vj）的下标i、j以及权值w(以空格分隔)：");
        scanf("%d%d%d", &i, &j, &w);
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];
    }

}

int main(void)
{
    MGraph G;

    CreateMGraph(&G);
    printf("顶点数:%d, 边数:%d\n", G.numNodes, G.numEdges);
    printf("边（%c, %c）的权值：%d", G.vexs[0], G.vexs[1], G.arc[0][1]);

    return 0;
}