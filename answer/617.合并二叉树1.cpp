/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        
        // 适用队列进行层序遍历
        queue<TreeNode *> que;
        que.push(root1);
        que.push(root2);
        while (!que.empty()) {
            TreeNode *node1 = que.top(); que.pop();
            TreeNode *node2 = que.top(); que.pop();

            // 此时两个结点不为空
            node1->val += node2->val;

            // 如果两个树的左节点都不为空
            if (node1->left && node2->left) {
                que.push(node1->left);
                que.push(node2->left);
            }

            // 如果两个结点的右节点都不为空
            if (node1->right && node2->right) {
                que.push(node1->right);
                que.push(node2->right);
            }

            // 如果第一棵树左节点为空
            if (!node1->left && node2->left) 
                node1->left = node2->left;
            // 如果第一颗树右节点为空
            if (!node1->right && node2->right) 
                node1->right = node2->right;
        }

        return root1;
    }
};
// @lc code=end

