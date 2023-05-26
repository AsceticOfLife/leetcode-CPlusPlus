/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node *> que;

        // 尝试将根节点入队
        if (root) que.push(root);
        while (!que.empty()) {
            vector<int> layer;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                Node *node = que.front();
                que.pop();

                // 访问结点
                layer.push_back(node->val);

                // 将所有孩子入队
                for (int i = 0; i < node->children.size(); ++i) {
                    que.push(node->children[i]);
                }
            }

            res.push_back(layer);
        }

        return res;
    }
};
// @lc code=end

