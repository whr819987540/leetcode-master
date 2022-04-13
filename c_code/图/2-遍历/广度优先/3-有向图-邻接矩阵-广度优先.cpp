#include <vector>
#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#define MaxVertexNum 100 //最大顶点数
using namespace std;

// 用邻接矩阵实现有向图的广度优先遍历

typedef char VertexType;
typedef int EdgeType;

typedef struct Graph
{
    VertexType vex[MaxVertexNum];
    EdgeType edge[MaxVertexNum][MaxVertexNum];
    int vexNum, edgeNum;
    Graph() { vexNum = 0, edgeNum = 0; }
} Graph;

class DirectedUnweightedGraph
{
private:
    Graph g;
    map<VertexType, int> my_map;
    bool signal[MaxVertexNum];

    void visit(int index)
    {
        printf("visit No:%d Vertex:%c\n", index, g.vex[index]);
    }

public:
    DirectedUnweightedGraph()
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
        cout << "input the edge, for example a b means an edge between a and b\n";
        while (1)
        {
            cin.getline(buf, 4096);
            if (memcmp(buf, "q", 2) == 0)
            {
                break;
            }
            sscanf(buf, "%c %c", &a, &b);
            g.edge[my_map[a]][my_map[b]] = 1;
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
                printf("%d ", g.edge[i][j]);
            }
            cout << endl;
        }
    }

    // 利用栈实现
    void BFS()
    {
        for (int i = 0; i < g.vexNum; i++)
        {
            signal[i] = false;
        }
        queue<int> my_queue;
        for (int i = 0; i < g.vexNum; i++)
        {
            if (signal[i] == true)
            {
                continue;
            }
            else
            {
                my_queue.push(i);
            }
            while (my_queue.empty() == false)
            {
                int index = my_queue.front();
                my_queue.pop();
                // 处理当前结点
                signal[index] = true, visit(index);
                // 当前结点指向的结点，且未被访问过
                for (int j = 0; j < g.vexNum; j++)
                {
                    if (g.edge[index][j] == 1 && signal[j] == false)
                    {
                        my_queue.push(j);
                    }
                }
            }
        }
    }
};

int main()
{
    DirectedUnweightedGraph g1;
    g1.display_graph();
    g1.BFS();
    // 6
    // 1
    // 2
    // 3
    // 5
    // 6
    // 7
    // 1 2
    // 1 5
    // 2 6
    // 3 6
    // 3 7
    // 5 2
}