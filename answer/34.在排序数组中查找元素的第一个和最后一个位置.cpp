/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;

        // 寻找左边开始位置
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) right = mid - 1;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }

        // 循环结束时left == right + 1
        if (left == nums.size()) res.push_back(-1);
        else if (nums[left] == target) res.push_back(left);
        else res.push_back(-1);

        // 寻找右边结束位置
        left = 0;
        right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }

        // 循环结束left == right + 1
        if (left - 1 < 0) res.push_back(-1);
        else if (nums[left - 1] == target) res.push_back(left - 1);
        else res.push_back(-1);

        return res;
    }
};
// @lc code=end

