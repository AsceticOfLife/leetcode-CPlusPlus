/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
class Solution {
public:
    // 使用组合数
    int uniquePaths(int m, int n) {
        long long numerator = 1; // 分子
        int denominator = m - 1; // 分母
        int count = m - 1;
        int t = m + n - 2; // 起点
        
        while (count--) {
            numerator *= (t--);
            // 当可以整除分母时
            // 由于是组合数，所以分子一定可以把所有的分母都给整除掉
            while (denominator != 0 && numerator % denominator == 0) {
                numerator /= denominator;
                denominator--;
            }

        }

        return numerator;
    }
};
// @lc code=end

