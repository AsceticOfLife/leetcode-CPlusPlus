/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum;

    void backtrace(const vector<int> &candidates, const int target, const int start_index) {
        // 终止条件
        if (target == sum) {
            res.push_back(path);
            return;
        } else if (target < sum) return;

        for (int i = start_index; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            
            if (sum > target) {
                sum -= candidates[i];
                path.pop_back();
                break;
            }
            backtrace(candidates, target, i);

            path.pop_back();
            sum -= candidates[i];
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sum = 0;
        sort(candidates.begin(), candidates.end());
        backtrace(candidates, target, 0);

        return res;
    }
};
// @lc code=end

