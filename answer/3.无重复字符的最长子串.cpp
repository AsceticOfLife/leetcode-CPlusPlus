/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len == 0) return 0;

        unordered_map<char, int> window;
        int left = 0, right = 0;
        int res = 0;
        while (right < len) {
            char c = s[right];
            right++;

            window[c]++;

            if (window[c] == 1) {
                res = right - left > res ? right - left : res;
            } else {
                while (window[c] > 1) {
                    char d = s[left];
                    left++;
                    window[d]--;
                }
            } // end if
        } // end while

        return res;
    }
};
// @lc code=end

