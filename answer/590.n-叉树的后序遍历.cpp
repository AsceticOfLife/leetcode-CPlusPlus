/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
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
    void traverse(Node *node, vector<int> &res) {
        if (node == nullptr) return;

        for (int i = 0; i < node->children.size(); ++i) {
            traverse(node->children[i], res);
        }
        res.push_back(node->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> res;

        traverse(root, res);

        return res;
    }
};
// @lc code=end

