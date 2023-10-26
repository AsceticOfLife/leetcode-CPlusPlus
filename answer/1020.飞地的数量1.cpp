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

    // 采用宽度优先搜索
    bool BFS(const vector<vector<int>> &grid, const int row, const int col) {
        bool flag = true; // 标志是否为飞地
        queue<pair<int, int>> que; // 队列实现先进先出
        que.push({row, col}); // 将当前结点入队
        visited[row][col] = true;
        count = 1;
        
        while (!que.empty()) {
            // 获取队首元素
            pair<int, int> cur = que.front();
            que.pop();

            // 遍历四个方向的点
            for (int i = 0; i < 4; i++) {
                // 获取下一个结点
                int next_row = cur.first + dir[i][0];
                int next_col = cur.second + dir[i][1];

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

                    // 将新结点入队
                    que.push({next_row, next_col});
                }
            } // end for i in range(4)
        } // end when que is empty


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
                    if (BFS(grid, i, j)) result += count;
                }
            }
        }

        return result;
    }
};
// @lc code=end

