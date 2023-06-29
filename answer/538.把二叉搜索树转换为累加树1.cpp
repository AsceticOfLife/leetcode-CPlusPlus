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
    TreeNode* convertBST(TreeNode* root) {
        TreeNode *pre = nullptr;

        // 首先采用中序遍历求取总和
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->right;
            } else {
                cur = st.top();
                st.pop();

                // 处理中间结点
                if (pre) {
                    cur->val += pre->val;
                }
                pre = cur;

                cur = cur->left;
            }
        }

        return root;
    }
};
// @lc code=end

