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
    int countNodes(TreeNode* root) {
        queue<TreeNode *> que;
        int deepth = 0;

        if (root) que.push(root);
        while (!que.empty()) {
            int size = que.size();
            // 加上这一层的结点数
            deepth += size;

            for (int i = 0; i < size; ++i) {
                TreeNode *node = que.front();
                que.pop();

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }

        return deepth;
    }
};
// @lc code=end

