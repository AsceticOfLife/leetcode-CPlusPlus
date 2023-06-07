/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    // 求以cur为根节点的树的高度
    // 使用栈模拟后序遍历
    // 当前结点最大深度就是高度
    int getDepth(TreeNode *cur) {
        stack<TreeNode *> st;

        if (cur != nullptr) st.push(cur);
        int depth = 0;
        int res = 0;

        while (!st.empty()) {
            TreeNode *node = st.top();
            if (node != nullptr) {
                st.pop();

                st.push(node);
                st.push(nullptr);

                depth++;

                if (node->right) st.push(node->right);
                if (node->left) st.push(node->left);
            } else {
                st.pop();
                st.pop();
                depth--;
            }

            res = (res > depth ? res : depth);
        }

        return res;
    }

    bool isBalanced(TreeNode* root) {
        stack<TreeNode *> st;
        if (root == nullptr) return true;
        st.push(root);

        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();

            // 计算根节点的左右孩子是否为差值在1以内
            if (abs(getDepth(node->left) - getDepth(node->right) > 1))
                return false;

            // 左右孩子入栈
            if (node->right) st.push(node->right);
            if (node->left) st.push(node->left);
        }

        return true;
    }
};
// @lc code=end

