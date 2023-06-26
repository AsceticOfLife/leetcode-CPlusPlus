/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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
    // 记录需要被删除的节点的父结点
    TreeNode *pre;
    int flag;   // 0表示左，1表示右
    // 使用递归
    // 如果找到结点删除并返回这个节点的指针
    // 否则返回空指针
    TreeNode * travesal(TreeNode *cur, int key) {
        if (cur == nullptr) return cur;

        if (key < cur->val) {
            pre = cur;
            flag = 0;
            return travesal(cur->left, key);
        } else if (key > cur->val) {
            pre = cur;
            flag = 1;
            return travesal(cur->right, key);
        } else {
            // 当前结点就是需要被删除的结点
            if (cur->left == nullptr && cur->right == nullptr) {
                if (flag == 0) pre->left = nullptr;
                else pre->right = nullptr;

                return cur;
            } else if (cur->left == nullptr) {
                if (flag == 0) pre->left = cur->right;
                else pre->right = cur->right;

                return cur;
            } else if (cur->right == nullptr) {
                if (flag == 0) pre->left = cur->left;
                else pre->right = cur->left;

                return cur;
            } else {
                // 首先找到当前节点的右子树的最左孩子
                TreeNode *temp = cur->right;
                while (temp->left) temp = temp->left;

                // 找到之后把当前结点的左子树作为寻找到的目标节点的左孩子
                temp->left = cur->left;

                // 连接上父结点
                if (flag == 0) pre->left = cur->right;
                else pre->right = cur->right;

                return cur;
            }
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *head = new TreeNode;
        pre = head;
        flag = 0;
        head->left = root;

        TreeNode *delete_node = travesal(root, key);
        if (delete_node) delete delete_node;

        TreeNode *temp = head;
        head = head->left;
        delete temp;
        
        return head;
    }
};
// @lc code=end

