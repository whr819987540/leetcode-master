#include <vector>
#include <iostream>
#include <cstring>
#include <map>
#define MaxVertexNum 100 //最大顶点数
using namespace std;

// 用邻接矩阵存储无向图，进行深度优先遍历
typedef char VertexType;
typedef int EdgeType;

// 图(顶点表、边表)
typedef struct Graph
{
    VertexType vex[MaxVertexNum];
    int edge[MaxVertexNum][MaxVertexNum]; // 要么存储0，要么存储1，表示有无连接关系
    int vexNum, edgeNum;
    Graph() : vexNum(0), edgeNum(0) {}
} Graph;

// 无向无权图
class UndirectedUnweightedGraph
{
private:
    Graph g;
    // 实际上用my_map和顶点表维护了外部值和内部值之间的映射
    map<VertexType, int> my_map;
    // 是否访问的标志位
    bool signal[MaxVertexNum];

public:
    UndirectedUnweightedGraph()
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
        cout << "input the edge, for example a b means an edge between a and b\n";
        char a, b;
        char buf[4096];
        while (1)
        {
            cin.getline(buf, 4096);
            if (memcmp(buf, "q", 2) == 0)
            {
                break;
            }
            sscanf(buf, "%c %c", &a, &b);
            g.edge[my_map[a]][my_map[b]] = 1;
            g.edge[my_map[b]][my_map[a]] = 1;
            g.edgeNum++;
        }
    }

    void display()
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
                printf("%d ", g.edge[i][j]);
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
};

int main()
{
    UndirectedUnweightedGraph g1;
    g1.display();
    g1.DFS();
    // 8
    // a
    // b
    // c
    // d
    // e
    // f
    // g
    // h
    // a b
    // a c
    // b d
    // b e
    // c f
    // c g
    // e h
}