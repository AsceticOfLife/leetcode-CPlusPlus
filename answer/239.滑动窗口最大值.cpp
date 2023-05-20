/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <vector>
#include <deque>

using std::vector;
using std::deque;

class Solution {
private:
    // 使用双端队列实现单调队列
    class Myqueue {
    private:
        deque<int> que;
    public:
        void pop(int value) {
            if (!que.empty() && que.front() == value)
                que.pop_front();
        }

        void push(int value) {
            while (!que.empty() && value > que.back())
                que.pop_back();
            
            que.push_back(value);
        }

        int front() {
            return que.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        Myqueue que;
        vector<int> res;

        // 先将前k个元素放进队列
        for (int i = 0; i < k; i++)
            que.push(nums[i]);

        // 记录当前最大值即单调队列的第一个元素
        res.push_back(que.front());

        // 遍历剩下的元素
        for (int i = k; i < nums.size(); i++) {
            // 出队元素
            que.pop(nums[i - k]);

            // 入队元素
            que.push(nums[i]);

            // 记录最大值
            res.push_back(que.front());
        }

        return res;
    }  
};
// @lc code=end

