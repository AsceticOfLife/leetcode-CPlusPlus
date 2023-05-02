/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class NumMatrix {
public:
    vector<vector<int>> preSum;
public:
    NumMatrix(vector<vector<int>>& matrix) : preSum(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0)) {
        int rows = matrix.size() + 1;
        int cols = matrix[0].size() + 1;

        
        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                preSum[r][c] = preSum[r - 1][c] + preSum[r][c - 1] + matrix[r - 1][c - 1] - preSum[r - 1][c - 1];
            } // end inner for
        } // end outer for
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2 + 1][col2 + 1] - preSum[row1][col2 + 1] - preSum[row2 + 1][col1] + preSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
