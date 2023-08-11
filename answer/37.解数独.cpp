/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool IsValid(const vector<vector<char>> &board, const int row,
                 const int col, const char c) {
        // 判断同一行是否有字符c
        for (int j = 0; j < 9; ++j) {
            if (board[row][j] == c)
                return false;
        }
        // 判断同列是否有元素
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == c)
                return false;
        }
        // 判断3*3的方格内是否存在这个元素
        int start_row = (row / 3) * 3;
        int start_col = (col / 3) * 3;
        for (int i = start_row; i < start_row + 3; ++i) 
            for (int j = start_col; j < start_col + 3; ++j) 
                if (board[i][j] == c) return false;
        
        return true;
    }

    bool BackTrace(vector<vector<char>> &board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] != '.') continue;

                // 尝试填充1~9
                for (char c = '1'; c <= '9'; ++c) {
                    if (IsValid(board, row, col, c)) {
                        board[row][col] = c; // 填充字符c
                        if (BackTrace(board)) return true;
                        board[row][col] = '.';
                    }
                }
                // 对于(row, col)位置尝试了9个字符都没成功
                return false;
            }
        }

        // 遍历完所有位置但是没有返回false
        // 说明填充均是正确的
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        BackTrace(board);
    }
};
// @lc code=end

