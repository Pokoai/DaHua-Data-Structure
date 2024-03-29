/*
 * @Description: 《大话数据结构》无环图的拓扑排序
 * @Author: Adair Hu
 * @WebSite: https://arctee.cn
 * @Github: https://github.com/pokoai
 * @Date: 2021-10-15 14:45:00
 * @FilePath: \DaHua\Chapter7_Graph\09TopologicalSort.c
 * 『戒急戒躁，心装大盘。日日耕耘，精进成长。』
 */

/*拓扑排序目的：
在各为各的前提条件的无环复杂网络中，
如何在不违背所有前提条件的情况下，把各个事件依次排好序，这就是拓扑排序的目的。

拓扑排序思路：
依次找出入度为0（即没有前提条件了）的顶点（事件），然后执行该事件，并删除以该点为弧尾的弧（即弧头顶点入度减1）
为了避免每次循环遍历，则将入度为0的顶点保存到栈中，后续从栈中取出
*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_VEX 20

typedef int VertexType;
typedef int EdgeType;

//边表结点
typedef struct edgeNode {
    int adjvex;
    EdgeType weight;
    struct edgeNode * next;
}EdgeNode;

//顶点类型
typedef struct vertex {
    int in;
    VertexType data;
    EdgeNode * firstedge;
}Vertex;

//邻接表
typedef struct {
    Vertex vex[MAX_VEX]; //顶点数组
    int numVertexs, numEdges;
}ALGraph; //构建完成


//拓扑排序
bool TopologicalSort(ALGraph G)
{
    int * stack; //构造一个栈，存储入度为0的顶点下标，以免每次遍历查询
    int top = 0; //栈顶指针，从数组下标为1处开始存储
    int count = 0; //记录入度为0的顶点数量

    stack = (int *)malloc(G.numVertexs * sizeof(int)); //为栈分配内存空间
    if (!stack) 
        return false;
    
    //首次还是要遍历查询一次入度为0的顶点的
    for (int i = 0; i < G.numVertexs; i++) {
        if (0 == G.vex[i].in) {
            stack[++top] = i; //入栈
        }
    }

    //开始
    int gettop;
    int k;
    EdgeNode * p;
    while (top) {
        gettop = stack[top--]; //出栈
        printf("%d -> ", G.vex[gettop].data);
        count++;

        //删除以此顶点为尾的弧
        p = G.vex[gettop].firstedge;
        while (p) {
            k = p->adjvex;
            if (!(--G.vex[k].in)) //首先--减一个入度，若减为0了就入栈
                stack[++top] = k; //顶点下标入栈
            //更新p
            p = p->next;
        }

    }
    if (count < G.numVertexs) {
        pritnf("有环图");
        return false;
    }
    else {
        return true;
    }
}
