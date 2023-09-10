/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        // 将数字转换为string类型
        string str_n = to_string(n);

        int flag; //
        for (int i = str_n.size() - 1; i > 0; --i) {
            // 当后者小于前者时
            if (str_n[i] < str_n[i - 1]) {
                // 从这个位置以后的所有元素应该为9
                flag = i;
                // 前者减去1
                str_n[i - 1]--;
            }
        }

        // 将从flag开始的所有元素设置为9
        for (int i = flag; i < str_n.size(); ++i) {
            str_n[i] = '9';
        }

        return stoi(str_n);
    }
};
// @lc code=end

