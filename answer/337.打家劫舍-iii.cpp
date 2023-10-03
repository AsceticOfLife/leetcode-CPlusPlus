/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
    vector<int> RobTree(TreeNode *cur) {
        if (cur == nullptr) return vector<int> {0, 0};

        // 计算左右孩子的返回值
        vector<int> left = RobTree(cur->left);
        vector<int> right = RobTree(cur->right);

        vector<int> result{0, 0};
        // 不偷当前结点的值
        result[0] = max(left[0], left[1]) + max(right[0], right[1]);
        // 偷当前结点的值
        result[1] = cur->val + left[0] + right[0];

        return result;
    }

    int rob(TreeNode* root) {
        vector<int> result = RobTree(root);

        return max(result[0], result[1]);
    }
};
// @lc code=end

