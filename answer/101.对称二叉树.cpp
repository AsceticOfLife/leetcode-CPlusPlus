/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool compare(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right != nullptr) return false;
        else if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right == nullptr) return true;
        else if (left->val != right->val) return false;

        // 剩下的情况是左右节点都不为空且相等的情况
        // 左边子树按照左右中顺序，右边子树按照右左中顺序
        // 比较外侧和里侧
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);

        return outside && inside;
    }


    bool isSymmetric(TreeNode* root) {
        int flag = true;
        if (root) flag = compare(root->left, root->right);

        return flag;
    }
};
// @lc code=end

