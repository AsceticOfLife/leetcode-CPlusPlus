/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 0;
        int right = num;

        while (left <= right) {
            int mid = left + ((right - left) / 2);
            long long s = (long long)(mid) * mid;
            if (s > num) right = mid - 1;
            else if (s < num) left = mid + 1;
            else return true;
        }

        return false;
    }
};
// @lc code=end

