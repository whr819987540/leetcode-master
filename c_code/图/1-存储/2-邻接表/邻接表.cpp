#include <vector>
#include <iostream>
#include <cstring>
#define MaxVertexNum 100 //最大顶点数
using namespace std;

// 顶点表为一维数组
// 边表为链表

// 顶点数据类型
typedef int VertexType;
// 边数据类型
typedef int EdgeType;

// 边表元素
typedef struct EdgeNode
{
    int index;       // 这条边指向的结点在顶点表的索引
    EdgeType weight; //相当于是边的权重，由于链表已经记录了连接关系，所以在无权图中该字段没有用
    EdgeNode *next;  //指向下一个结点
} EdgeNode;

// 顶点表元素
typedef struct VertexNode
{
    VertexType vertex; // 顶点的信息
    EdgeNode *head;    // 指向边表的头结点
} VertexNode;

// 图
typedef struct Graph
{
    VertexNode vex[MaxVertexNum];
    int vexNum, edgeNum;
} Graph;

// 无向无权图
class UndirectedUnweightedGraph
{
private:
    Graph g;
    // first、second表示边的两个结点的索引
    void insert(int first, int second)
    {
        EdgeNode *tmp;
        tmp = new EdgeNode;
        tmp->index = second;
        tmp->weight = 1;
        tmp->next = g.vex[first].head;
        g.vex[first].head = tmp;
    }

public:
    UndirectedUnweightedGraph()
    {
        // 初始化顶点表
        cout << "input the vertex num:";
        (cin >> (g.vexNum)).get();
        for (int i = 0; i < g.vexNum; i++)
        {
            g.vex[i].vertex = i;
            g.vex[i].head = nullptr;
        }

        // 初始化边表
        char buf[4096];
        cout << "input the edge, for example '1 2', which means there is an edge between 1 and 2. input q to quit\n";
        while (1)
        {
            cin.getline(buf, 4096);
            if (memcmp(buf, "q", 1) == 0)
            {
                break;
            }
            else
            {
                int first, second;
                sscanf(buf, "%d %d", &first, &second);
                // 无向图，插入两次；采用头插法
                insert(first, second);
                insert(second, first);
                g.edgeNum++;
            }
        }
    }

    void display_graph()
    {
        printf("vexNum:%d,edgeNum:%d\n", g.vexNum, g.edgeNum);
        for (int i = 0; i < g.vexNum; i++)
        {
            EdgeNode *tmp = g.vex[i].head;
            printf("%d->", i);
            while (tmp)
            {
                printf(" %d", tmp->index);
                tmp = tmp->next;
            }
            cout << endl;
        }
    }

    // 释放new的EdgeNode
    ~UndirectedUnweightedGraph()
    {
        for (int i = 0; i < g.vexNum; i++)
        {
            EdgeNode *pwd = g.vex[i].head;
            EdgeNode *tmp = pwd;
            while (pwd)
            {
                pwd = pwd->next;
                delete tmp;
                tmp = pwd;
            }
        }
    }
};

// 有向无权图
class DirectedUnweightedGraph
{
private:
    Graph g;
    // 向边表插入结点,采用头插法
    void insert(int start, int end)
    {
        EdgeNode *tmp = new EdgeNode;
        tmp->index = end;
        tmp->next = g.vex[start].head;
        tmp->weight = 1;

        g.vex[start].head = tmp;
    }

public:
    // 顶点表和边表初始化
    DirectedUnweightedGraph()
    {
        // 顶点表初始化
        cout << "input the vertex num:";
        (cin >> g.vexNum).get();
        for (int i = 0; i < g.vexNum; i++)
        {
            g.vex[i].vertex = i;
            g.vex[i].head = nullptr;
        }

        // 边表初始化
        cout << "input the edge, for example '1 2', which means there is an edge from 1 to 2. input q to quit\n";
        char buf[4096];
        while (1)
        {
            cin.getline(buf, 4096);
            if (memcmp(buf, "q", 1) == 0)
            {
                break;
            }
            else
            {
                int start, end;
                sscanf(buf, "%d %d", &start, &end);
                insert(start, end);
                g.edgeNum++;
            }
        }
    }

    void display_graph()
    {
        printf("vexNum:%d,edgeNum:%d\n", g.vexNum, g.edgeNum);
        for (int i = 0; i < g.vexNum; i++)
        {
            EdgeNode *tmp = g.vex[i].head;
            printf("%d->", i);
            while (tmp)
            {
                printf(" %d", tmp->index);
                tmp = tmp->next;
            }
            cout << endl;
        }
    }

    // 释放new的EdgeNode
    ~DirectedUnweightedGraph()
    {
        for (int i = 0; i < g.vexNum; i++)
        {
            EdgeNode *pwd = g.vex[i].head;
            EdgeNode *tmp = pwd;
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
    // UndirectedUnweightedGraph g1;
    // g1.display_graph();
    // 测试数据
    // 6
    // 1 2
    // 1 5
    // 5 2
    // 5 4
    // 2 3
    // 2 4
    // 4 3

    DirectedUnweightedGraph g2;
    g2.display_graph();
    // 7
    // 1 2
    // 1 4
    // 4 2
    // 2 5
    // 5 4
    // 3 5
    // 3 6
    // 6 6
}