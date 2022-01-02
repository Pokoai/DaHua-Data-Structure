/*
 * @Description: 《大话数据结构》最短路径Floyd算法
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-10-14 23:24:36
 * @FilePath: \DaHua\Chapter7_Graph\08ShortestPath_Floyd.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include "01CreateMGraph.c"

#define MAX_VEX 100

typedef int ShortestPathLength[MAX_VEX][MAX_SIZE]; //存储起点到各顶点的最短路径长度
typedef int Path[MAX_VEX][MAX_SIZE]; //存储路径上前驱顶点的下标值

//最短路径Floyd算法
void ShortestPath_Floyd(MGraph G, ShortestPathLength * L, Path * P)
{
    //初始化两个矩阵
    for (int i = 0; i < G.numNodes; i++) {
        for (int j = 0; j < G.numNodes; j++) {
            (*L)[i][j] = G.arc[i][j]; //邻接矩阵的权值
            (*P)[i][j] = j;
        }
    }
    //开始迭代
    for (int k = 0; k < G.numNodes; k++) { //w:中转
        for (int i = 0; i < G.numNodes; i++) { //i:起点
            for (int j = 0; j < G.numNodes; j++) { //j:终点
                if ((*L)[i][k] + (*L)[k][j] < (*L)[i][j]) { //中转比直达路径短
                    (*L)[i][j] = (*L)[i][k] + (*L)[k][j];
                    (*P)[i][j] = (*P)[i][k]; //路径设置为经过下标为k的顶点
                }
            }
        }
    }
}

//打印各顶点间最短路径
void PrintShortPath(MGraph G, ShortestPathLength * L, Path * P)
{
    int v, w, k;

    printf("各顶点间最短路径如下:\n");    
	for(v = 0; v < G.numNodes; ++v)   
	{        
		for(w = v+1; w < G.numNodes; w++)  
		{
			printf("v%d-v%d weight: %d ",v, w, L[v][w]);
			k = P[v][w];				/* 获得第一个路径顶点下标 */
			printf(" path: %d", v);	/* 打印源点 */
			while(k != w)				/* 如果路径顶点下标不是终点 */
			{
				printf(" -> %d", k);	/* 打印路径顶点 */
				k = P[k][w];			/* 获得下一个路径顶点下标 */
			}
			printf(" -> %d\n", w);	/* 打印终点 */
		}
		printf("\n");
	}
}
