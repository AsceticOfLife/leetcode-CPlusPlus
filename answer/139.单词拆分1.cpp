/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool BackTrace(const string &s, const int start_index, const unordered_set<string> &word_set) {
        // 递归终止条件
        if (start_index >= s.size()) return true;

        // 单层处理逻辑
        for (int i = start_index; i < s.size(); ++i) {
            string str = s.substr(start_index, i - start_index + 1);
            if (word_set.find(str) != word_set.end() && BackTrace(s, i + 1, word_set))
                return true;
        }

        return false;
    }


    bool wordBreak(string s, vector<string>& wordDict) {
        // 使用无序集合方便在其中查找单词
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        // 回溯
        return BackTrace(s, 0, wordSet);

    }
};
// @lc code=end

