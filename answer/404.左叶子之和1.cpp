/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        stack<TreeNode *> st;
        // 采用迭代前序遍历方式
        if (root) st.push(root);

        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();

            // 处理当前根节点
            if (node->left != nullptr && node->left->left == nullptr &&
                node->left->right == nullptr) 
                res += node->left->val;
            
            // 右左孩子入栈
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }

        return res;
    }
};
// @lc code=end

