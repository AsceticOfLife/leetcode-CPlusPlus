/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if (len == 0) return string("");

        // 长度为i的字串，i=[n, ..., 2]
        for (int i = len; i >= 2; i--) {
            // j从下标0开始寻找长度为i的字串
            for (int j = 0; j + i - 1 < len; j++) 
                if (isPlain(s, j, j + i - 1))
                    return s.substr(j, i);
        }

        return string(1, char(s[0]));
    }

    bool isPlain(string &s, int start, int end) {
        // end--;
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
};
// @lc code=end

