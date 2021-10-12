/*
 * @Description: 《大话数据结构》邻接矩阵的深度优先-广度优先算法
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/adairhu
 * @Date: 2021-10-12 17:20:15
 * @FilePath: \DaHua\Chapter7_Graph\03MGraph_DFS_BFS.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include "01CreateMGraph.c"
#include "linkqueue.h"

#define MAX_VEX 100

typedef enum{nvisit, visited} Flag;
Flag visit[MAX_VEX]; //顶点是否被访问过的标记数组


//邻接矩阵的深度优先递归算法
void DFS(MGraph G, int i, void (*func)(VertexType v))
{
    //首先将顶点标记为已访问
    visit[i] = visited;
    //访问顶点
    (*func)(G.vexs[i]);
    //查找顶点的邻接点
    for (int j = 0; j < G.numNodes; j++) {
        if (G.arc[i][j] == 1 && visit[j] == nvisit) //找到了未访问过的邻接点
            DFS(G, j, func); //开始递归
    }
}

//邻接矩阵的深度遍历算法
void DFSTraverse(MGraph G, void (*func)(VertexType v))
{
    //首先要初始化标记数组visit
    for (int i = 0; i < G.numNodes; i++)  
        visit[i] = nvisit;

    //依次对每个顶点进行递归遍历，实际上是针对非连通图的，
    //因为对于连通图来说,i=0就能直接遍历完所有的顶点，不需要再去调整遍历的起顶点i了
    for(int i = 0; i < G.numNodes; i++) {
        if (visit[i] == nvisit) {
            DFS(G, i, func); //若顶点i未被访问，则从该顶点开始遍历整个图
        }
    }
}

//邻接矩阵的广度遍历算法
//要借助辅助队列来实现
void BFS(MGraph G, void (*func)(VertexType v))
{
    LinkQueue Q;

    //初始化标记数组
    for (int i = 0; i < G.numNodes; i++) {
        visit[i] = nvisit;
    }
    //初始化队列
    InitQueue(&Q);
    
    //开始遍历
    for (int i = 0; i < G.numNodes; i++) { //其实这里的for循环也是为了非连通图
        if (visit[i] == nvisit) {   //未访问的顶点
            visit[i] == visited;    //1.标记为已访问
            (*func)(G.vexs[i]);     //2.访问顶点
            EnQueue(&Q, i);         //3.顶点入队

            While(!QueueIsEmpty(Q)) {
                DeQueue(&Q, &i); //出队
                //查找该点的邻接点，将其入队
                for (int j = 0; j < G.numNodes; j++) {
                    if (G.arc[i][j] == 1 && visit[j] == nvisit) { //找到未访问的邻接点
                        visit[j] == visited;  //1.标记为已访问
                        (*func)(G.vexs[j]);   //2.访问
                        EnQueue(&Q, j);       //3.邻接点入队
                    }
                }
            }
        }

    }

}