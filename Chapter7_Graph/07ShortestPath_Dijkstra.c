/*
 * @Description: 《大话数据结构》最短路径Dijkstra算法
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-10-14 18:41:57
 * @FilePath: \DaHua\Chapter7_Graph\07ShortestPath_Dijkstra.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include "01CreateMGraph.c"

#define MAX_VEX 100
#define INIFINITY 65535

typedef int ShortestPathLength[MAX_VEX]; //存储起点到各顶点的最短路径长度
typedef int preVex[MAX_VEX]; //存储路径上前驱顶点的下标值


/**
 * @description: 最短路径Dijkstra算法
 * @param {MGraph} G
 * @param {int} v0：起点
 * @param {ShortestPathLength *} L：存储V0到各顶点的最短路径长度
 * @param {preVex *} V：存储最短路径上各顶点的前驱下标
 * @return {*}
 */
void ShortestPath_Dijkstra(MGraph G, int v0, ShortestPathLength * L, preVex * V)
{
    int flag[MAX_SIZE]; //标记数组，1表示已加入最短路径中

    //初始化
    for (int i = 0; i < G.numNodes; i++) {
        (*L)[i] = G.arc[v0][i]; //初始化L数组为v0到各顶点的长度，后续逐次更新
        (*V)[i] = -1; //为了与顶点下标区分开来，故设置为-1
        flag[i] = 0; //各顶点均未加入到路径中
    }
    //V0加入路径
    flag[v0] = 1;
    (*L)[v0] = 0; //V0到V0的长度为0

    //每次循环更新V0到某顶点的最短路径
    int min;
    int k; //用来记录距离V0最近顶点的下标
    for (int i = 1; i < G.numNodes; i++) { //i从1开始，即V1开始
        min = INFINITY;
        
        //找到距离V0最短的顶点
        for (int j = 0; j < G.numNodes; j++) {
            if (!flag[j] && (*L)[j] < min) { 
                min = G.arc[v0][j];
                k = j; //储存最近下标值
            }
        }
        flag[k] = 1; //找到后马上加入到最短路径中

        //乘胜追击，立马借助这个最近的点去扫描与之相邻顶点，相当于借助了一只手去探寻更远的地方
        //然后利用扫描到的新路径长度去更新原始V0到各顶点的最短路径
        for (int w = 0; w < G.numNodes; w++) {
            if (!flag[w] && (min+G.arc[k][w] < (*L)[w])) { //min+G.arc[k][j]:多走一步到达j顶点的新路径长度  
                                                           //(*L)[j]:原始从v0到达j顶点的最短路径长度
                (*L)[w] = min + G.arc[k][w]; //更新从v0到j顶点的最短路径长度
                (*V)[w] = k; //到达顶点j 之前的那一个中转顶点的下标，即前驱顶点下标
            }
        }

    }

}
 