/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> map;
        // 初始化三种面值
        map[5] = 0;
        map[10] = 0;
        map[20] = 0; 

        for (int i = 0; i < bills.size(); ++i) {
            if (bills[i] == 5) {
                map[5]++;
            } else if (bills[i] == 10) {
                // 只能找回一张5元面额
                if (map[5] == 0) return false; // 没有5元面额
                map[5]--;
                map[10]++;
            } else {
                // 尽量使用10元和5元混合
                if (map[5] >= 1 && map[10] >= 1) {
                    map[5]--;
                    map[10]--;                    
                } else if (map[5] >= 3) {
                    map[5] -= 3;
                } else {
                    return false;
                }
            }
        }

        // 循环完毕
        return true;
    }
};
// @lc code=end

