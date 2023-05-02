/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    string minWindow(string &s, string &t) {
        int s_len = s.length();
        int t_len = t.length();
        int valid = 0;
        int start = 0, len = INT_MAX;
        if (s_len < t_len || s_len == 0 || t_len == 0) return string("");

        // 创建hash表，need表示合格状态
        unordered_map<char, int> window, need;
        // 初始话need
        for (char c : t) need[c]++;

        int left = 0, right = 0;
        while (right < s_len) {
            char c = s[right];
            right++;

            // windows更新
            if (need.count(c)) {
                window[c]++;
                // 某个字符满足t状态
                if (window[c] == need[c]) valid++;
            }
            
            // T中所有字符都已被覆盖
            while (valid == need.size()) {
                // 更新最小覆盖字串长度
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                // d是窗口左边元素
                char d = s[left];
                // 窗口左移
                left++;
                // 更新信息
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        } // end while

        return len == INT_MAX ? "" : s.substr(start, len);

    }
};
// @lc code=end

