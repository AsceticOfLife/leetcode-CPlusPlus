/*
 * @lc app=leetcode.cn id=1971 lang=cpp
 *
 * [1971] 寻找图中是否存在路径
 */

// @lc code=start
class Solution {
public:
    vector<int> father; // 父节点

    // 创建具有n各节点的并查集树状结构
    void init(int n) {
        father = vector<int>(n, 0);
        // 初始化
        for (int i = 0; i < n; ++i)
            father[i] = i; // 每个节点的父亲都是自己
    }

    // 寻根过程
    int find(int u) {
        // 路径压缩
        return u == father[u] ? u : father[u] = find(father[u]);
    }

    // 添加并查集
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return; // 如果相同说明在同一个集合中
        father[v] = u;
    }

    // 判断两个元素是否相连
    bool isSame(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // 初始化并查集数组
        init(n);

        // 根据每一个边进行合并
        int len = edges.size();
        for (int i = 0; i < len; ++i) {
            join(edges[i][0], edges[i][1]);
        }

        return isSame(source, destination);
    }
};
// @lc code=end

