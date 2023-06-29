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
    int sum;
    TreeNode *pre;
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        pre = nullptr;

        // 首先采用中序遍历求取总和
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while (cur != nullptr || !st.empty()) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();

                // 处理中间结点
                sum += cur->val;
                cur = cur->right;
            }
        }

        // 中序遍历处理二叉搜索树
        cur = root;
        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();

                if (pre) {
                    sum -= pre->val;
                } else pre = new TreeNode(cur->val);
                pre->val = cur->val;
                cur->val = sum;

                cur = cur->right;
            }
        }

        if (pre) delete pre;
        return root;
    }
};
// @lc code=end

