/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    // 时间复杂度为O(n-m+1)
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length(), p_len = p.length();
        if (s_len < p_len || s_len == 0 || p_len == 0) return vector<int>(0);

        vector<int> res;
        unordered_map<char, int> window, need;
        for (char c : p) need[c]++;

        int valid = 0, left = 0, right = 0;
        while (right < s_len) {
            char c = s[right];
            right++;

            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            if (right - left >= p_len) {
                if (valid == need.size()) res.push_back(left);

                char d = s[left];
                left++;

                if (need.count(d)) {
                    if (need[d] == window[d]) valid--;
                    window[d]--;
                }
            }
        }

        return res;
    }
};
// @lc code=end

