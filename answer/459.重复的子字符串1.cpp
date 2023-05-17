/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
// 时间复杂度为KMP算法的复杂度，O(m + n), 空间复杂度(n)
    bool repeatedSubstringPattern(string s) {
        string t = s + s;

        t.erase(t.begin());
        t.erase(t.end() - 1);

        // 寻找字串
        if (t.find(s) != std::string::npos) return true;
        else return false;
    }
};
// @lc code=end

