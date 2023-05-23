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
            // 首先取出栈顶结点访问
            TreeNode *node = st.top();
            st.pop();

            // 遍历元素
            res.push_back(node->val);
            if (node->left) st.push((node->left));
            if (node->right) st.push(node->right);
            
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end

