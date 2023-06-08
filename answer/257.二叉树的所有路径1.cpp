/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    // 使用迭代法
    // 一个栈用于模拟前序遍历
    // 一个栈用于保存路径
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode *> treest;
        stack<string> pathst;
        vector<string> res;

        if (root == nullptr) return res;
        treest.push(root);
        pathst.push(to_string(root->val));

        // 迭代法前序遍历
        while (!treest.empty()) {
            TreeNode *node = treest.top();
            treest.pop();

            string path = pathst.top();
            pathst.pop();

            // 判断是否为叶子结点
            if (node->left == nullptr && node->right == nullptr) {
                res.push_back(path);
            }

            if (node->right) {
                pathst.push(path + "->" + to_string(node->right->val));
                treest.push(node->right);
            }

            // 对于左孩子不为空
            if (node->left) {
                pathst.push(path + "->" + to_string(node->left->val));
                treest.push(node->left);
            }


        }

        return res;
    }
};
// @lc code=end

