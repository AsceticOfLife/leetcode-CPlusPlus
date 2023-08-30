/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    // 使用回溯递归
    int result;

    void TraceBack(const int m, const int n, int row, int col) {
        // 递归终止条件
        // if (row == m || col == n) return; // 越界
        if (row == m - 1 && col == n -1) {
            // 到达终点
            result++;
            return;
        }

        // 尝试向右移动
        // 在这里检查列是否越界，可以省去一层递归
        if (col + 1 < n) TraceBack(m, n, row, col + 1);
        if (row + 1 < m) TraceBack(m, n, row + 1, col);
    }


    int uniquePaths(int m, int n) {
        result = 0;
        TraceBack(m, n, 0, 0);

        return result;
    }
};
// @lc code=end

