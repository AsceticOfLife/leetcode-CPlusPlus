/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        // 求石头的总重量
        for (int x : stones) sum += x;

        // 背包的重量就是总和的一半
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        // 外层循环遍历物品
        for (int i = 0; i < stones.size(); ++i) {
            // 内存循环逆序遍历重量
            for (int j = target; j >= stones[i]; --j) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        
        // 最终这一个背包的重量是dp[target]
        // 另一个背包的重量是sum - dp[target]
        // 两个背包相互抵消剩下的就是最小重量
        return sum - dp[target] - dp[target];
    }
};
// @lc code=end

