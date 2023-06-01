/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode *> que;
        que.push(root->left);
        que.push(root->right);

        while (!que.empty()) {
            TreeNode *node1 = que.front();
            que.pop();
            TreeNode *node2 = que.front();
            que.pop();
            // 注意都为空的情况
            if (node1 == nullptr && node2 == nullptr) continue;

            // 比较两个结点
            if (node1 == nullptr || node2 == nullptr || node1->val != node2->val)
                return false;
            
            // 注意放入队列顺序
            que.push(node1->left);
            que.push(node2->right);
            
            que.push(node1->right);
            que.push(node2->left);
        }

        return true;
    }
};
// @lc code=end

