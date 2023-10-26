/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int count;
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 表示四个方向

    // 采用深度优先搜索
    void dfs(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col) {
        // 遍历可以访问的四个方向
        for (int i = 0; i < 4; i++) {
            // 下一个访问结点的下标
            int next_row = row + dir[i][0];
            int next_col = col + dir[i][1];
            
            // 判断是否越界
            if (next_row < 0 || next_row >= grid.size() || next_col < 0 || next_col >= grid[0].size())
                continue;

            // 如果没有被访问过并且表示土地
            if (!visited[next_row][next_col] && grid[next_row][next_col] == 1) {
                visited[next_row][next_col] = true; // 表示已经访问过
                count++;

                // 对于这个结点继续深度优先搜索
                dfs(grid, visited, next_row, next_col);
            }

        } // end of for i in range(4)

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // 初始化访问矩阵
        // 表示二维网格点是否被访问过
        vector<vector<bool>> visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        int result = 0;

        // 遍历所有的网格寻找一块土地
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    // 如果是土地并且没有被访问过
                    visited[i][j] = true;
                    count = 1;
                    dfs(grid, visited, i, j);

                    result = max(result, count);
                }
            }
        }

        return result;
    }
};
// @lc code=end

