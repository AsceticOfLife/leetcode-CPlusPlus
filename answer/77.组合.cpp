/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;


    void backtracing(int n, int k, int start_index) {
        // 终止条件
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        // 循环处理集合
        // 这里的集合是[start_index, n]
        for (int i = start_index; i <= n - (k - path.size()) + 1; ++i) {
            path.push_back(i); // 加上当前结点
            backtracing(n, k, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        backtracing(n, k, 1);

        return res;
    }
};
// @lc code=end

