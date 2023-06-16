/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    // 迭代的方法
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *cur = root;
        while (cur) {
            if (cur->val < val) cur = cur->right;
            else if (cur->val > val) cur = cur->left;
            else return cur;
        }

        return nullptr;
    }
};
// @lc code=end

