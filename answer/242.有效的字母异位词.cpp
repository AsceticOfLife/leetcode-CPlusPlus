/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        if (len1 != len2) return false;

        unordered_map<char, int> hash_table;
        // 遍历第一个字符串统计字符个数
        for (int i = 0; i < len1; i++) hash_table[s[i]]++;

        // 遍历第二个字符比较
        for (int i = 0; i < len2; i++) hash_table[t[i]]--;

        // 判断s中每一个字符都为0
        for (int i = 0; i < len1; i++) {
            if (hash_table[s[i]] != 0) return false; 
        }

        return true;
    }
};
// @lc code=end

