/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        // 创建一个hash表用于保存变化过程中已经出现的数字
        unordered_set<int> hash_table;

        int temp = n; // 保存中间变量
        while (hash_table.find(temp) == hash_table.end()) {
            hash_table.insert(temp);

            int sum = 0;
            while (temp != 0) {
                sum += pow(temp % 10, 2);
                temp /= 10;
            }

            temp = sum;
            if (temp == 1) return true;
        }

        return false;
    }
};
// @lc code=end

