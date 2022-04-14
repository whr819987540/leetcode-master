#include <vector>
#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#define MaxVertexNum 100 //最大顶点数
#define MaxEdgeNum 1000  // 最大边数
#define NotExists -1
using namespace std;

// 边集数组，更加适合对边的处理（比如kruskal-MST）
// 而不适合对顶点的处理
typedef char VertexType;
typedef int EdgeType;
typedef struct Edge
{
    int start;
    int end;
    EdgeType weight;
} Edge;
typedef struct Graph
{
    VertexType vex[MaxVertexNum]; // 顶点表
    vector<Edge> edge;            // 边表
    int vexNum, edgeNum;
    Graph() : vexNum(0), edgeNum(0) { edge.resize(MaxEdgeNum); }
} Graph;

// 无向有权图
class UndirectedWeightedGraph
{
private:
    Graph g;
    map<VertexType, int> my_map;
    static bool cmp(const Edge &a, const Edge &b)
    {
        cout << a.weight << " " << b.weight << endl;
        return a.weight < b.weight;
    }

public:
    UndirectedWeightedGraph()
    {
        // 顶点表初始化
        cout << "input vertex num: ";
        (cin >> g.vexNum).get();
        cout << "input the value of the vertex, like a:\n";
        for (int i = 0; i < g.vexNum; i++)
        {
            (cin.get(g.vex[i])).get();
            my_map[g.vex[i]] = i;
        }

        // 边表初始化
        char buf[4096];
        char a, b;
        int weight;
        cout << "input the edge, for example a b 10 means an edge between a and b, with the weight 10\n";
        while (1)
        {
            cin.getline(buf, 4096);
            if (memcmp(buf, "q", 2) == 0)
            {
                break;
            }
            sscanf(buf, "%c %c %d", &a, &b, &weight);
            Edge tmp;
            tmp.start = my_map[a], tmp.end = my_map[b], tmp.weight = weight;
            g.edge[g.edgeNum++] = tmp;
        }
    }
    void display_graph()
    {
        printf("start:\tend:\tweight:\n");
        for (int i = 0; i < g.edgeNum; i++)
        {
            printf("%d %c\t%d %c\t%d\n", g.edge[i].start, g.vex[g.edge[i].start],
                   g.edge[i].end, g.vex[g.edge[i].end], g.edge[i].weight);
        }
    }
};

int main()
{
    UndirectedWeightedGraph g;
    g.display_graph();
    // 9
    // 0
    // 1
    // 2
    // 3
    // 4
    // 5
    // 6
    // 7
    // 8
    // 0 1 10
    // 0 5 11
    // 1 2 18
    // 1 6 16
    // 1 8 12
    // 2 3 22
    // 2 8 8
    // 3 4 20
    // 3 6 24
    // 3 7 16
    // 3 8 21
    // 4 5 26
    // 4 7 7
    // 5 6 17
    // 6 7 19
}