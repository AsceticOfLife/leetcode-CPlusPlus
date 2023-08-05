/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<bool> used;
    vector<int> path;

    void BackTrace(const vector<int> &nums, const int start_index) {
        result.push_back(path);

        // 终止条件
        if (start_index >= nums.size()) return;

        for (int i = start_index; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;

            path.push_back(nums[i]);
            used[i] = true;

            BackTrace(nums, i + 1);

            path.pop_back();
            used[i] = false;
        }

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        used = vector<bool>(nums.size(), false);

        BackTrace(nums, 0);

        return result;
    }
};
// @lc code=end

