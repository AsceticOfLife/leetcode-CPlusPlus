/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
#include <stack>
#include <string>
#include <vector>
using std::stack;
using std::string;
using std::vector;
using std::stoi;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 栈用于保存数字字符串
        stack<int> st;

        // 遍历字符串
        for (string str : tokens) {
            if (str != "-" && str != "+" && str != "*" && str != "/") 
                st.push(stoi(str));
            else {
                // 如果栈中没有数据但是遇到了运算符则报错
                if (st.empty()) return false;

                // 取出两个栈元素并计算
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();

                // 判断是哪一种运算
                if (str == "-") st.push(op1 - op2);
                else if (str == "+") st.push(op1 + op2);
                else if (str == "*") st.push(op1 * op2);
                else if (str == "/") st.push(op1 / op2);
                else return false; // unexpected operator
            }
        }

        // 此时栈中就是答案
        return st.top();
    }

    // 字符串求数值
    int evalString(string &s) {
        int res = 0;
        int len = s.length();
        int base = 1;
        // 处理除了第一个字符之外的字符
        for (int i = len - 1; i > 0; i--) {
            char c = s[i];
            int temp = c - '0';
            res += temp * base;

            // 基数增加
            base *= 10;
        }
        // 处理第一个字符
        if (s[0] == '-') res = -res;
        else res += int(s[0] - '0') * base;
            
        return res;
    }
};
// @lc code=end

