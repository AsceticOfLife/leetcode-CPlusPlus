/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp_i_2 = 0, dp_i_1 = 0;
        if (cost.size() == 0) return -1;
        if (cost.size() == 1) return 0;

        int dp_i;
        // 从前向后遍历
        // 到达顶部指的是超越最后一层阶梯
        for (int i = 2; i <= cost.size(); ++i) {
            if (dp_i_2 + cost[i - 2] < dp_i_1 + cost[i - 1])
                dp_i = dp_i_2 + cost[i - 2];
            else
                dp_i = dp_i_1 + cost[i - 1];
            
            // 更新前两个的记录
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }

        return dp_i;
    }
};
// @lc code=end

