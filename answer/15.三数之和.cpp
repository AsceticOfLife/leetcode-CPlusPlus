/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    // 使用双指针
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            // 如果三元组第一个元素大于零，就不可能和为0
            if (nums[i] > 0) return res;

            // 去重元素a
            // 即a字符与上一个a字符一样，这是重复
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    // 左右指针相等的都是重复的
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    
                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;            
                }
            }


        }


        return res;
    }
};
// @lc code=end

