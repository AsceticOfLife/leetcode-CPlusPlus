/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 表示四个方向
    vector<vector<bool>> visited;

    // 深度搜索
    void DFS(const vector<vector<char>> &grid, int row, int col) {
        // 遍历可以访问的四个方向
        for (int i = 0; i < 4; i++) {
            int next_row = row + dir[i][0];
            int next_col = col + dir[i][1];

            // 判断是否越界
            if (next_row < 0 || next_row >= grid.size() || next_col < 0 || next_col >= grid[0].size()) 
                continue;
            
            if (grid[next_row][next_col] == '1' && visited[next_row][next_col] == false) {
                visited[next_row][next_col] = true; // 表示已经加入当前岛屿
                DFS(grid, next_row, next_col); // 沿着这个新结点继续访问
            }
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        // 初始化访问地图
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    visited[i][j] = true;
                    DFS(grid, i, j);

                    // 更新完一个岛屿
                    result++;
                }
                
            }
        }

        return result;
    }
};
// @lc code=end

