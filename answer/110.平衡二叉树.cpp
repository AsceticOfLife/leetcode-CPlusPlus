/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    // 求以root为根节点的树的高度
    // 如果不是平衡二叉树返回-1
    int getHeight(TreeNode *root) {
        if (root == nullptr) return 0;

        // 判断左子树和右子树的“高度”
        int left_height = getHeight(root->left);
        if (left_height == -1) return -1;
        int right_height = getHeight(root->right);
        if (right_height == -1) return -1;

        if (abs(left_height - right_height) > 1) 
            return -1;
        else return 1 + max(left_height, right_height);
    }

    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};
// @lc code=end

