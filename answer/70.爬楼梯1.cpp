/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    /**
     * @description: 计算登上n阶台阶可能的方法个数
     * @param {int} n: 台阶数
     * @return {*}
     */
    int F(int n) {
        // 边界条件
        if (n == 1) return 1;
        if (n == 2) return 2;
        return F(n - 1) + F(n - 2);
    }

    // 采用分治（递归），自顶向下递归
    int climbStairs(int n) {
        return F(n);
    }
};
// @lc code=end

