/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end());

        // 从第二个元素开始遍历
        int ans = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= intervals[i - 1][1]) {
                // 后者左端点大于等于前者右端点
                continue; // 无交集无需操作
            } else {
                // 存在交集，应该把范围更大的区间删除
                ++ans;

                if (intervals[i][1] > intervals[i - 1][1]) {
                    // 后者右边界更大
                    // 更新后者为前者继续比较
                    // 相当于删除后者
                    intervals[i][1] = intervals[i - 1][1];
                }

            }
        } // end for i in intervals

        return ans;
    }
};
// @lc code=end

