/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int getNum(TreeNode *root) {
        if (root == nullptr) return 0;
        // 根据左右结点深度判断是否为满二叉树
        int left_depth, right_depth;
        left_depth = right_depth = 0;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        while (left) {
            left_depth++;
            left = left->left;
        }

        while (right) {
            right_depth++;
            right = right->right;
        }

        if (left_depth == right_depth) {
            return (2 << left_depth) - 1;
        }

        return getNum(root->left) + getNum(root->right) + 1;
    }

    int countNodes(TreeNode* root) {
        return getNum(root);
    }
};
// @lc code=end

