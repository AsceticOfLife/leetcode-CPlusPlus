/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used; // every nums is used or not

    void BackTrace(const vector<int> &nums) {
        // 终止条件
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        // 单层处理逻辑
        // 遍历集合所有元素
        for (int i = 0; i < nums.size(); ++i) {
            int temp = nums[i];

            // 避免递归树层重复
            if (i > 0 && nums[i - 1] == temp && used[i - 1] == false)
                continue;
            
            // 当前元素没有被使用过
            if (used[i] == false) {
                path.push_back(temp);
                used[i] = true;

                BackTrace(nums);

                path.pop_back();
                used[i] = false;
            }

        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());
        
        BackTrace(nums);

        return result;
    }
};
// @lc code=end

