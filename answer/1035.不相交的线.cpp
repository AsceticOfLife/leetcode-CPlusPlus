/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // 边界检查
        if (nums1.size() == 0 || nums2.size() == 0) return 0;
        
        // 定义dp数组
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), 0));
        // 初始化第一列
        for (int row = 0; row < nums1.size(); ++row) {
            if (nums1[row] == nums2[0]) {
                // 找到一个相等的之后
                // 后面全部为1
                while (row < nums1.size()) dp[row++][0] = 1;
                break;
            }
        }
        // 初始化第一行
        for (int col = 0; col < nums2.size(); col++) {
            if (nums1[0] == nums2[col]) {
                while (col < nums2.size()) dp[0][col++] = 1;
                break;
            }
        }

        // 下标从1开始
        // 外层循环遍历第一个数组的元素
        for (int i = 1; i < nums1.size(); i++) {
            // 内层循环遍历第二个数组的元素
            for (int j = 1; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        return dp[nums1.size() - 1][nums2.size() - 1];
    }
};
// @lc code=end

