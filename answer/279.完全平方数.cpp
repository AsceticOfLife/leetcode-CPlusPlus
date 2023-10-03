/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        int Max_i = int(sqrt(n));

        // 定义dp数组和初始化
        vector<int> dp(n + 1, numeric_limits<int>::max());
        dp[0] = 0;

        // 外层循环遍历物品
        for (int i = 1; i <= Max_i; ++i) {
            int weight = i * i;
            // 内层循环遍历背包重量
            for (int j = weight; j <= n; ++j) {
                if (dp[j - weight] != numeric_limits<int>::max())
                    dp[j] = min(dp[j], dp[j - weight] + 1);
            }
        }

        // 最多可以由n个1装满
        // 所以不会存在无法装满的情况
        return dp[n];
    }
};
// @lc code=end

