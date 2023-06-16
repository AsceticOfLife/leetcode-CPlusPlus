/*
 * @lc app=leetcode.cn id=700 lang=cpp
 *
 * [700] 二叉搜索树中的搜索
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
    TreeNode * searchCore(TreeNode *cur, int val) {
        if (cur == nullptr) return nullptr;
        if (cur->val == val) {
            // 此时cur是目标根节点
            return cur;
        } else {
            TreeNode *res = nullptr;
            if (cur->val > val) res = searchCore(cur->left, val);
            if (cur->val < val) res = searchCore(cur->right, val);

            return res;
        }
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return searchCore(root, val);
    }
};
// @lc code=end

