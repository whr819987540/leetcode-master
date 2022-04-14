#include <vector>
#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <string>
#define MaxVertexNum 100 //最大顶点数
#define Infinity INT_MAX
using namespace std;

// 权值中不能出现负值
// 用邻接矩阵来存储有向带权图
// 可以求源点到所有顶点的最短路径和最短路径的长度
// 时间复杂度为v^2
// 如果要求源点到某个顶点的最短路径和最短路径的长度，也需要v^2
// 因为这个算法需要处理所有结点之后才能给出结果

typedef char VertexType;
typedef int EdgeType;
typedef struct Graph
{
    VertexType vex[MaxVertexNum];
    EdgeType edge[MaxVertexNum][MaxVertexNum];
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

class DirectedWeightedGraph
{
private:
    Graph g;
    map<VertexType, int> my_map;

public:
    DirectedWeightedGraph()
    {
        // 初始化顶点表
        cout << "input the vertex num:";
        (cin >> g.vexNum).get();
        cout << "input the vertex:\n";
        for (int i = 0; i < g.vexNum; i++)
        {
            cin.get(g.vex[i]).get();
            my_map[g.vex[i]] = i;
        }

        // 初始化边表
        cout << "input the edge, for example a b 10 means an edge from a to b with the weight 10:\n";
        char buf[4096];
        char a, b;
        int weight;
        while (1)
        {
            cin.getline(buf, 4096);
            if (memcmp(buf, "q", 2) == 0)
            {
                break;
            }
            sscanf(buf, "%c %c %d", &a, &b, &weight);
            g.edge[my_map[a]][my_map[b]] = weight;
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

    void dijkstra()
    {
        // 标识顶点是否被访问过
        bool *signal = new bool(g.vexNum);
        // 记录目前源点到各个点的最短路径
        EdgeType *length = new EdgeType(g.vexNum);
        // 记录最短路径(存顶点的索引)
        int *path = new int(g.vexNum);
        // 初始化
        signal[0] = true;
        length[0] = 0;
        for (int i = 1; i < g.vexNum; i++)
        {
            length[i] = g.edge[0][i];
        }
        int last = 0;
        for (int pointCnt = 1; pointCnt < g.vexNum; pointCnt++)
        {
            int minIndex = -1;
            int min = Infinity;
            for (int i = 0; i < g.vexNum; i++)
            {
                if (signal[i] == false && length[i] < min)
                {
                    minIndex = i;
                    min = length[minIndex];
                }
            }

            // 将局部最短的点设置为访问过
            signal[minIndex] = true;
            // 记录路径信息
            path[last] = minIndex;
            last = minIndex;
            // 利用新找到的点更新length
            for (int i = 0; i < g.vexNum; i++)
            {
                // 未被访问过；存在边（防溢出）
                if (signal[i] == false && g.edge[minIndex][i] != Infinity &&
                    length[minIndex] + g.edge[minIndex][i] < length[i])
                {
                    length[i] = length[minIndex] + g.edge[minIndex][i];
                }
            }
        }

        // 输出源点到各个点的最短路径长度
        printf("index\tponit\tlength\n");
        for (int i = 0; i < g.vexNum; i++)
        {
            printf("%d\t%c\t%d\t", i, g.vex[i], length[i]);
            cout << "path " << getPath(path, i) << endl;
        }
        delete[] signal;
        delete[] length;
    }

    string getPath(int *path, int des)
    {
        string res = "";
        int point = 0;
        while (point != des)
        {
            res += to_string(point) + "->";
            point = path[point];
        }
        res += to_string(des);
        return res;
    }
};

int main()
{
    DirectedWeightedGraph g;
    g.dijkstra();
    // 5
    // 1
    // 2
    // 3
    // 4
    // 5
    // 1 2 10
    // 1 5 5
    // 2 3 1
    // 2 5 2
    // 3 4 4
    // 4 1 7
    // 4 3 6
    // 5 2 3
    // 5 3 9
    // 5 4 2
}
