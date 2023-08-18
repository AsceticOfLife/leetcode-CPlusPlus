/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    // 采用动态规划自底向上解决问题
    int climbStairs(int n) {
        int last_2 = 1, last_1 = 2;
        if (n <= 0) return -1; // 错误情况
        if (n == 1) return last_2;
        if (n == 2) return last_1;

        int cur;
        for (int i = 3; i <= n; ++i) {
            cur = last_2 + last_1;

            // 更新前两个数
            last_2 = last_1;
            last_1 = cur;
        }

        return cur;
    }
};
// @lc code=end

