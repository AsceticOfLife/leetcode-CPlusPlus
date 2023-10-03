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

    // 广度优先搜索
    void BFS(const vector<vector<char>> &grid, int row, int col) {
        // 使用一个队列保存剩余需要访问的结点
        queue<pair<int, int>> que;
        que.push({row, col}); // 将当前结点加入队列
        visited[row][col] = true; // 只要加入队列立马标记

        while (!que.empty()) {
            // 取出队列中的元素
            pair<int, int> cur = que.front();
            que.pop();
            int cur_row = cur.first;
            int cur_col = cur.second;

            // 遍历可以访问的四个方向
            for (int i = 0; i < 4; i++) {
                int next_row = cur_row + dir[i][0];
                int next_col = cur_col + dir[i][1];

                // 判断是否越界
                if (next_row < 0 || next_row >= grid.size() || next_col < 0 || next_col >= grid[0].size()) 
                    continue;
                
                if (grid[next_row][next_col] == '1' && visited[next_row][next_col] == false) {
                    que.push({next_row, next_col}); // 加入待访问结点
                    visited[next_row][next_col] = true; // 加入队列马上标记
                }
                        
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
                    BFS(grid, i, j);

                    // 更新完一个岛屿
                    result++;
                } 
            }
        }

        return result;
    }
};
// @lc code=end

