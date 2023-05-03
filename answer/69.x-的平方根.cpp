/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int ans = -1;
        while (left <= right) {
            long long mid = left + ((right - left) >> 1);
            long long res = mid * mid;
            if (res <= x) {
                left = mid + 1;
                ans = mid;
            }
            else right = mid - 1;
        } 
    return ans;
    }
};
// @lc code=end

