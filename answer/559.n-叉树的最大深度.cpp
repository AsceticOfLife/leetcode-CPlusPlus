/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N 叉树的最大深度
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node *> que;
        int depth = 0;

        if (root) que.push(root);

        while (!que.empty()) {
            int size = que.size();
            // 此时队列中为一层
            depth++;

            for (int i = 0; i < size; ++i) {
                Node *node = que.front();
                que.pop();

                // 所有孩子入队
                for (int j = 0; j < node->children.size(); ++j)
                    que.push(node->children[j]);
            }
            
        }

        return depth;
    }
};
// @lc code=end

