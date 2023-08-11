/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, map<string, int>> targets;

    bool BackTrace(const int tickets_num, vector<string> &result) {
        // 终止条件
        if (result.size() == tickets_num + 1) return true;

        // 单层处理逻辑
        string start = result.back();
        for (pair<const string, int> &target : targets[start]) {
            // 当票数大于0时
            if (target.second > 0) {
                result.push_back(target.first);
                target.second--;
                
                // 当找到一条路径时
                if (BackTrace(tickets_num, result)) return true;

                result.pop_back();
                target.second++;
            }
        } 

        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> result;

        // 记录票数
        for (const vector<string> &vec : tickets) 
            targets[vec[0]][vec[1]]++;

        result.push_back("JFK");
        BackTrace(tickets.size(), result);

        return result;
    }
};
// @lc code=end

