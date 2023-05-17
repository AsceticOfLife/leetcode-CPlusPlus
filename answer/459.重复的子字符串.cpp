/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
// 时间复杂度O(n^2)
    bool repeatedSubstringPattern(string s) {
        int n = s.length();

        for (int i = 1; i < n; i++) {
            if (n % i != 0) continue;
            else {
                int j;
                for (j = i; j < n; j++) {
                    if (s[j] != s[j - i]) break;
                }
                if (j == n) return true;
            }
        }

        return false;
    }
};
// @lc code=end

