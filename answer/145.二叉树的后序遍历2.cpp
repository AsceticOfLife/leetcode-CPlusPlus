/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        // 使用栈保存未访问的结点
        stack<TreeNode *>st;
        vector<int> res;

        if (root == nullptr) return res;
        // 首先将根结点入栈
        st.push(root);

        while (!st.empty()) {
            TreeNode *node = st.top();

            if (node != nullptr) {
                st.pop();
                st.push(node);
                st.push(nullptr);
                // 右、左孩子入栈
                if (node->left) st.push(node->left);
                if (node->right) st.push(node->right);
                

            } else {
                st.pop();
                res.push_back(st.top()->val);
                st.pop();
            }
        }

        return res;
    }
};
// @lc code=end

