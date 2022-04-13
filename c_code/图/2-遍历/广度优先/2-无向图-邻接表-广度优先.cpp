#include <vector>
#include <iostream>
#include <cstring>
#include <map>
#include <queue>
#define MaxVertexNum 100 //最大顶点数
using namespace std;

// 用邻接表实现无向图的广度优先遍历

typedef char VertexType;
typedef int EdgeType;

// 边表的结点
typedef struct EdgeNode
{
    int index;
    EdgeType weight;
    EdgeNode *next;
    EdgeNode() { next = nullptr; }
} EdgeNode;

// 顶点表的结点
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
    Graph() { vexNum = 0, edgeNum = 0; }
} Graph;

class UndirectedUnweightedGraph
{
private:
    Graph g;
    map<VertexType, int> my_map;
    bool signal[MaxVertexNum];
    void insert(int first, int second)
    {
        EdgeNode *tmp = new EdgeNode;
        tmp->index = second;
        tmp->weight = 1;
        tmp->next = g.vex[first].head;
        g.vex[first].head = tmp;
    }

    void visit(int i)
    {
        printf("index:%d, vertex_value:%c\n", i, g.vex[i].vertex);
    }

public:
    UndirectedUnweightedGraph()
    {
        // 顶点表初始化
        cout << "input vertex num: ";
        (cin >> g.vexNum).get();
        cout << "input the value of the vertex, like a:\n";
        for (int i = 0; i < g.vexNum; i++)
        {
            cin.get(g.vex[i].vertex).get();
            my_map[g.vex[i].vertex] = i;
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
            // 无向图，所以插入两个结点
            insert(my_map[a], my_map[b]);
            insert(my_map[b], my_map[a]);
            g.edgeNum++;
        }
    }

    void display_graph()
    {
        for (int i = 0; i < g.vexNum; i++)
        {
            printf("index:%d, vertex_value:%c ->", i, g.vex[i].vertex);
            EdgeNode *tmp = g.vex[i].head;
            while (tmp)
            {
                printf(" %d %c|", tmp->index, g.vex[tmp->index].vertex);
                tmp = tmp->next;
            }
            cout << endl;
        }
    }

    // 广度优先遍历，类似于树的广度优先遍历（层序遍历）
    // 需要借助一个栈来记录结点的关系
    void BFS()
    {
        for (int i = 0; i < g.vexNum; i++)
        {
            signal[i] = false;
        }

        queue<int> my_queue;
        for (int i = 0; i < g.vexNum; i++)
        {
            if (signal[i] == true) // 访问过
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
                // 访问
                visit(index), signal[index] = true;
                // 将未被访问过且与当前结点关联的结点索引放入
                EdgeNode *tmp = g.vex[index].head;
                while (tmp)
                {
                    if (signal[tmp->index] == false)
                    {
                        my_queue.push(tmp->index);
                    }
                    tmp = tmp->next;
                }
            }
        }
    }

    ~UndirectedUnweightedGraph()
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
    UndirectedUnweightedGraph g1;
    g1.display_graph();
    g1.BFS();
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