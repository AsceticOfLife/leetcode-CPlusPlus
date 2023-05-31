/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode *> que;

        if (root) que.push(root);

        while (!que.empty()) {
            int size = que.size();

            TreeNode *node;
            for (int i = 0; i < size; ++i) {
                node = que.front();
                que.pop();

                // 交换左右结点
                TreeNode *temp = node->left;
                node->left = node->right;
                node->right = temp;

                // 左右孩子入队
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }

        return root;
    }
};
// @lc code=end

