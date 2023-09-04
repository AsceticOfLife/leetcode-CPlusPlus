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
        sort(points.begin(), points.end());

        int ans = 0;
        vector<bool> shot(points.size(), false); // 是否已经被射中

        // 遍历所有的气球
        for (int i = 0; i < points.size(); ++i) {
            if (shot[i]) continue; // 如果已经被射中就跳过

            int L1 = points[i][0]; // lower bound
            int H1 = points[i][1]; // upper bound

            ans++; // 需要一个箭
            shot[i] = true;

            // 遍历后面的气球，寻找可以被这支箭射中的气球
            for (int j = 1 + i; j < points.size(); ++j) {
                if (shot[j]) continue;

                int L2 = points[j][0]; // lower bound
                int H2 = points[j][1]; // upper bound

                // 更新L1和H1
                if (L1 > H2) {
                    // 第一个集合整体在第二个集合右边，无交集
                    continue;
                } else if (H1 < L2) {
                    // 第二个集合整体在第一个集右边，无交集
                    continue;
                } else {
                    // 存在交集，那么L1和H1就更新为交集
                    L1 = max(L1, L2);
                    H1 = min(H1, H2);

                    // 第二个气球需要被射中
                    shot[j] = true;
                }
                
            }
        } // end for i in points

        return ans;
    }
};
// @lc code=end

