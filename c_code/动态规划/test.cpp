#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void gap()
{
    cout << "-------------\n";
}
int main()
{
    {
        // 初始化为row*column的矩阵，不指定初始值
        int row = 3, column = 4;
        vector<vector<int>> matrix(row, vector<int>(column));
        for (auto outer : matrix)
        {
            for (auto inner : outer)
            {
                cout << inner << " ";
            }
            cout << endl;
        }
        cout << "--------\n";
    }

    {
        // 初始化为row*column的矩阵，指定初始值
        int row = 3, column = 4;
        int init = 5;
        vector<vector<int>> matrix(row, vector<int>(column, init));
        for (auto outer : matrix)
        {
            for (auto inner : outer)
            {
                cout << inner << " ";
            }
            cout << endl;
        }
        cout << "--------\n";
    }

    {
        // 初始化为row*column的矩阵，逐行初始化，指定初始值
        int row = 3, column = 4;
        int init = 5;
        vector<vector<int>> matrix;
        matrix.resize(row); //确定行数
        // 逐行确定列数
        for (int i = 0; i < row; i++)
        {
            matrix[i].resize(column);
        }

        for (auto outer : matrix)
        {
            for (auto inner : outer)
            {
                cout << inner << " ";
            }
            cout << endl;
        }
        cout << "--------\n";
    }
    {
        // 一维数组初始化，指定个数和初始值
        vector<int> data(3, 2);
        for (auto i : data)
        {
            cout << i << " ";
        }
        cout << endl;
        gap();
    }
    {
        // 一维数组初始化，指定序列值
        vector<int> data{1, 2, 3};
        for (auto i : data)
        {
            cout << i << " ";
        }
        cout << endl;
        gap();
    }
}