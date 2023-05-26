/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode *> que;

        if (root) que.push(root);
        int max_val;
        while (!que.empty()) {
            int size = que.size();
            // 首先取出第一个结点的值
            TreeNode *node = que.front();
            que.pop();
            max_val = node->val;
            // 将左右孩子入队
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
            
            for (int i = 1; i < size; ++i) {
                node = que.front();
                que.pop();

                max_val < node->val ? max_val = node->val : max_val;

                // 尝试将左右孩子入队
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }

            res.push_back(max_val);
        }
        
        return res;
    }
};
// @lc code=end

