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
    // 将两个树合并
    TreeNode * mergeCore(TreeNode *cur1, TreeNode *cur2) {
        if (cur1 == nullptr) return cur2;
        if (cur2 == nullptr) return cur1;

        cur1->val += cur2->val;

        cur1->left = mergeCore(cur1->left, cur2->left);
        cur1->right = mergeCore(cur1->right, cur2->right);

        return cur1;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return mergeCore(root1, root2);
    }
};
// @lc code=end

