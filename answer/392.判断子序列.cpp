/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    // 暴力解法
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        while (i < s.size()) {
            while (j < t.size() && s[i] != t[j]) j++;
            // 如果j超出字符串t
            if (j == t.size()) return false;

            // 如果没有超出说明找到了s[i] == t[j]
            // 需要找下一个元素
            i++;
            j++;
        }

        // 如果S串中全都能找到
        return true;
    }
};
// @lc code=end

