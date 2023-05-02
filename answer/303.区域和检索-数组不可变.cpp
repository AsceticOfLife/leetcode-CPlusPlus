/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */
#include <vector>
using namespace std;
// @lc code=start
class NumArray {
private:
    vector<int> preSum;
public:
    NumArray(vector<int>& nums) : preSum(nums.size() + 1) {
        // 创建前缀和数组
        int i = 0;
        int length = preSum.size();
        preSum[i] = 0;

        for (i = i + 1; i < length; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

