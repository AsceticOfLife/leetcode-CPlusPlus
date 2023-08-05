/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used; // used or not used

    void BackTrace(const vector<int> &nums) {
        // 终止条件
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        // 遍历未使用过的元素
        for (int i = 0; i < nums.size(); ++i) {
            // 被使用的元素不能再次使用
            if (used[i] == true) continue;

            path.push_back(nums[i]);
            used[i] = true;

            BackTrace(nums);

            path.pop_back();
            used[i] = false;
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);

        BackTrace(nums);

        return result;
    }
};
// @lc code=end

