/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <queue>

using std::queue;

// 使用一个队列完成栈
// 每次出队列之后重新入队即可
class MyStack {
private:
    queue<int> queue;
public:
    MyStack() {

    }
    
    void push(int x) {
        queue.push(x);
    }
    
    int pop() {
        int size = queue.size();
        int x;
        size--;

        while (size--) {
            x = queue.front();
            queue.pop();

            // 重新入队
            queue.push(x);
        }

        // 经过size-1次出队和重新入队
        // 队首就是之前的队尾
        x = queue.front();
        queue.pop();

        return x;
    }
    
    int top() {
        int x = pop();
        push(x);
        return x;
        
    }
    
    bool empty() {
        return queue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

