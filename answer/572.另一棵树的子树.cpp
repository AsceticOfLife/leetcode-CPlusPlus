/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // 遍历root所有结点，判断以任何节点为根节点的树是否与子树相同
        // 使用前序遍历
        queue<TreeNode *> que;
        if (root) que.push(root);
        while (!que.empty()) {
            TreeNode *node = que.front();
            que.pop();
            // 处理中结点
            if (compare(node, subRoot)) return true;

            // 右左孩子入队
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }

        return false;
    }
};
// @lc code=end

