/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
public:
    int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1}; // 四个方向
    bool pac, alt; // 表示是否能够到达两个海洋
    

    // 采用深度优先搜索
    void DFS(const vector<vector<int>> &heights, vector<vector<bool>> &visited, int row, int col) {
        // 遍历四个方向
        for (int i = 0; i < 4; i++) {
            // 下一个方向
            int next_row = row + dir[i][0];
            int next_col = col + dir[i][1];

            // 能够到达左边和上边
            if (next_row < 0 || next_col < 0) {
                pac = true;
                continue;
            }
            // 能够到达下边和右边
            if (next_row >= heights.size() || next_col >= heights[0].size()) {
                alt = true;
                continue;
            }

            // 如果已经发现两个海洋都能到达
            if (pac && alt) return;

            // 只有未访问过并且下一个节点的值小于当前结点才能继续搜索
            if (!visited[next_row][next_col] && 
                 heights[next_row][next_col] <= heights[row][col]) {
                visited[next_row][next_col] = true;
                DFS(heights, visited, next_row, next_col);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> visited; // 访问矩阵
        vector<vector<int>> result;

        // 遍历每一个结点尝试搜索到海洋
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                visited = vector<vector<bool>>(m, vector<bool>(n, false));
                pac = alt = false; // 初始化

                visited[i][j] = true; // 标记当前被访问过
                DFS(heights, visited, i, j); // 搜索
                if (pac && alt) result.push_back(vector<int>({i, j}));
            }
        }

        return result;
    }   
};
// @lc code=end

