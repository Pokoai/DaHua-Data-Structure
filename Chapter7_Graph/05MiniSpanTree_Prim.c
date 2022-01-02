/*
 * @Description: 《大话数据结构》最小生成树的Prim算法
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-10-13 09:59:11
 * @FilePath: \DaHua\Chapter7_Graph\05MiniSpanTree_Prim.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */
#include <stdio.h>
#include <stdbool.h>
#include "01CreateMGraph.c"

#define MAX_VEX 20 //最大顶点数
#define INIFINITY 65535  

//最小生成树的Prim算法
void MiniSpanTree_Prim(MGraph G)
{
    int min, k;
    int adjvex[MAX_VEX]; //权值数组所对应的边的起点下标，与权值数组保持同步
    int lowcost[MAX_VEX]; //存储权值，值为0：已加入生成树

    //先从任意一个顶点开始，这里为了方便就从V0顶点开始
    lowcost[0] = 0; //[0]:第一个权值，即V0所代表的权值，当然为0了（一个点有权值），另外这个=0的0也表示第一个顶点V0已加入生成树，后面就不用考虑它了
    adjvex[0] = 0; //[0]:与权值数组对应，即第一个权值所对应的元素，=0：这里的0表示第一个权值的起点是V0
    //接着初始化lowcost数组和adjvex数组其他元素
    for (int i = 1; i < G.numNodes; i++) {
        lowcost[i] = G.arc[0][i]; //将V0为起点的边的权值全放入权值数组中，后续不断更新这个数组
        adjvex[i] = 0; //记住adjvex始终保持与lowcost同步更新，=0即表述lowcost中的权值边都是以V0开始的
    }//至此，初始化结束

    //下面要不断地找出权值数组lowcost中的最小值，并不断的更新lowcost
    for (int i = 1; i < G.numNodes; i++) { //i的循环是为了推进生成树的顶点逐次增加，直到结束
        //1.找出最小权值
        for (int j = 1; j < G.numNodes; j++) {
            min = INFINITY;
            if (lowcost[j] != 0 && lowcost[j] < min) {
                min = lowcost[j];
                k = j; //最小权值的下标保存在k中
            }
        }
        //2.打印找到的边
        //既然找到最小值了，那么最小值的下标就是我们要找的下一个顶点,那么生成树的边就有了
        printf("(%d, %d)\n", adjvex[k], k);

        //3.更新权值数组和adjvex
        lowcost[k] = 0; //标记Vk已加入生成树中
        for (int j = 1; j < G.numNodes; j++) {
            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) {//i顶点未加入生成树且（k,i）边权值比现有的i位置权值小
                lowcost[j] = G.arc[k][j]; //更新权值数组
                adjvex[j] = k; //新加入的权值所对应边的起点是k
            }
        }

    }
}
