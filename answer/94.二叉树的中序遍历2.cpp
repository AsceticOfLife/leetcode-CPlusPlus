/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        vector<int> res;

        // 根节入栈
        if (root != nullptr) st.push(root);

        while (!st.empty()) {
            TreeNode *node = st.top();

            if (node != nullptr) {
                // 先将这个结点弹出
                st.pop();

                // 尝试将右孩子入栈
                if (node->right != nullptr) st.push(node->right);
                // 将中结点入栈，并且中间结点已经访问过，作为下一次处理的结点需要标记
                st.push(node);
                st.push(nullptr);

                // 最后将左孩子入栈但是不标记
                if (node->left != nullptr) st.push(node->left);
            } else {
                // 如果栈顶是空指针，说明下一个是需要处理的结点
                st.pop();

                // 将需要处理的结点假如列表
                res.push_back(st.top()->val);
                st.pop();
            }
        }

        return res;
    }
};
// @lc code=end

