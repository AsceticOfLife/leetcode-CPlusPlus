/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    // 
    int count = 0; // 当前路径个数
    int result;
    // 判断除了第i个字母是否都相同
    bool isEqual(const string &word, const string &curWord, const int i) {
        for (int j = 0; j < word.size(); ++j) {
            if (i == j) continue;
            if (word[j] != curWord[j]) return false;
        }

        return true;
    }

    void DFS(const vector<string> &wordList, const string &curWord, const int i,
             const string &endWord, vector<bool> &visited) {
        // 终止条件
        if (curWord == endWord) {
            result = min(count, result);
            return ;
        }

        // 单层逻辑
        for (int k = 0; k < wordList.size(); ++k) {
            string str = wordList[k];
            // 如果不是可达单词就跳过
            if (!isEqual(str, curWord, i)) continue; 
            // 如果访问过就跳过
            if (visited[k]) continue;

            // 将单词添加进序列并继续搜索
            count++;
            visited[k] = true;
            for (int j = 0; j < str.size(); j++) {
                DFS(wordList, str, j, endWord, visited);
            }
            // 搜索完之后回溯
            count--;
            visited[k] = false;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> vistied(wordList.size(), false); // 访问矩阵

        result = INT_MAX;
        // 遍历每一个字母尝试变换
        for (int i = 0; i < beginWord.length(); i++) {
            count = 1;
            DFS(wordList, beginWord, i, endWord, vistied);
        }

        if (result == INT_MAX) return 0;
        return result;
    }
};
// @lc code=end

