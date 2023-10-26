/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */

// @lc code=start
class Solution {
public:
    // 父节点数组
    vector<int> father;
    
    // 初始化父节点数组
    void init(const int n) {
        father = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; ++i)
            father[i] = i;
    }

    // 查找根结点
    int find(int u) {
        // 路径压缩
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        init(n);

        vector<int> result;
        for (int i = 0; i < n; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];

            // 寻根
            u = find(u);
            v = find(v);
            // 如果根相同说明二者已经连通
            // 那么这条边就是多余的边
            if (u == v) {
                result = edges[i];
                continue;
            }
            // 如果根不同说明未连通
            // 添加到同一并查集中
            father[v] = u;
        }

        return result;
    }
};
// @lc code=end

