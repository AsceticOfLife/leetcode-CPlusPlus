/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int getHeight(TreeNode *root) {
        if (root == nullptr) return 0;

        int depth_left = getHeight(root->left);
        int depth_right = getHeight(root->right);
        int res;
        depth_left > depth_right ? res = depth_left + 1: res = depth_right + 1;
        
        return res;
    }

    int maxDepth(TreeNode* root) {
        return getHeight(root);
    }
};
// @lc code=end

