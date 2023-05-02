/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int times_up_down = trips.size();
        if (times_up_down == 0) return true;

        int length = trips[times_up_down - 1][2] + 1;
        vector<int> differ(length, 0);
        
        for (int i = 0; i < times_up_down; i++) {
            int max_len = trips[i][2];
            if (length < max_len + 1) {
                differ.resize(max_len + 1, 0);
                length = max_len + 1;
            }

            differ[trips[i][1]] += trips[i][0];
            if (trips[i][2] <= length)  
                differ[trips[i][2]] -= trips[i][0];
            
        }
        
        if (differ[0] > capacity) return false;
        
        vector<int> res(length, 0);
        res[0] = differ[0];
        
        for (int i = 1; i < length; i++) {
            int tmp = res[i - 1] + differ[i];
            if (tmp > capacity) return false;
            else res[i] = tmp;
        }

        return true;
    }
};
// @lc code=end

