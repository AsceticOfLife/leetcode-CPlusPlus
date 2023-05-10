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
    // 时间复杂度为O((n-m+1)*mlogm)
    // vector<int> findAnagrams(string s, string p) {
    //     int s_len = s.length(), p_len = p.length();
    //     if (s_len < p_len || s_len == 0 || p_len == 0) return vector<int>(0);

    //     // 对p进行排序
    //     sort(p.begin(), p.end());
    //     vector<int> res;
    //     int limit = s_len - p_len + 1;
    //     for (int i = 0; i < limit; i++) {
    //         string temp(s.begin() + i, s.begin() + i + p_len);
    //         // 排序之后与p进行比较
    //         sort(temp.begin(), temp.end());
    //         if (temp == p) res.push_back(i);
    //     }

    //     return res;
    // }

    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length(), p_len = p.length();
        if (s_len < p_len || s_len == 0 || p_len == 0) return vector<int>(0);

        // 创建hash表
        unordered_map<char, int> window, need;
        // 统计p的各个字母的次数
        for (char c : p) need[c]++;

        int right, left;
        int valid = 0; // 表示window中出现次数与need相同的字母数
        left = right = 0;
        vector<int> res;
        while (right < s_len) {
            char c = s[right];
            right++;

            // 判断是否在need中
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            if (right - left == p_len) {
                if (valid == need.size()) res.push_back(left);

                char d = s[left];
                left++;

                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }

            
        }
        
        return res;
    }
};
// @lc code=end

