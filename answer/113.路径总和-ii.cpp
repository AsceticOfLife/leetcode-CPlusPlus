/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    // 采用递归遍历二叉树
    void traverseal(TreeNode *cur, int targetSum, vector<int> &path, vector<vector<int>> &res) {
        path.push_back(cur->val);
        targetSum -= cur->val;

        if (cur->left == nullptr && cur->right == nullptr &&
            targetSum == 0) {
            res.push_back(path);
            return;
        }

        // 处理左孩子
        if (cur->left) {
            traverseal(cur->left, targetSum, path, res);
            path.pop_back();
        }

        // 处理右孩子
        if (cur->right) {
            traverseal(cur->right, targetSum, path, res);
            path.pop_back();
        }

    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        if (root == nullptr) return res;

        traverseal(root, targetSum, path, res);

        return res;
    }
};
// @lc code=end

