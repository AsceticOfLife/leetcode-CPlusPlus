/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        return Index_KMP(haystack, needle, 0);
    }
    void get_next(const std::string &T, std::vector<int> &next) {
        int i = 1, j = 0;
        int len = next.size();
        if (len > 0) next[0] = 0;
        if (len > 1) next[1] = 0;

        while (i < len - 1) {
            if (T[i] == T[j]) {
                // 第i个相等对应第i+1不匹配时的情况
                ++i;
                ++j;
                // 原始
                // next[i] = j;

                // 改进：这个过程描述的是当出现不匹配时，要根据next数组选择 j 的位置
                // 即当前字符不与S串匹配，那么考虑next指向的字符（也就是前缀字符）是否与当前字符相同
                // 如果相同说明两个字符都不会与这个S串中的字符相等，因此可以把next指向的字符（前缀字符）对应next值给这个字符
                if (T[i] != T[j]) next[i] = j;
                else next[i] = next[j];
                
            } else if (j == 0) {
                // 对应第一个字符就不等的情况
                ++i;
                next[i] = j;
            } else {
                // j回溯，与字符串匹配时类似
                j = next[j];
            }
        }

    }

    int Index_KMP(const std::string &S, const std::string &T, int pos) {
        int s_len = S.length();
        int t_len = T.length();
        // 创建next列表
        std::vector<int> next(t_len);
        get_next(T, next);
        
        int i = pos;
        int j = 0;
        while (i < s_len && j < t_len) {
            if (S[i] == T[j]) {
                ++i;
                ++j;
            } else if (j == 0) {
                ++i;
            } else {
                j = next[j];
            }
        }

        if (j == t_len) return i - t_len;
        else return -1;
    }
};
// @lc code=end

