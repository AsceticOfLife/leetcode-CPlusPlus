/*
 * @lc app=leetcode.cn id=1020 lang=cpp
 *
 * [1020] 飞地的数量
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int count; // 相连的陆地数目
    vector<vector<bool>> visited; // 访问矩阵
    int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1}; // 方向信息

    // 采用深度优先搜索
    bool DFS(const vector<vector<int>> &grid, const int row, const int col) {
        bool flag = true; // 标志是否为飞地
        
        // 遍历四个方向的结点
        for (int i = 0; i < 4; i++) {
            int next_row = row + dir[i][0];
            int next_col = col + dir[i][1];

            // 判断下一个结点是否能够越界，越界则说明这块土地不是飞地
            if (next_row < 0 || next_row >= grid.size() ||
                next_col < 0 || next_col >= grid[0].size()) {
                flag = false; // 不立即返回，而是遍历完整块土地再返回
                continue;
            }
                
            
            // 如果是一块没有被访问过的土地
            if (!visited[next_row][next_col] && grid[next_row][next_col] == 1) {
                visited[next_row][next_col] = true;
                count++; // 连接土地数加1

                // 对于这个新土地继续进行搜索
                // 如果搜索结果发现相邻土地不是飞地
                // 那么整块连接土地均不是飞地
                flag &= DFS(grid, next_row, next_col);
            }
        }

        return flag;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        // 初始化访问矩阵
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        int result = 0; // 飞地的土地数目

        // 遍历所有网格
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    visited[i][j] = true;
                    count = 1; // 初始化土地数目

                    if (DFS(grid, i, j)) result += count;
                }
            }
        }

        return result;
    }
};
// @lc code=end

