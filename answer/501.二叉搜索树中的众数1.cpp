/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    // 采用迭代法
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int count = 0;
        int max_count = 0;
        TreeNode *pre_node = nullptr;

        stack<TreeNode *> st;
        if (root) st.push(root);
        
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();

            if (node != nullptr) {
                if (node->right) st.push(node->right);

                st.push(node);
                st.push(nullptr);

                if (node->left) st.push(node->left);
            } else {
                node = st.top();
                st.pop();

                // 中间结点处理逻辑
                if (pre_node && node->val == pre_node->val) count++;
                else count = 1;

                pre_node = node;

                if (count == max_count) res.push_back(node->val);
                else if (count > max_count) {
                    res.clear();
                    res.push_back(node->val);
                    max_count = count;
                } 
            } // end of if node == nullptr
        } // end of while st is empty

        return res;
    }
};
// @lc code=end

