/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
        
        if (root->val > p->val && root->val > q->val) {
            TreeNode *left = lowestCommonAncestor(root->left, p, q);
            if (left) return left;
        }

        if (root->val < p->val && root->val < q->val) {
            TreeNode *right = lowestCommonAncestor(root->right, p, q);
            if (right) return right;
        }

        return root;
    }
};
// @lc code=end

