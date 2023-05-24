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
        vector<int> temp;
        queue<TreeNode *> qu;
        // 每一层用一个空结点区分
        if (root != nullptr) {
            qu.push(root);
            qu.push(nullptr);
        } else return res;
        while (qu.size() > 1 || qu.front() != nullptr) {
            // 取出队首元素
            TreeNode *node = qu.front();
            if (node != nullptr) {
                // 不为空层数不增加
                qu.pop();

                // 处理结点
                temp.push_back(node->val);

                // 并尝试将左右结点队
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
            } else {
                // 当队首元素为null说明这一层已经结束
                // 层数加1
                // 并且该层的孩子们（也就是下一层）也都入队，再加一个空结点
                qu.pop();
                res.push_back(temp);
                temp = vector<int>();
                qu.push(nullptr);
            }
        }
        if (temp.size() != 0) res.push_back(temp);

        return res;
    }
};
// @lc code=end

