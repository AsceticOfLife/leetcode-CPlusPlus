/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <string>
#include <stack>
using std::string;
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        // 使用栈结构
        stack<char> st;
        // 遍历字符串
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') st.push(c);
            else {
                if (!st.empty()) {
                    if (c == ')' && st.top() == '(') st.pop();
                    else if (c == ']' && st.top() == '[') st.pop();
                    else if (c == '}' && st.top() == '{') st.pop();
                    else return false;
                }
                else return false;
            }
        } // end for c in s

        if (st.empty()) return true;
        else return false;
    }
};
// @lc code=end

