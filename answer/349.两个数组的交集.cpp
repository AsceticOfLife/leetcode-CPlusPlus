/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();

        // 创建一个hash_table
        unordered_map<int, int> hash_table;

        // 遍历第一个集合统计字符个数
        for (int i = 0; i < len1; i++) hash_table[nums1[i]]++;

        vector<int> res;
        // 遍历第二个集合，如果hash表中的值不为0就是集合中的元素
        for (int x : nums2) {
            if (hash_table.count(x)) {
                res.push_back(x);
                // 并把这个值对应的hash表中的值置零
                hash_table.erase(x);
            }
        }

        return res;
    }
};
// @lc code=end

