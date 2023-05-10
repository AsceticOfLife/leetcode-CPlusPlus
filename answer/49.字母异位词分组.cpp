/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        // 创建hash表，键是字符串，键值是列表
        unordered_map<string, vector<string>> hash_table;

        // 遍历字符串，将排序后相同的字符串添加到列表中
        for (int i = 0; i < n; i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            // 将排序之后的字符串作为键
            hash_table[temp].push_back(strs[i]);
        }

        // 创建结果
        vector<vector<string>> res;
        for (auto it = hash_table.begin(); it != hash_table.end(); it++) {
            res.push_back((*it).second);
        }

        return res;
    }

   
};
// @lc code=end

