/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        int cur_distance = 0; // 当前覆盖最远距离的下标
        int next_distance = 0; // 下一步覆盖的最远的下标
        int ans = 0; // 最小步数

        for (int i = 0; i < nums.size(); i++) {
            next_distance = max(i + nums[i], next_distance); // 更新下一步可以覆盖的范围

            // 如果当前下标到达当前覆盖最远范围
            if (i == cur_distance) {
                ans++; // 说明需要多走一步
                cur_distance = next_distance; // 更新走一步之后覆盖的最大范围
                if (next_distance >= nums.size() - 1) break;
            }
        }

        return ans;
    }
};
// @lc code=end

