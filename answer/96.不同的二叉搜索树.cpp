/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        // 初始化
        dp[0] = dp[1] = 1;

        // 外层循环遍历结点个数[2, n]
        for (int i = 2; i <= n; ++i) {
            // 内存循环尝试分别以i个值作为根节点
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j - 1] * dp[i - j];
            } 
        }

        return dp[n];
    }
};
// @lc code=end

