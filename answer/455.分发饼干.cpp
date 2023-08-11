/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end()); // 升序排列饼干大小

        int index = 0;  // index of g
        for (int i = 0; i < s.size(); i++) {
            if (index < g.size() && s[i] >= g[index])
                index++;
        }

        return index;
    }
};
// @lc code=end

