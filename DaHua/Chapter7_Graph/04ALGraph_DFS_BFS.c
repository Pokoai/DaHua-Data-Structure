/*
 * @Description: 《大话数据结构》邻接表的深度优先-广度优先算法
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-10-12 20:02:37
 * @FilePath: \DaHua\Chapter7_Graph\04ALGraph_DFS_BFS.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

#include <stdio.h>
#include <stdbool.h>
#include "02CreateALGraph.c"
#include "linkqueue.h"

#define MAX_VEX 100

//typedef enum{nvisit, visited} Flag;  这样有点多此一举
bool visit[MAX_VEX]; //顶点是否被访问过的标记数组

//邻接表的深度优先递归算法
void DSF(ALGraph G, int i, void (*func)(VertexType v))
{   
    EdgeNode * p;

    //先标记再访问
    visit[i] = true;
    (*func)(G.vexs[i].data);
    //查找邻接点
    p = G.vexs[i].firstedge; //p指向第一个邻接点
    while (p) { //邻接点存在
        //还要判断该邻接点是否已经访问过
        if (!visit[p->adjvex]) {
            //开始递归
            DSF(G, p->adjvex, func);
        } 
        //更新p
        p = p->next;
    }
}

//邻接表的深度遍历
void BSFTraverse(ALGraph G, void (*func)(VertexType v))
{
    //初始化
    for (int i = 0; i < G.numNodes; i++)  
        visit[i] = false;

    for (int i = 0; i < G.numNodes; i++) {
        if (!visit[i])
            BSF(G, i, func);
    }
}

//邻接表的广度优先遍历
void BSF(ALGraph G, void (*func)(VertexType v))
{
    EdgeNode * p;
    LinkQueue Q;

    //初始化
    for (int i = 0; i < G.numNodes; i++) {
        visit[i] = false;
    } 
    InitQueue(&Q);

    for (int i = 0; i < G.numNodes; i++) {
        if (!visit[i]) {
            visit[i] == true;
            (*func)(G.vexs[i].data);
            EnQueue(&Q, i);
            while (!QueueIsEmpty(Q)) {
                DeQueue(&Q, &i);
                p = G.vexs[i].firstedge;
                while (p) {
                    if (!visit[p->adjvex]) {
                        visit[p->adjvex] == true;
                        (*func)(G.vexs[p->adjvex].data);
                        EnQueue(&Q, p->adjvex);
                    }
                    p = p->next;
                }
            }
            
        }
    }
}
