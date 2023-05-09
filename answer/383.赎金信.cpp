/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len1 = ransomNote.length();
        int len2 = magazine.length();
        if (len1 > len2) return false;

        unordered_map<char, int> hash_table;
        // 遍历magazine，统计字符个数
        for (int i = 0; i < len2; i++) hash_table[magazine[i]]++;

        // 遍历ransomNote，使用哪个字符就删除哪个字符一次
        int ch;
        for (int i = 0; i < len1; i++) {
            ch = ransomNote[i];
            hash_table[ch]--;
            if (hash_table[ch] < 0) return false;
        }

        return true;
    }
};
// @lc code=end

