/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */

// @lc code=start
class Solution {
public:
    int count;
    int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

    void DFS(const vector<vector<int>> &grid, const int row, const int col,
             vector<vector<bool>> &visited) {
        // 无终止条件

        // 遍历四个方向
        for (int i = 0; i < 4; ++i) {
            int next_r = row + dir[i][0];
            int next_c = col + dir[i][1];

            // 判断是否越界
            if (next_r < 0 || next_r >= grid.size() ||
                next_c < 0 || next_c >= grid[0].size()) {
                count++;
                continue;
            }

            // 判断是否为海洋
            if (grid[next_r][next_c] == 0) {
                count++;
                continue;
            }

            // 判断是否访问过
            if (visited[next_r][next_c]) continue;

            visited[next_r][next_c] = true;
            DFS(grid, next_r, next_c, visited);
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        count = 0;
        // 找到第一个陆地
        int i = 0, j = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (grid[i][j] == 1) goto tag;
            }
        }
        tag:
        if (i == m && j == n) return count;
        visited[i][j] = true; 
        DFS(grid, i, j, visited);

        return count;
    }
};
// @lc code=end

