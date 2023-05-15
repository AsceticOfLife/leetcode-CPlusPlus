/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
#include <string>
#include <utility>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        if (s.length() == 0) return string();

        // 首先清除多余的空格
        // 对于开头的空格
        int slow, fast;
        slow = fast = 0;
        for (; fast < s.length(); fast++) {
            if (s[fast] != ' ') {
                // 给单词之间添加空格
                if (slow != 0) s[slow++] = ' ';
                while (fast < s.length() && s[fast] != ' ')
                    s[slow++] = s[fast++];

            }
        }

        s.resize(slow);

        // 接着翻转整个字符串
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }

        // 最后判断字符串并翻转
        slow = fast = 0;
        for (; fast < s.length(); fast++) {
            while (fast < s.length() && s[fast] != ' ') fast++;
            // 翻转slow到fast之间的字符
            int left = slow;
            int right = fast - 1;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }

            // 更新slow
            slow = fast + 1;
        }

        return s;
    }
};
// @lc code=end

