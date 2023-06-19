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
    vector<int> res;
    int count;
    int max_count;
    TreeNode *pre_node;
    void traversal(TreeNode *cur) {
        if (cur == nullptr) return;

        // 先处理左子树，让pre_node更新
        traversal(cur->left);

        // 当前中间节点的值如果等于上一个节点的值
        if (pre_node && cur->val == pre_node->val) count++;
        // 当pre_node为空结点时，重新计数
        // 当遇到不相等的结点时，重新计数
        else count = 1;
        
        pre_node = cur;

        // 判断如果出现次数等于最大次数
        if (count == max_count) res.push_back(cur->val);
        else if (count > max_count) {
            res.clear();
            res.push_back(cur->val);
            max_count = count;
        }

        traversal(cur->right);
    }

    vector<int> findMode(TreeNode* root) {
        count = 0;
        max_count = 0;
        pre_node = nullptr;

        traversal(root);

        return res;
    }
};
// @lc code=end

