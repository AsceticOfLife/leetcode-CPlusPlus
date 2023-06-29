/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode *pre;
    // 使用递归方法
    void traversal(TreeNode *cur) {
        if (cur == nullptr) return;

        traversal(cur->right);

        // 处理当前结点
        if (pre) cur->val += pre->val;
        pre = cur;

        traversal(cur->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        pre = nullptr;

        traversal(root);

        return root;
    }
};
// @lc code=end

