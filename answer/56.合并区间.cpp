/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0]; // 以第一个元素按升序排列
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        // 从第二个元素开始
        // 每个元素与前者进行比较
        // 假设至少有两个元素
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > intervals[i - 1][1]) {
                // 如果后者左边界超过前者右边界
                // 说明无交集
                // 把前者加入结果中
                ans.push_back(intervals[i - 1]);
            } else {
                // 如果存在交集
                // 确定合并后区间的左边界
                // 应该以两者中较小的左边界为左边界
                // 而排序已经保证前者的左边界<=后者的左边界
                intervals[i][0] = intervals[i - 1][0];

                // 确定合并后区间的右边界
                // 应该以两者中较大的右边界作为新的右边界
                intervals[i][1] = max(intervals[i - 1][1], intervals[i][1]);
            }
        }

        // 添加新区间的时机是当遇到下一个不重叠的区间
        // 最后一个区间不会遇到新的区间
        // 所以这里手动添加
        ans.push_back(intervals[intervals.size() - 1]);

        return ans;
    }
};
// @lc code=end

