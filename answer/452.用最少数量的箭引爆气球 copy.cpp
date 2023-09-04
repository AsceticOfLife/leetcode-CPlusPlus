/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end()); // 根据左边界排序

        // 从第二个点开始遍历
        int ans = 1; // 假设总是存在第一个元素
        for (int i = 1; i < points.size(); i++) {
            if (points[i][0] > points[i- 1][1]) {
                // 第二个元素的左边界大于第一个元素右边界
                // 说明不挨着
                ans++; 
            } else {
                // 以最小右边界继续
                points[i][1] = min(points[i - 1][1], points[i][1]);
            }
        }

        return ans;
    }
};
// @lc code=end

