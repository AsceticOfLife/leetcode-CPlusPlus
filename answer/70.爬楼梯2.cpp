/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    // 另一种动态规划
    // 将其看作是一个完全背包问题
    // 物品只有两个，就是1和2
    // 背包重量是n
    // 求刚好组成n的排列数
    int climbStairs(int n) {
        // 定义dp数组和初始化
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        // 外层循环遍历重量
        for (int j = 0; j <= n; ++j) {
            // 内层循环遍历物品
            for (int i = 1; i <= 2; ++i) {
                if (j >= i) dp[j] += dp[j - i];
            }
        }

        return dp[n];
    }
};
// @lc code=end

