/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

// @lc code=start
class Solution {
public:
    // 
    int count;
    bool result;
    void DFS(const vector<vector<int>> &rooms, int index, vector<bool> &visited) {
        // 终止条件
        if (count == rooms.size()) {
            result = true;
            return;
        }

        // 单层处理逻辑
        // 遍历下一步可访问的节点
        vector<int> next_rooms(rooms[index]);
        for (int i = 0; i < next_rooms.size(); ++i) {
            int next_index = next_rooms[i];
            
            // 如果已经访问过就跳过
            if (visited[next_index]) continue;

            count++;
            visited[next_index] = true;
            DFS(rooms, next_index, visited);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        count = 1;
        result = false;
        vector<bool> visited(rooms.size(), false);
        visited[0] = true;

        DFS(rooms, 0, visited);

        return result;
    }
};
// @lc code=end

