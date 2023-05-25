/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode *> que;

        // 首先将根节点入队
        if (root) que.push(root);

        while (!que.empty()) {
            // 每次遍历一层
            // 记录当前队列中还剩多少同层元素
            int size = que.size();
            // 访问同层元素
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();

                // 访问该结点
                temp.push_back(node->val);

                // 左右孩子入队
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }

            // 该层元素保存
            res.push_back(temp);
        }

        return res;
    }
};
// @lc code=end

