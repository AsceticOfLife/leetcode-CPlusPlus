/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        // 创建一个hash用于保存数组1和2元素之和出现的次数
        unordered_map<int, int> hash_table;

        for (int a : nums1) 
            for (int b : nums2) 
                hash_table[a + b]++;

        // 遍历剩下两个数组，判断四个元素之和为0出现的次数
        int count = 0;
        for (int c : nums3) 
            for (int d : nums4) 
                if (hash_table.find(-(c + d)) != hash_table.end())
                    count += hash_table[-(c + d)];

        return count;
    }
};
// @lc code=end

