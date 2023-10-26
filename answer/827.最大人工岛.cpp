/*
 * @lc app=leetcode.cn id=827 lang=cpp
 *
 * [827] 最大人工岛
 */

// @lc code=start
class Solution {
public:
    int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1}; // 四个方向
    int count; // 当前遍历的陆地数目
    vector<vector<bool>> visited; // 是否被访问过

    void DFS(vector<vector<int>> &grid, const int row, const int col, const int mark) {
        for (int i = 0; i < 4; ++i) {
            int next_r = row + dir[i][0];
            int next_c = col + dir[i][1];

            // 判断是否超出边界
            if (next_r < 0 || next_r >= grid.size() ||
                next_c < 0 || next_c >= grid[0].size())
                continue;

            // 如果被访问过或者不是陆地
            if (visited[next_r][next_c] || grid[next_r][next_c] == 0)
                continue;
            
            visited[next_r][next_c] = true; // 标记被访问过
            count++; // 陆地数目加1
            grid[next_r][next_c] = mark; // 陆地编号
            DFS(grid, next_r, next_c, mark);
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(); // 题目中说明行列相等且均大于等于1
        bool all_island = true; // 是否全部为岛屿

        // 第一步，记录所有当前陆地面积
        unordered_map<int, int> map; // 记录每个标记的陆地面积
        visited = vector<vector<bool>>(n, vector<bool>(n, false));
        int mark = 2; // 初始化标记
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) all_island = false; // 存在海洋所以不是全部为岛屿

                if (visited[i][j] || grid[i][j] == 0) continue; // 不是陆地
                
                
                visited[i][j] = true; // 标记为被访问过
                count = 1; // 初始化陆地数目
                grid[i][j] = mark; // 当前结点设置为编号
                DFS(grid, i, j, mark);

                map[mark] = count; // 记录当前编号的陆地数目
                mark++; // 陆地编号递增
            }
        }
        
        if (all_island) return n * n; // 如果全部是岛屿

        // 第二步，尝试将所有的0进行修改
        unordered_set<int> visited_island; // 记录周围的陆地编号
        int result = 0; // 最终结果
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 0) continue; // 如果不是0就跳过

                count = 1; // 修改之后陆地数目暂时为1
                visited_island.clear(); // 清空陆地编号
                // 同样遍历四个方向
                for (int k = 0; k < 4; ++k) {
                    int nexti = i + dir[k][0];
                    int nextj = j + dir[k][1];

                    // 判断是否越界
                    if (nexti < 0 || nexti >= n ||
                        nextj < 0 || nextj >= n) continue;
                    
                    // 判断是否为陆地
                    int m = grid[nexti][nextj];
                    if (m == 0) continue;

                    // 判断是否已经记录过相同编号的陆地
                    if (visited_island.count(m)) continue;

                    // 添加周围的陆地
                    count += map[m];
                    visited_island.insert(m);
                }

                result = max(result, count);
            }
        } // end when i == n

        return result;
    }
};
// @lc code=end

