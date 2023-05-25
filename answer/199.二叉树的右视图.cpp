/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode *> que;

        // 尝试将根节点入队
        if (root) que.push(root);
        while (!que.empty()) {
            // 每次遍历一层
            int size = que.size();
            // 第size个元素就是本层最右边一个
            TreeNode *node;
            for (int i = 0; i < size - 1; ++i) {
                // 将本层除了最后一个的孩子都入队
                node = que.front();
                que.pop();

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            // 此时头元素是本层最右结点
            node = que.front();
            que.pop();
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);

            res.push_back(node->val);
        }

        return res;
    }
};
// @lc code=end

