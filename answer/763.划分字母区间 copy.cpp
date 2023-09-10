/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 使用一个hash表记录每一个字母最后出现的位置
        // 题目中说明左右字母均是小写
        int hash_table[26] = {0};
        for (int i = 0; i < s.size(); ++i) 
            hash_table[s[i] - 'a'] = i;

        int count = 0;  // 记录每一个分区的长度
        int max_end = 0; // 每一个分区的最大右边界
        vector<int> ans;
        for (int i = 0; i < s.size(); ++i) {
            // 更新max_end右边界
            max_end = max(max_end, hash_table[s[i] - 'a']);
            count++;

            if (i == max_end) {
                // 当前字母就是同一分区最后一个元素
                // 记录该分区长度
                ans.push_back(count);

                // 长度归零
                count = 0;
            }
        }

        return ans;
    }
};
// @lc code=end

