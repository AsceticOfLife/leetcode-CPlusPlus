/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> result;

    bool IsValid(const int row, const int col, const vector<string> &board, int n)  {
        // 检查列
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q')
                return false;
        }

        // 检查左上斜线
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q')
                return false;
        }

        // 检查右上斜线
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void Backtrace(const int n, const int row, vector<string> &board) {
        // 终止条件
        if (row == n) {
            // row表示本层应该处理的行，从0开始计数
            result.push_back(board);
            return;
        }

        // 单层处理逻辑
        for (int col = 0; col < n; ++col) {
            // 根据限制条件判断是否合法
            if (IsValid(row, col, board, n)) {
                board[row][col] = 'Q'; // 放置皇后
                Backtrace(n, row + 1, board);
                board[row][col] = '.'; // 回溯
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        Backtrace(n, 0, board);

        return result;
    }
};
// @lc code=end

