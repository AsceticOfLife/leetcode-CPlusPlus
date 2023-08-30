/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // 升序排列
        sort(nums.begin(), nums.end());

        // 首先处理负数
        int i;
        for (i = 0; i < nums.size(); ++i) {
            if (k == 0) break; // 次数用完退出

            if (nums[i] < 0) {
                // 消耗一次变化次数
                --k;
                nums[i] = -nums[i];
            } else if (nums[i] == 0){
                k = 0;
                break; // 当遇到非负数时退出循环
            } else {
                break;
            }
        }

        // 此时K表示所有的负数都被消耗
        if (k > 0) {
            if (k % 2 == 0) {
                // 此时无需再处理数组
                ;
            } else {
                // 重新排序选择最小的整数取反即可
                sort(nums.begin(), nums.end());
                nums[0] = -nums[0];
            }
        }


        int ans = 0;
        for (int j = 0; j < nums.size(); ++j)
                ans += nums[j];

        return ans;
    }
};
// @lc code=end

