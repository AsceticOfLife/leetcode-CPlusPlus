/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    void left_sum(TreeNode *cur, int &res) {
        if (cur == nullptr) return;

        // 存在左叶子结点
        if (cur->left != nullptr && cur->left->left == nullptr &&
            cur->left->right == nullptr)
            res += cur->left->val;
        
        // 处理左右孩子
        left_sum(cur->left, res);
        left_sum(cur->right, res);

    }

    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        left_sum(root, res);

        return res;
    }
};
// @lc code=end

