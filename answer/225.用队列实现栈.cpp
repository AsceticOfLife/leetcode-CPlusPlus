/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include <queue>

using std::queue;

class MyStack {
private:
    queue<int> queue1;
    queue<int> queue2;
public:
    MyStack() {

    }
    
    void push(int x) {
        // 谁不为空就入哪个队列
        if (!queue1.empty()) queue1.push(x);
        else queue2.push(x);
    }
    
    int pop() {
        // 谁有元素就把所有元素全部入到另一队列
        int x;
        if (!queue1.empty()) {
            int size = queue1.size();
            size--;
            while (size--) {
                x = queue1.front();
                queue1.pop();

                queue2.push(x);
            }
            // 此时转移了size-1个元素，队列中还剩下最后一个元素
            x = queue1.front();
            queue1.pop();
            
        } else {
            int size = queue2.size();
            size--;
            while (size--) {
                x = queue2.front();
                queue2.pop();

                queue1.push(x);
            }
            // 此时转移了size-1个元素，队列中还剩下最后一个元素
            x = queue2.front();
            queue2.pop();
        }

        return x;
    }
    
    int top() {
        int x = pop();
        push(x);
        return x;
        
    }
    
    bool empty() {
        return queue1.empty() && queue2.empty();
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

