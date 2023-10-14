/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int result = 0;
        int count = 1; // 表示遍历时递增子序列长度
        int last = nums[0];

        // 遍历数组
        for (int i = 1; i < nums.size(); ++i) {
            if (last < nums[i]) {
                // 如果递增长度加1
                count++;
                last = nums[i];
            } else {
                // 此时不再是连续递增
                // 记录最长长度
                count > result ? result = count : result;

                count = 1; // 更新递增子序列长度
                last = nums[i];
            }
        }

        // 比较最后一个递增子序列长度
        count > result ? result = count : result;

        return result;
    }
};
// @lc code=end

