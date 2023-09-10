/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution {
public:
    int FindMaxend(const string &s, char c) {
        // 返回c在s中最后一次出现的位置下标
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == c) return i;
        }

        // c一定在s中，否则出错
        exit(-1);
    }

    vector<int> partitionLabels(string s) {
        if (s.size() == 0) return vector<int>(0);
        int max_end = 0; // 表示当前

        // 假设s不为空，初始化第一个字符的max_end
        max_end = FindMaxend(s, s[0]);
        int count = 1; // 初始化第一个分区的长度
        vector<int> ans;
        // 从第二个元素开始
        for (int i = 1; i < s.size(); ++i) {
            if (i <= max_end) {
                // 说明还在上一个分区内
                count++; // 分区长度加1
            } else {
                // 说明这是一个新的分区
                // 应该保留上一次的长度
                ans.push_back(count);

                count = 1; // 从这个新的元素开始计数
            }

            // 更新max_end
            max_end = max(max_end, FindMaxend(s, s[i]));
        }
        // 每一段的更新逻辑是遇到下一段才会更新
        // 最后一段不会遇到下一段，所以没有更新
        ans.push_back(count);

        return ans;
    }
};
// @lc code=end

