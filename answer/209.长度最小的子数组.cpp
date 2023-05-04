/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        // 所有数字进行平方并找到第一个大于等于0的数字
        int min_len = len + 1;
        int left, right;
        left = right = 0;
        int sum = 0;
        while (right < len) {
            // 更新窗口内的和
            sum += nums[right];
            right++; // 右边界增大

            while (sum >= target) {
                int temp = right - left; //窗口长度
                temp < min_len ? min_len = temp : min_len;

                // 窗口左边界增加使得窗口缩小
                sum -= nums[left];
                left++; 
            }

        } 

        if (min_len == len + 1) return 0;
        else return min_len;
    }
};
// @lc code=end

