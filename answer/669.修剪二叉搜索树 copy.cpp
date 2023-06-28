/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    // 使用迭代
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return nullptr;

        // 将头结点移动到[L, R]范围内
        while (root && (root->val < low || root->val > high)) {
            if (root->val < low) root = root->right;
            else root = root->left;
        }

        TreeNode *cur = root;
        // 将根节点的左孩子都小于low节结点删除
        while (cur) {
            while (cur->left && cur->left->val < low) {
                cur->left = cur->left->right;
            }

            cur = cur->left;
        }

        cur = root;
        while (cur) {
            while (cur->right && cur->right->val > high) {
                cur->right = cur->right->left;
            }

            cur = cur->right;
        }

        return root;
    }
};
// @lc code=end

