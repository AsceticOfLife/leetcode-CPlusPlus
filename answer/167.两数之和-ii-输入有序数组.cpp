/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
// #include <vector>
// using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low, high;
        low = 0;
        high = numbers.size() - 1;

        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) 
                return vector<int> {low + 1, high + 1};
            else if (sum < target) low++;
            else high--;
        }

        return vector<int> {-1, -1};
    }
};
// @lc code=end

