/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    bool compare(TreeNode *node1, TreeNode *node2) {
        // 二者中存在空结点
        if (node1 == nullptr && node2 != nullptr) return false;
        else if (node1 != nullptr && node2 == nullptr) return false;
        else if (node1 == nullptr && node2 == nullptr) return true;
        else if (node1->val != node2->val) return false;

        // 剩余情况就是连个结点都不为空且两个节点的值相等
        // 比较左孩子结点
        bool left = compare(node1->left, node2->left);
        // 比较右孩子
        bool right = compare(node1->right, node2->right);

        return left && right;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p, q);
    }
};
// @lc code=end

