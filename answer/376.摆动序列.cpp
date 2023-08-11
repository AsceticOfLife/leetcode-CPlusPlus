/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int pre_differ = 0;
        int cur_differ = 0;
        int result = 1; // 默认最右边是一个波峰或者波谷

        for (int i = 0; i < nums.size() - 1; ++i) {
            cur_differ = nums[i + 1] - nums[i];

            if ((pre_differ <= 0 && cur_differ > 0) || (pre_differ >= 0 && cur_differ < 0)) {
                result++;
                pre_differ = cur_differ; // 只有出现波峰和波谷时才会更新差值
            }
        }

        return result;
    }
};
// @lc code=end

