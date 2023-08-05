/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void BackTrace(const vector<int> &nums, const int start_index) {
        result.push_back(path);

        // 终止条件
        if (start_index >= nums.size()) return;

        // 遍历剩下的集合元素
        for (int i = start_index; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            
            BackTrace(nums, i + 1);

            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        BackTrace(nums, 0);

        return result;
    }
};
// @lc code=end

