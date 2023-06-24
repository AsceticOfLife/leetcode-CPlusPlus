/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    // 使用递归
    void traversal(TreeNode *cur, int val) {
        if (val < cur->val) {
            if (cur->left == nullptr) {
                TreeNode *temp = new TreeNode(val);
                cur->left = temp;
            } else traversal(cur->left, val);
        } else {
            if (cur->right == nullptr) {
                TreeNode *temp = new TreeNode(val);
                cur->right = temp;
            } else traversal(cur->right, val);
        } // end of if val is cur->val
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);

        traversal(root, val);

        return root;
    }
};
// @lc code=end

