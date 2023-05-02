/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1_len = s1.length(), s2_len = s2.length();
        if (s1_len > s2_len || s1_len == 0 || s2_len == 0) return false;

        unordered_map<char, int> window, need;
        for (char c : s1) need[c]++;

        int valid = 0;
        int right = 0, left = 0;
        while (right < s2_len) {
            char c = s2[right];
            right++;
            
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            while (right - left >= s1_len) {
                if (valid == need.size()) return true;

                char d = s2[left];
                left++;
                
                // 进行窗口内数据更新
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }

        }

        return false;
    }
};
// @lc code=end

