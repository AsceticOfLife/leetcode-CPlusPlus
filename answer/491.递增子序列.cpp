/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void BackTrace(const vector<int> &nums, const int start_index) {
        if (path.size() > 1) result.push_back(path);

        // 终止条件
        if (start_index >= nums.size()) return;

        unordered_set<int> uset; // 使用set对本层元素进行去重
        // 单层处理逻辑
        // 遍历从start_index开始的元素，逐一加入到path中
        for (int i = start_index; i < nums.size(); ++i) {
            // 树层重复
            if (uset.find(nums[i]) != uset.end()) 
                continue;
            
            if (path.size() == 0 || nums[i] >= path.back()) {
                // 当前元素必须大于等于path末尾元素
                path.push_back(nums[i]);
                uset.insert(nums[i]);

                BackTrace(nums, i + 1);

                path.pop_back();
                
            }  else {
                continue;
            }
        }
     }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        BackTrace(nums, 0);

        return result;
    }
};
// @lc code=end

