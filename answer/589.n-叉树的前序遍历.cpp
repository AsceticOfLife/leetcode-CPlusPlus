/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N 叉树的前序遍历
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

        res.push_back(node->val);
        for (int i = 0; i < node->children.size(); ++i) {
            traverse(node->children[i], res);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> res;
        
        traverse(root, res);

        return res;
    }
};
// @lc code=end

