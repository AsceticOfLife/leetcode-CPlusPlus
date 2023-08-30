/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> nums(ratings.size(), 1);

        // 遍历比较两个小朋友，只有当两个小朋友中评分更高的获得多一个糖果
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i - 1] < ratings[i]) 
                nums[i] = nums[i - 1] + 1;

        }

        // 从后向前
        for (int i = ratings.size() - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i])
                nums[i - 1] = max(nums[i - 1], nums[i] + 1);
        }

        int ans = 0;
        for (int i = 0; i < nums.size(); i++) 
            ans += nums[i];
        
        return ans;
    }
};
// @lc code=end

