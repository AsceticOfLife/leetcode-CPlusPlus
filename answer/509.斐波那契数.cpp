/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        int fn_2 = 0, fn_1 = 1;
        if (n == 0) return fn_2;
        if (n == 1) return fn_1;

        int fn;
        for (int i = 2; i <= n; ++i) {
            fn = fn_2 + fn_1;

            // 更新前两个数
            fn_2 = fn_1;
            fn_1 = fn;
        }

        return fn;
    }
};
// @lc code=end

