/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
#include <stack>
#include <string>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        // 创建字符串栈
        stack<string> words;

        // 遍历语句
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                // 找到下一个空格字符
                int j = i + 1;
                while (j < s.length() && s[j] != ' ') j++;

                // 将从i到j-1的字符作为字符串添加进栈
                words.push(string(s.begin() + i, s.begin() + j));

                i = j;
            } else continue;
        }

        // 输出结果
        string res = words.top();
        words.pop();
        while (!words.empty()) {
            res += " " + words.top();
            words.pop();
        }

        return res;
    }
};
// @lc code=end

