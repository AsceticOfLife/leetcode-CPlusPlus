/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
class Solution {
public:
    vector<int> father; // 父节点数组

    // 初始化父节点数组
    void init(int n) {
        father = vector<int>(n + 1, 0);
        for (int i = 1; i <= n; i++)
            father[i] = i;
    }

    // 查询根结点
    int find(int u) {
        // 路径压缩
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    // 合并
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        father[v] = u;
    }

    // 判断两个元素是否有同一个根
    bool isSame(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

    // 判断删除下标为i的边之后是否为一颗树
    bool isTreeAfterRemoveEdges(vector<vector<int>> &edges, int index) {
        // 初始化并查集
        int n = edges.size();
        init(n);
        for (int i = 0; i < n; i++) {
            if (i == index) continue;
            int u = edges[i][0];
            int v = edges[i][1];
            // 如果还没添加边时出现根相同
            // 说明加入这条边会形成有向环
            // 因此不是一棵树
            if (isSame(u, v)) return false;
            join(u, v);
        }

        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // 首先统计每个结点的入度
        vector<int> indegree(n + 1, 0);
        // 统计每个边的后一个结点的入度
        for (int i = 0; i < n; i++) {
            indegree[edges[i][1]]++;
        }
        // 查找入度为2的结点对应的边
        vector<int> index;
        for (int i = n - 1; i >= 0; i--) {
            if (indegree[edges[i][1]] == 2)
                index.push_back(i);
        }
        if (index.size() > 0) {
            if (isTreeAfterRemoveEdges(edges, index[0]))
                return edges[index[0]];
            else return edges[index[1]];
        }

        // 如果没有出现入度为2的结点
        // 那么一定是出现了有向环
        init(n);
        for (int i = 0; i < n; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (isSame(u, v)) return edges[i];

            join(u, v);
        }
        
        return {};
    }
};
// @lc code=end

