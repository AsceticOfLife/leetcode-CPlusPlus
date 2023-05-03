/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        int slow1, fast1;

        // 处理s中的退格
        slow1 = fast1 = 0;
        while (fast1 < s_len) {
            if (s[fast1] != '#') {
                // slow指向的位置为fast的字符
                s[slow1++] = s[fast1];
            } else {
                // 如果是#慢指针后移一位
                slow1 == 0? slow1 : slow1--;
            }

            fast1++;
        }
        // 处理完成之后slow就是s串后一位

        // 处理t中的退格
        int slow2, fast2;
        slow2 = fast2 = 0;
        while (fast2 < t_len) {
            if (t[fast2] != '#') {
                // slow指向的位置为fast的字符
                t[slow2++] = t[fast2];
            } else {
                // 如果是#慢指针后移一位
                slow2 == 0 ? slow2 : slow2--;
            }
            
            fast2++;
        }

        // 比较两个字符
        if (slow1 != slow2) return false;
        for (int i = 0; i < slow1; i++) {
            if (s[i] != t[i]) return false;
        }

        return true;
    }
};
// @lc code=end

