/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // 求出总和
        int sum = 0;
        for (int x : nums) sum += x;

        if (sum % 2 == 1) return false; // 如果sum是奇数，则不可能两个子集和相等
        int target = sum / 2; 

        // 定义dp数组
        vector<int> dp(target + 1, 0);
        // 外层循环遍历物品
        for (int i = 0; i < nums.size(); i++) {
            // 内存逆序遍历背包重量
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        // 存在一个集合使得和正好等于target
        if (dp[target] == target) return true;
        return false;
    }
};
// @lc code=end

