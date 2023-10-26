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

    void BFS(const vector<string> &wordList, string &curWord,
             const string &endWord, vector<bool> &visited) {
        queue<string> que;
        que.push(curWord);
        count = 0;
        unordered_map<string, int> map;
        map[curWord] = 1;
    
        while (!que.empty()) {
            curWord = que.front();
            que.pop();
            count = map[curWord];

            // 终止条件
            if (curWord == endWord) {
                result = count;
                return ;
            }

            // 单层逻辑
            // 外层循环尝试修改curWord的所有字母
            for (int i = 0; i < curWord.size(); ++i) {
                // 内存循环遍历所有单词
                for (int k = 0; k < wordList.size(); ++k) {
                    string str = wordList[k];
                    // 如果不是可达单词就跳过
                    if (!isEqual(str, curWord, i)) continue; 
                    // 如果访问过就跳过
                    if (visited[k]) continue;

                    // 将单词添加进序列队列
                    que.push(str);
                    visited[k] = true;
                    map[str] = count + 1;
                }
            }
        } // end when queue is empty

    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<bool> vistied(wordList.size(), false); // 访问矩阵

        result = INT_MAX;
        BFS(wordList, beginWord, endWord, vistied);

        if (result == INT_MAX) return 0;
        return result;
    }
};
// @lc code=end

