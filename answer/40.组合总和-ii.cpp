/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    int sum;

    void BackTrace(const vector<int> &candidates, const int target,
                   const int start_index, vector<bool> &used) {
        // 终止条件
        if (target == sum) {
            result.push_back(path);
            return;
        }

        // 遍历集合
        for (int i = start_index; i < candidates.size(); ++i) {
            if (i > 0 && candidates[i] == candidates[i - 1]
                && used[i - 1] == false)
                continue;
            
            path.push_back(candidates[i]);
            sum += candidates[i];
            used[i] = true;

            // 剪枝
            if (sum > target) {
                path.pop_back();
                sum -= candidates[i];
                used[i] = false;
                return;
            }

            // 递归
            BackTrace(candidates, target, i + 1, used);

            // 回溯
            path.pop_back();
            sum -= candidates[i];
            used[i] = false;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sum = 0;
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);

        BackTrace(candidates, target, 0, used);

        return result;
    }
};
// @lc code=end

