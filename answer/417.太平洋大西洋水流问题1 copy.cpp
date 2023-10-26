/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
public:
    int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1}; // 四个方向
    
    // 采用广度优先搜索
    void BFS(const vector<vector<int>> &heights, vector<vector<bool>> &visited, int row, int col) {
        if (visited[row][col]) return; // 如果已经访问过就返回

        queue<pair<int, int>> que;
        que.push({row, col});
        visited[row][col] = true;

        while (!que.empty()) {
            pair<int, int> cur = que.front();
            que.pop();

            // 遍历四个方向
            for (int i = 0; i < 4; i++) {
                // 下一个方向
                int next_row = cur.first + dir[i][0];
                int next_col = cur.second + dir[i][1];

                // 超出边界
                if (next_row < 0 || next_row >= heights.size() ||
                    next_col < 0 || next_col >= heights[0].size())
                    continue; 

                if (visited[next_row][next_col] || 
                    heights[next_row][next_col] < heights[cur.first][cur.second])
                    continue;

                que.push({next_row, next_col});
                visited[next_row][next_col] = true; // 入队立刻标记
        
            }

        } // end when que is empty
        
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false)); // 太平洋逆流可达矩阵
        vector<vector<bool>> altantic(m, vector<bool>(n, false)); // 大西洋逆流可达矩阵
        vector<vector<int>> result;
        
        // 从最左和最右开始
        for (int row = 0; row < m; row++) {
            BFS(heights, pacific, row, 0);
            BFS(heights, altantic, row, n - 1);
        }

        // 从最上和最下开始
        for (int col = 0; col < n; col++) {
            BFS(heights, pacific, 0, col);
            BFS(heights, altantic, m - 1, col);
        }

        // 将两个可达矩阵均为true的结点作为结果
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && altantic[i][j])
                    result.push_back({i, j});
            }
        }

        return result;
    }   
};
// @lc code=end

