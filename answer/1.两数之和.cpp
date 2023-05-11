 /*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_table;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (hash_table.count(target - nums[i]) == 0) hash_table[nums[i]] = i;
            else return vector<int>{hash_table[target - nums[i]], i};
        }

        return vector<int>{-1, -1};
    }
};
// @lc code=end

