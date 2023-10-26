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

    // 采用宽度优先搜索
    void BFS(const vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col) {
        // 使用队列保存剩余可遍历的结点
        queue<pair<int, int>> que;
        que.push(pair<int, int>(row, col)); // 将当前结点入队
        visited[row][col] = true; // 入队之后立马标记
        
        while (!que.empty()) {
            // 取出队列首元素
            pair<int, int> cur = que.front();
            que.pop();
            int cur_row = cur.first;
            int cur_col = cur.second;

            // 遍历当前结点可以访问的四个方向
            for (int i = 0; i < 4; i++) {
                int next_row = cur_row + dir[i][0];
                int next_col = cur_col + dir[i][1];

                // 判断是否越界
                if (next_row < 0 || next_row >= grid.size() || 
                    next_col < 0 || next_col >= grid[0].size())
                    continue;
                
                // 找到一个岛屿并且没有被访问过
                if (!visited[next_row][next_col] && grid[next_row][next_col] == 1) {
                    // 标记为被访问过并加入队列
                    visited[next_row][next_col] = true;
                    que.push({next_row, next_col});
                    count++; // 陆地数加1
                }
            }
        } // end when queue is empty


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
                    count = 1;
                    BFS(grid, visited, i, j);

                    result = max(result, count);
                }
            }
        }

        return result;
    }
};
// @lc code=end

