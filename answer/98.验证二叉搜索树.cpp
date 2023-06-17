/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    // 采用递归方式判断
    // 二叉搜索树中序遍历是一个有序序列
    long long  last_val = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;

        bool left = isValidBST(root->left);

        // 更新上一次的值
        if (last_val >= root->val) return false;
        else last_val = root->val;

        bool right = isValidBST(root->right);

        return left && right;
    }
};
// @lc code=end

