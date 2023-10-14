/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution {
public:
    // 动态规划
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // 定义dp数组和初始化
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));

        int result = 0;
        // 外层循环遍历第一个数组作为最后一个元素
        for (int i = 1; i <= nums1.size(); ++i) {
            // 内层循环遍历第二个数组作为最后一个元素
            for (int j = 1; j <= nums2.size(); ++j) {
                if (nums1[i - 1] == nums2[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                // 记录最大值
                result < dp[i][j] ? result = dp[i][j] : result;
            }
        }

        return result;
    }
};
// @lc code=end

