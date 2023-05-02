/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> differ(n, 0);

        for (int i = 0; i < bookings.size(); i++) {
            differ[bookings[i][0] - 1] += bookings[i][2];
            if (bookings[i][1] < differ.size()) 
                differ[bookings[i][1]] -= bookings[i][2];
            
        }

        vector<int> res(differ.size(), 0);
        res[0] = differ[0];
        for (int i = 1; i < differ.size(); i++) {
            res[i] = res[i-1] + differ[i];
        }

        return res;
    }
};
// @lc code=end

