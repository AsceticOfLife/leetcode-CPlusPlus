/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        vector<vector<string>> res;
        
        // 遍历字符串数组
        auto it = strs.begin();
        while (it != strs.end()) {
            vector<string> temp;
            temp.push_back(*it);
            
            // 遍历后面的元素
            auto next = it + 1;
            while (next != strs.end()) {
                // 如果是字母异位词就添加入temp列表
                // 并把这个next元素从字符串列表中删除
                if (isAnagram(*it, *next)) {
                    temp.push_back(*next);

                    // 将这个元素与最后一个元素互换并删除尾部元素
                    swap(*next, *(strs.end() - 1));
                    strs.pop_back();
                } else next++;
            }

            // temp列表中是与it指向的元素为字符异位词
            res.push_back(temp);

            it++;
        }

        // 由于边遍历变删除所以时间复杂度为O(m*n)
        // 其中m表示分组个数
        return res;
    }

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

