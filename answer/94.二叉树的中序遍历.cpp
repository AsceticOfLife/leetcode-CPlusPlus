/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode *root, vector<int> &v) {
        if (root == nullptr) return;

        // 递归后序遍历
        traverse(root->left, v);
        v.push_back(root->val);
        traverse(root->right, v);

    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);

        return res;
    }
};
// @lc code=end

