/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    void order(TreeNode *root, vector<vector<int>> &res, int depth) {
        if (root == nullptr) return;
        if (res.size() == depth) res.push_back(vector<int>());

        // 先访问根结点
        res[depth].push_back(root->val);
        // 处理左右孩子
        order(root->left, res, depth + 1);
        order(root->right, res, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int depth = 0;
        order(root, res, depth);

        return res;
    }
};
// @lc code=end

