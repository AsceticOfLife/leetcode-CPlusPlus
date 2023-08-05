/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum;

    void backtrace(int n, int k, int start_index) {
        // 终止条件
        // 当path中元素个数达到k时
        if (path.size() == k) {
            if (sum == n) res.push_back(path);
            return;
        }

        // 循环处理剩余集合
        for (int i = start_index; i <= 9 - (k - path.size()) + 1; ++i) {
            path.push_back(i);
            sum += i;

            // 剪枝
            if (sum > n) {
                sum -= i;
                path.pop_back();
                return;
            }
            
            backtrace(n, k, i + 1);
            path.pop_back();
            sum -= i;
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        sum = 0;
        backtrace(n, k, 1);

        return res;
    }
};
// @lc code=end

