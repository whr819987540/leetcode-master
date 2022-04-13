#include <vector>
#include <iostream>
#include <cstring>
#define MaxVertexNum 100 //最大顶点数

using namespace std;

// 需要一个一维数组来记录顶点信息
// 需要一个二维数组来记录边信息
// 可以分为四种类型：1）无向无权图 2）无向有权图 3）有向无权图 4）有向有权图
// 无向图，二维数组是对称的；有向图，二维数组不对称
// 无权图，如果顶点相邻，二维数组的值为1，否则为0；有权图，如果顶点相邻，二维数组的值为权重，否则为0

// 定义一维数组的数据类型，即顶点的数据类型
typedef int VertexType;
// 定义二维数组的数据类型，即边的数据类型
typedef int EdgeType;
// 图中存储以上两个数组和顶点数、边数
typedef struct Graph
{
    VertexType vex[MaxVertexNum];              //顶点表
    EdgeType edge[MaxVertexNum][MaxVertexNum]; // 边表
    int vexNum, edgeNum;                       // 当前的顶点数和边数
} Graph;

// 无向无权图
// 边表为0表示有边，为1表示没边
class UndirectedUnweightedGraph
{
private:
    Graph g;

public:
    UndirectedUnweightedGraph()
    {
        // 初始化顶点表
        cout << "input the vertex num:";
        // 读到整形变量中时，cin不会处理结尾的换行符，所以还需要cin.get()一次
        (cin >> g.vexNum).get();
        for (int i = 0; i < g.vexNum; i++)
        {
            g.vex[i] = i;
        }

        // 初始化边表
        cout << "input the edge, for example '1 2', which means there is an edge between 1 and 2. input q to quit\n";
        char buf[4096];
        while (1)
        {
            // cin.get()遇到空白字符就停止输入，所以用getline
            cin.getline(buf, 4095);
            if (memcmp(buf, "q", 1) == 0)
            {
                break;
            }
            else
            {
                int first, second;
                sscanf(buf, "%d %d", &first, &second);
                if (g.edge[first][second] == 0)
                {
                    g.edgeNum++;
                }
                // 注意插入一条表时，要修改两个位置的值
                g.edge[first][second] = 1;
                g.edge[second][first] = 1;
            }
        }
    }
    void display_graph()
    {
        printf("vexNum:%d,edgeNum:%d\n", g.vexNum, g.edgeNum);
        for (int i = 0; i < g.vexNum; i++)
        {
            for (int j = 0; j < g.vexNum; j++)
            {
                cout << g.edge[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// 无向有权图
class UndirectedWeightedGraph
{
};

// 有向无权图
class DirectedUnweightedGraph
{
private:
    Graph g;

public:
    DirectedUnweightedGraph()
    {
        // 初始化顶点表
        cout << "input the vertex num:";
        (cin >> g.vexNum).get();
        // 初始化边表
        cout << "input the edge, for example '1 2', which means there is an edge from 1 to 2. input q to quit\n";
        char buf[4096];
        while (1)
        {
            cin.getline(buf, 4095);
            if (memcmp(buf, "q", 1) == 0)
            {
                break;
            }
            else
            {
                int start, end;
                sscanf(buf, "%d %d", &start, &end);
                // 防止重复输入
                if (g.edge[start][end] == 0)
                {
                    g.edgeNum++;
                }
                g.edge[start][end] = 1;
            }
        }
    }
    void display_graph()
    {
        printf("vexNum:%d,edgeNum:%d\n", g.vexNum, g.edgeNum);
        for (int i = 0; i < g.vexNum; i++)
        {
            for (int j = 0; j < g.vexNum; j++)
            {
                cout << g.edge[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// 有向有权图
class DirectedWeightedGraph
{
};

int main()
{
    UndirectedUnweightedGraph g1;
    g1.display_graph();

    DirectedUnweightedGraph g3;
    g3.display_graph();
}