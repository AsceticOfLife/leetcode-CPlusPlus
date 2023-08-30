/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */

// @lc code=start
class Solution {
public:
    // 比较两个人的属性
    // 首先是身高比较高的站在前面
    // 其次如果身高相同那么久k值小的站前面
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 首先排序保证身高高的站前面
        sort(people.begin(), people.end(), cmp);

        // 然后遍历元素，根据k值将元素插入队列中
        // 因为身高从大到小排列，一定是先将身高高的排在前面，能够满足k值的需要
        // 即使以后再插入元素导致后移也都是小元素，不影响
        // 另外为了刚好满足，所以要其插入到下标为k的地方
        list<vector<int>> que; // list底层是链表实现，插入效率更高
        for (int i = 0; i < people.size(); i++) {
            int index = people[i][1]; // k值，需要插入的位置
            std::list<vector<int>>::iterator it = que.begin();
            while (index--) it++; // 找到合适的插入位置

            que.insert(it, people[i]); 
        }

        return vector<vector<int>>(que.begin(), que.end());
    }
};
// @lc code=end

