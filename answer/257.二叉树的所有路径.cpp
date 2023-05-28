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
    void traverse(TreeNode *node, vector<int> &path, vector<string> &res) {
        // 添加中间结点
        path.push_back(node->val);

        // 递归终止条件
        if (node->left == nullptr && node->right == nullptr) {
            // 此时path是一条路径
            string sPath;
            for (int i = 0; i < path.size() - 1; ++i) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            res.push_back(sPath);

            return;
        }

        // 尝试左孩子递归
        if (node->left) {
            traverse(node->left, path, res);
            // 回溯
            path.pop_back();
        }

        if (node->right) {
            traverse(node->right, path, res);
            path.pop_back();
        }

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if (root == nullptr) return res;

        traverse(root, path, res);

        return res;
    }
};
// @lc code=end

