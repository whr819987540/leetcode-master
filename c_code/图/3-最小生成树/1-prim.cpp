#include <vector>
#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#define MaxVertexNum 100 //最大顶点数
#define Infinity INT_MAX // 表示两个顶点之间不存在路径
#define Selected -1      // 表示顶点已经被选过
using namespace std;

// 求一个无向有权图的最小生成树
// 前提：
// 1、无向有权图
// 2、连通图
// 利用的性质：最小生成树一定包含权值最小的边

// 用prim算法来求解，针对顶点的运算，适合用邻接矩阵来存储
// 复杂度为v^2，适合稠密图（而kruskal适合稀疏图，eloge）

// 用邻接矩阵存储无向有权图
typedef char VertexType;
typedef int EdgeType;

// 图(顶点表、边表)
typedef struct Graph
{
    VertexType vex[MaxVertexNum];              // 顶点信息
    EdgeType edge[MaxVertexNum][MaxVertexNum]; // 权值
    int vexNum, edgeNum;
    Graph() : vexNum(0), edgeNum(0)
    {
        for (int i = 0; i < MaxVertexNum; i++)
        {
            for (int j = 0; j < MaxVertexNum; j++)
            {
                edge[i][j] = Infinity;
            }
        }
    }
} Graph;

// 无向有权图
class UndirectedWeightedGraph
{
private:
    Graph g;
    // 实际上用my_map和顶点表维护了外部值和内部值之间的映射
    map<VertexType, int> my_map;
    // 是否访问的标志位
    bool signal[MaxVertexNum];
    void DFS_func(int index)
    {
        // 访问顶点index
        signal[index] = true;
        visit(index);

        // 访问和index相邻的顶点
        for (int i = 0; i < g.vexNum; i++)
        {
            if (g.edge[index][i] == 1 && signal[i] == false)
            {
                DFS_func(i);
            }
        }
    }

    void visit(int index)
    {
        printf("visit No%d Vertex:%c\n", index, g.vex[index]);
    }

public:
    UndirectedWeightedGraph()
    {
        // 顶点表初始化
        cout << "input the vertex num:";
        (cin >> g.vexNum).get();
        cout << "input the value of vertext, for example a\n";
        for (int i = 0; i < g.vexNum; i++)
        {
            cin.get(g.vex[i]).get();
            // 建立VertexType到index的映射，不用关心具体的映射怎样
            my_map[g.vex[i]] = i;
        }

        // 边表初始化
        cout << "input the edge, for example a b 10 means an edge between a and b, with the weight 10\n";
        char a, b;
        int weight;
        char buf[4096];
        while (1)
        {
            cin.getline(buf, 4096);
            if (memcmp(buf, "q", 2) == 0)
            {
                break;
            }
            sscanf(buf, "%c %c %d", &a, &b, &weight);
            g.edge[my_map[a]][my_map[b]] = weight;
            g.edge[my_map[b]][my_map[a]] = weight;
            g.edgeNum++;
        }
    }

    void display_graph()
    {
        printf("vertex num:%d, edge num:%d\n ", g.vexNum, g.edgeNum);
        for (int i = 0; i < g.vexNum; i++)
        {
            printf(" %c", g.vex[i]);
        }
        cout << endl;

        for (int i = 0; i < g.vexNum; i++)
        {
            printf("%c ", g.vex[i]);
            for (int j = 0; j < g.vexNum; j++)
            {
                if (g.edge[i][j] == Infinity)
                {
                    printf("M ");
                }
                else
                {
                    printf("%d ", g.edge[i][j]);
                }
            }
            cout << endl;
        }
    }

    // 深度优先遍历
    void DFS()
    {
        for (int i = 0; i < g.vexNum; i++)
        {
            signal[i] = false;
        }

        for (int i = 0; i < g.vexNum; i++)
        {
            // 以i为起点的过程中可能会修改别的顶点的标志位
            // 所以要加判断
            // 这里也给出判断是否是连通图的方式：
            // 从某个顶点出发进行深度/广度优先遍历，如果能访问到所有顶点，那么一定是连通图
            // 对于程序而言，就是去掉for循环，然后检查signal是否都是true
            if (signal[i] == false)
            {
                DFS_func(i);
            }
        }
    }

    // prim构建最小生成树
    // 从原图的顶点集中选中一个顶点放入MST的顶点集
    // 在未选中顶点集和选中顶点集之间找到一条最短边，并把该边的顶点加入选中顶点集
    // 重复上述过程，知道选中顶点集和顶点数==原图中的顶点数
    void PrimMST()
    {
        // lowcost[i]表示某个点到i的最短距离
        // 如果该点已经被选中，后续不应该再被考虑，所以被置为Selected(-1)
        EdgeType lowcost[MaxVertexNum];
        // adjvex[i]表示lowcost中边的另一个顶点
        int adjvex[MaxVertexNum];
        // 先选中0点
        lowcost[0] = Selected;
        adjvex[0] = 0;
        for (int i = 1; i < g.vexNum; i++)
        {
            lowcost[i] = g.edge[0][i];
            adjvex[i] = 0;
        }

        int sum = 0; //权重之和
        // 找到g.vexNum个顶点
        for (int pointCnt = 1; pointCnt < g.vexNum; pointCnt++)
        {
            // 在lowcost数组中找到最小值
            int minIndex = -1;
            int min = Infinity;
            for (int j = 0; j < g.vexNum; j++)
            {
                // 点未被选中且可以被更新
                if (lowcost[j] != Selected && lowcost[j] < min)
                {
                    minIndex = j;
                    min = lowcost[minIndex];
                }
            }
            // 输出这条边
            printf("%d->%d\n", adjvex[minIndex], minIndex);

            // 将该点放入
            sum += min;
            lowcost[minIndex] = Selected;

            // 更新lowcost和adjvex
            for (int j = 0; j < g.vexNum; j++)
            {
                // j未被选中
                if (lowcost[j] != Selected && g.edge[minIndex][j] < lowcost[j])
                {
                    lowcost[j] = g.edge[minIndex][j];
                    adjvex[j] = minIndex;
                }
            }
        }
        printf("min weight:%d\n", sum);
    }
};

int main()
{
    UndirectedWeightedGraph g;
    g.display_graph();
    g.PrimMST();
    // 6
    // 1
    // 2
    // 3
    // 4
    // 5
    // 6
    // 1 2 6
    // 1 3 1
    // 1 4 5
    // 2 3 5
    // 2 5 3
    // 3 4 5
    // 3 5 6
    // 3 6 4
    // 4 6 2
    // 5 6 6
}