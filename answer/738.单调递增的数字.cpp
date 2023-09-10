/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        // 使用栈保存每个位置的数字
        stack<int> st;
        while (n != 0) {
            st.push(n % 10);
            n /= 10;
        }
        int n_len = st.size();
        // 使用栈保存结果的每位数字
        stack<int> ans;
        int cur; // 当前数字
        int min_val = 0; // 根据当前数字确定下一位数字的最小值
        int i = 0; // 表示目前处理的数字下标，从0计数
        while (!st.empty()) {
            cur = st.top();
            st.pop();

            if (cur >= min_val) {
                // 满足递增的条件
                ans.push(cur); // ans同一位置的数字尽量等于原数字
                min_val = cur;
                ++i; // 数字下标递增
            } else {
                // 此时不满足单调递增
                // 则让前一位减一
                // 后续所有元素为最大值9
                ans.top()--;

                // 如果前一位减1之后为0，则这一位不需要
                // if (ans.top() == 0) ans.pop();

                int remain = n_len - i; // 剩下的元素个数
                while (remain--) 
                    ans.push(9);

                break;
            }
        }

        // 根据结果栈恢复最大值
        long base = 1;
        int result = 0;
        while (!ans.empty()) {
            int cur = ans.top();
            ans.pop(); 

            if (ans.empty() || cur >= ans.top()) {
                result += cur * base;
            } else {
                result += 9 * base;
                ans.top()--;

                // if (ans.top() == 0) ans.pop();
            }

            base *= 10;
        }
        
        return result;
    }
};
// @lc code=end

