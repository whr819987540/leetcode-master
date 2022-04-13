#include <vector>
#include <iostream>
#include <cstring>
#include <map>
#define MaxVertexNum 100 //最大顶点数
using namespace std;

// 用邻接表存储有向图，实现深度优先遍历

typedef char VertexType;
typedef int EdgeType;
// 边表结点
typedef struct EdgeNode
{
    int index;
    EdgeType weight;
    EdgeNode *next;
    EdgeNode() { next = nullptr; }
} EdgeNode;
// 顶点表结点
typedef struct VertexNode
{
    VertexType vertex;
    EdgeNode *head;
    VertexNode() { head = nullptr; }
} VertexNode;

typedef struct Graph
{
    VertexNode vex[MaxVertexNum];
    int vexNum, edgeNum;
    Graph()
    {
        vexNum = 0, edgeNum = 0;
    }
} Graph;

class DirectedUnweightedGraph
{
private:
    Graph g;
    map<VertexType, int> my_map;
    bool signal[MaxVertexNum];

public:
    DirectedUnweightedGraph()
    {
        // 初始化顶点表
        cout << "input the vertex num:";
        (cin >> g.vexNum).get();
        cout << "input the value of vertext, for example a\n";
        for (int i = 0; i < g.vexNum; i++)
        {
            (cin.get(g.vex[i].vertex)).get();
            my_map[g.vex[i].vertex] = i;
        }

        // 初始化边表
        cout << "input the edge, for example a b means an edge from a to b\n";
        char buf[4096], a, b;
        while (1)
        {
            cin.getline(buf, 4096);
            if (memcmp(buf, "q", 2) == 0)
            {
                break;
            }
            sscanf(buf, "%c %c", &a, &b);
            EdgeNode *tmp = new EdgeNode; // 注意这里不能使用EdgeNode *tmp;因为没有分配内存
            tmp->index = my_map[b];
            tmp->weight = 1;
            tmp->next = g.vex[my_map[a]].head;
            g.vex[my_map[a]].head = tmp;
            g.edgeNum++;
        }
    }

    void display_graph()
    {
        printf("vex num:%d, edge unm:%d\n", g.vexNum, g.edgeNum);
        for (int i = 0; i < g.vexNum; i++)
        {
            printf("%d %c->", i, g.vex[i].vertex);
            EdgeNode *tmp = g.vex[i].head;
            while (tmp)
            {
                printf(" %d %c|", tmp->index, g.vex[tmp->index].vertex);
                tmp = tmp->next;
            }
            cout << endl;
        }
    }

    void DFS()
    {
        // signal数组初始化
        for (int i = 0; i < g.vexNum; i++)
        {
            signal[i] = false;
        }
        for (int i = 0; i < g.vexNum; i++)
        {
            if (signal[i] == false)
            {
                DFS_func(i);
            }
        }
    }

    void DFS_func(int index)
    {
        // 处理当前结点
        signal[index] = true;
        visit(index);

        // 处理该结点指向的其他结点
        EdgeNode *tmp = g.vex[index].head;
        while (tmp)
        {
            // 需要检查结点是否访问过，否则如果有回路，将进入死循环
            if (signal[tmp->index] == false)
            {
                DFS_func(tmp->index);
            }
            tmp = tmp->next;
        }
    }

    void visit(int index)
    {
        printf("index:%d vertex_value%c\n", index, g.vex[index].vertex);
    }

    ~DirectedUnweightedGraph()
    {
        for (int i = 0; i < g.vexNum; i++)
        {
            EdgeNode *pwd, *tmp;
            pwd = g.vex[i].head;
            tmp = pwd;
            while (pwd)
            {
                pwd = pwd->next;
                delete tmp;
                tmp = pwd;
            }
        }
    }
};

int main()
{
    DirectedUnweightedGraph g1;
    g1.display_graph();
    g1.DFS();
    // 4
    // 0
    // 1
    // 2
    // 3
    // 0 3
    // 1 0
    // 1 2
    // 2 1
    // 2 0
}