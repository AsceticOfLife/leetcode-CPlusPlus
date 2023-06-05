/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int getNum(TreeNode *root) {
        if (root == nullptr) return 0;
        // 左子树结点数
        int left_num = getNum(root->left);
        // 右子树结点数
        int right_num = getNum(root->right);

        return 1 + left_num + right_num;
    }

    int countNodes(TreeNode* root) {
        return getNum(root);
    }
};
// @lc code=end

