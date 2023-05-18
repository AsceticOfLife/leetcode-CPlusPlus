/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
#include <string>
#include <stack>
using std::string;
using std::stack;

class Solution {
public:
    string removeDuplicates(string s) {
        // 创建栈
        stack<char> st;
        // 遍历
        for (int i = 0; i < s.length(); i++) {
            if (!st.empty() && s[i] == st.top()) 
                st.pop();
            else st.push(s[i]);
        }

        // 此时栈中就是结果
        s = string(st.size(), 'c');
        for (int i = st.size() - 1; i >= 0; i--) {
            s[i] = st.top();
            st.pop();
        }

        return s;
    }
};
// @lc code=end

