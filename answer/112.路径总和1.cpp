/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    // 递归方式遍历
    bool traversal(TreeNode *cur, int sum) {
        if (cur->left == nullptr && cur->right == nullptr) {
            if (sum == 0) return true;
            else return false;
        }

        if (cur->right) {
            if (traversal(cur->right, sum - cur->right->val)) 
                return true;
        }

        if (cur->left) {
            if (traversal(cur->left, sum - cur->left->val))
            return true;
        }

        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;

        return traversal(root, targetSum - root->val);
    }
};
// @lc code=end

