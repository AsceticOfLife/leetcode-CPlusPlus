/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) return -1;
        stack<TreeNode *> st;
        TreeNode *last_node = nullptr;
        int res = INT_MAX;
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();

            if (node != nullptr) {
                // 右孩子入栈
                if (node->right) st.push(node->right);

                // 中间结点入栈以及使用一个空结点标记
                st.push(node);
                st.push(nullptr);

                // 左孩子入栈
                if (node->left) st.push(node->left);
            } else {
                // 处理根节点
                node = st.top();
                st.pop();

                if (last_node == nullptr) {
                    last_node = node;
                    continue;
                };

                res = min(res, node->val - last_node->val);
                last_node = node;
            }
        }

        return res;
    }
};
// @lc code=end

