/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1}; // 四个方向
    // 深度优先搜索
    void DFS(vector<vector<char>> &board, const int row, const int col) {
        // 将当前结点设置为A
        // 只有O结点才能进入这个函数
        board[row][col] = 'A';

        // 遍历四个方向
        for (int i = 0; i < 4; i++) {
            // 确定下一个连接的结点
            int next_row = row + dir[i][0];
            int next_col = col + dir[i][1];

            // 判断是否超出边界
            if (next_row < 0 || next_row >= board.size() || 
                next_col < 0 || next_col >= board[0].size())
                continue;

            // 如果不是O直接跳过
            if (board[next_row][next_col] == 'A' || board[next_row][next_col] == 'X')
                continue;

            DFS(board, next_row, next_col);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        // 第一步从四个边界出发，将所有与边界相连的O设置为A
        // 从左右两个边界
        for (int row = 0; row < m; ++row) {
            if (board[row][0] == 'O') DFS(board, row, 0);
            if (board[row][n - 1] == 'O') DFS(board, row, n - 1);
        }

        // 从上下两个边界开始
        for (int col = 0; col < n; ++col) {
            if (board[0][col] == 'O') DFS(board, 0, col);
            if (board[m - 1][col] == 'O') DFS(board, m - 1, col);
        }

        // 第二步遍历所有的网格，将A设置为O，将O设置为X
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
};
// @lc code=end

