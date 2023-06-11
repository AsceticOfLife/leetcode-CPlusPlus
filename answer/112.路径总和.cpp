/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 采用迭代方式遍历树
        // 栈中存放当前结点以及从根节点到当前节点的路径总和
        stack<pair<TreeNode *, int>> st;
        
        if (root == nullptr) return false;
        st.push(pair<TreeNode *, int>(root, root->val));

        while (!st.empty()) {
            pair<TreeNode *, int> node = st.top();
            st.pop();

            if (node.first->left == nullptr && node.first->right == nullptr &&
                node.second == targetSum) return true;
            
            if (node.first->right) 
                st.push(pair<TreeNode *, int>(node.first->right, node.second + node.first->right->val));
            
            if (node.first->left)
                st.push(pair<TreeNode *, int>(node.first->left, node.second + node.first->left->val));

        }   

        return false;        
    }
};
// @lc code=end

