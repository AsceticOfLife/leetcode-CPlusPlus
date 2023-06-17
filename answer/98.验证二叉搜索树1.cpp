/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    // 采用迭代方式判断
    // 二叉搜索树中序遍历是一个有序序列
    long long  last_val = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;

        stack<TreeNode *> st;
        st.push(root);
        long long last_val = LONG_MIN;

        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();

            if (node != nullptr) {
                // 先将右孩子入栈
                if (node->right) st.push(node->right);

                // 再将中间结点入栈并标记
                st.push(node);
                st.push(nullptr);

                // 最后左孩子入栈
                if(node->left) st.push(node->left);
            } else {
                // 空结点代表标记已经出栈
                node = st.top(); st.pop();

                // 处理当前结点
                if (node->val <= last_val) return false;
                else last_val = node->val;
            }
        }

        return true;
    }
};
// @lc code=end

