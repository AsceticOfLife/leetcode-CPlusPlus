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
        int mid = 0;

        for (i = 1; i < len; i++) {
            if (abs(nums[i]) < abs(nums[mid])) mid = i;
        }

        for (i = 0; i < len; i++) nums[i] = nums[i] * nums[i];


        vector<int> res(len);
        i = 0;
        if (mid < len) {
            res[i++] = nums[mid];
        }
        
        int left = mid - 1;
        int right = mid + 1;

        while (left >= 0 && right < len) {
            if (nums[left] <= nums [right]) {
                res[i++] = nums[left];
                left--;
            } else {
                res[i++] = nums[right];
                right++;
            }
        }

        if (left >= 0) {
            while (left >= 0) {
                res[i++] = nums[left--];
                // left--;
            }
        }

        if (right < len) {
            while (right < len) {
                res[i++] = nums[right++];
                // right++;
            }
        }

        return res;
    }
};
// @lc code=end

