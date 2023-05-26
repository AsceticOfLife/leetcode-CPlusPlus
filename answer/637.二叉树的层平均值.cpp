/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode *> que;

        // 尝试将根结点入队
        if (root) que.push(root);
        long long sum ;
        while (!que.empty()) {
            sum = 0;
            int size = que.size();

            for (int i = 0; i < size; ++i) {
                TreeNode *node = que.front();
                que.pop();

                sum += node->val;

                // 尝试将左右孩子入队
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);    
            }

            res.push_back(double(sum) / size);
        }

        return res;
    }
};
// @lc code=end

