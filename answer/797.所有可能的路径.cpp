/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void DFS(const vector<vector<int>> &graph, const int index) {
        if (index == graph.size() - 1) {
            result.push_back(path);
            return;
        }

        // 遍历当前可以访问的结点
        for (int i : graph[index]) {
            path.push_back(i); // 添加可访问结点到当前路径
            DFS(graph, i); // 以可访问结点作为当前结点
            path.pop_back(); // 回溯
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        DFS(graph, 0);

        return result;
    }
};
// @lc code=end

