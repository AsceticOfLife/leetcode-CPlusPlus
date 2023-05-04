/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include <vector>
#include <cmath>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int len = nums.size();
        // 所有数字进行平方并找到第一个大于等于0的数字
        int i = 0;
        for (i = 0; i < len; i++) nums[i] = nums[i] * nums[i];


        vector<int> res(len);

        int left = 0;
        int right = len - 1;

        i = len - 1;
        while (left <= right) {
            if (nums[left] >= nums [right]) {
                res[i--] = nums[left++];
            } else {
                res[i--] = nums[right--];
            }
        }


        return res;
    }
};
// @lc code=end

