/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (p == root || q == root) return root;

        // 接收左右子树结果
        TreeNode *left_flag = lowestCommonAncestor(root->left, p, q);
        TreeNode *right_flag = lowestCommonAncestor(root->right, p, q);

        // 根据左右子树判断结果
        if (left_flag && right_flag) return root;
        else if (!left_flag && right_flag) return right_flag;
        else if (left_flag && !right_flag) return left_flag;
        else return nullptr;
    }
};
// @lc code=end

