/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        queue<TreeNode *> que;
        int depth = 0;
        if (root) que.push(root);
        else return depth;
        
        while (!que.empty()) {
            depth++;
            int size = que.size();

            for (int i = 0; i < size; ++i) {
                TreeNode *node = que.front();
                que.pop();

                if (node->left == nullptr && node->right == nullptr) return depth;
                else {
                    if (node->left) que.push(node->left);
                    if (node->right) que.push(node->right);
                }
            }
        }

        return depth;
    }
};
// @lc code=end

