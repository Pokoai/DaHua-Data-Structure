/*
 * 功能: 有向无环图-关键路径
 * 作者: Guyue
 * 微信公众号: https://img.arctee.cn/one/pokeai-wechat.png
 * 网站：https://pokeai.cn
 * Github: https://github.com/Pokoai/DaHua-Data-Structure/tree/main/A1-LatestVersion
 * Date: 2022-10-09
 */




// 先占个位置，待重新编写



/*思路：
1.关键路径由关键活动连起来的，所以要找出关键活动；
2.关键活动：最早开始时间和最晚开始时间相同，
即该事件什么时候必须开始了的时间是确定的，不受某段时间里其他活动的影响，而是去影响别人;
所以要计算出活动最早开始时间（ete）和最晚开始时间(lte)；
3.活动最早开始时间（ete）：由前事件（即该活动弧尾顶点）最早发生时间(etv)确定
活动最晚开始时间(lte)：由后事件（即该活动弧头顶点）最晚发生时间(ltv)与该活动持续时间(weight)确定
4.具体公式：
活动最早开始时间（ete） = 该活动弧尾顶点最早发生时间（事件的最早发生时间(etv)）
活动最晚开始时间(lte) = 该活动弧头顶点最晚发生时间（事件的最晚发生时间(ltv)） - 该活动持续时间（活动弧的权值(weight)）
5.进而推出，只要计算出各事件的最早发生时间(etv[])、各事件的最晚发生时间(ltv[])，关键路径问题就解决了。
*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXVEX 100

typedef char VertexType;
typedef int EdgeType;

// 边表节点
typedef struct edgeNode {
    int adjvex;
    EdgeType weight;  // 比拓扑排序多了权值域wieght
    struct edgeNode * next;
} EdgeNode;

// 带入度的顶点表节点
typedef struct vertex {
    VertexType data;
    EdgeNode * firstedge;
    int in;  // 入度
} VertexNode;

typedef VertexNode AdjList[MAXVEX];  

// 最终定义图的邻接表结构
typedef struct {
    AdjList adjList;
    int numVex, numEdge;
} ALGraph;



// 全局变量
int * stack2;       // 存储拓扑序列
int top2 = -1;       // 栈的头指针

int etv[MAXVEX];    // 事件最早开始时间
int ltv[MAXVEX];    // 事件最晚开始时间


// 先求事件的最早发生时间（etv），这个时间由它前面事件和活动持续时间确定，
// 所以确定该时间的过程就是拓扑排序
bool TopologicalSort(ALGraph G) {
    int * stack; //动态存储入度为0的顶点
    int top = 0;
    //int top2 = 0; //栈的头指针
    int gettop; //接受出栈的元素
    EdgeNode * p; 
    int k;
    int count = 0;
    
    //分配内存空间
    stack = (int *)malloc(G.numVertexs * sizeof(int));
    stack2 = (int *)malloc(G.numVertexs * sizeof(int));
    if (stack == NULL || stack2 == NULL)
        return false;
    
    //找入度为0的点，顺带初始化etv
    for (int i = 0; i < G.numVertexs; i++) {
        if (G.vex[i].in == 0) {
            stack[++top] = i;
            stack2[++top2] = i; //存储起来
        }
        
        etv[i] = 0; //初始化
    }

    while(top) {
        gettop = stack[top--]; //出栈
        count++;
        //删弧
        p = G.vex[gettop].firstedge;
        while(p) {
            k = p->adjvex; //下标
            if (!(--G.vex[k].in)) {
                stack[++top] = k;
                stack2[++top2] = k; //继续存
            }
            //更新最早时间数组
            if (etv[gettop] + p->weight > etv[k]) {
                etv[k] = etv[gettop] + p->weight;
            }

            p = p->next;
        }
    }

    if(count < G.numVertexs)
        return false;
    else 
        return true;
}

//关键路径算法
void CriticalPath(ALGraph G)
{
    int ete; //活动最早开始时间
    int lte; //活动最晚开始时间
    int gettop;
    int k;
    EdgeNode * p;

    //调用拓扑函数
    TopologicalSort(G); 
    //初始化ltv
    for (int i = 0; i < G.numVertexs; i++) {
        ltv[i] = etv[G.numVertexs - 1]; //初始化为etv最后一个元素值
    }
    //更新ltv[]
    while (top2) {
        gettop = stack2[top2--]; //出栈
        p = G.vex[gettop].firstedge;
        while (p) {
            k = p->adjvex;
            if (ltv[k] - p->weight < ltv[gettop]) {
                ltv[gettop] = ltv[k] - p->weight;
            }
        }
    }
    //求每条弧的ete、lte
    for (int j = 0; j < G.numVertexs; j++) { //遍历每个顶点，j为弧(活动)的起点
        p = G.vex[j].firstedge;
        while (p) {
            k = p->adjvex; //k为弧(活动)的终点
            ete = etv[j]; //活动最早开始时间
            lte = ltv[k] - p->weight; //活动最晚开始时间
            if (ete == lte) { //找到关键活动
                printf("<v%d - v%d> length: %d\n",
                    G.vex[j].data, G.vex[k].data, p->weight);
            }
            p = p->next;
        }
    }

}
