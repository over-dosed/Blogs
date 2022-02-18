#include<iostream>
#include<vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) 
    {
        int size_row = matrix.size();
        int size_col = matrix[0].size();
        sum.resize(size_row + 1,vector<int>(size_col+1));
        for(int i = 0; i < size_row;i++)
        {
            for(int j = 0; j < size_col;j++)
            {
                sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) 
    {
        return sum[row2+1][col2+1] - sum[row1][col2+1] - sum[row2+1][col1] + sum[row1][col1];
    }
};