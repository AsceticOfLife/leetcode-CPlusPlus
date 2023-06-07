/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    // 使用前序遍历求深度
    int res;
    // 求以root为根节点的深度
    // depth 表示从根节点到当前节点的深度
    void getDepth(TreeNode *root, int depth) {
        res  = depth > res ? depth : res;
        // 深度是从根节点到当前节点的结点个数
        if (root->left == nullptr && root->right == nullptr) return;

        if (root->left) {
            depth++;
            getDepth(root->left, depth);
            depth--;
        }

        if (root->right) {
            depth++;
            getDepth(root->right, depth);
            depth--;
        }

        return ;
    }

    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        res = 0;
        getDepth(root, 1);

        return res;
    }
};
// @lc code=end

