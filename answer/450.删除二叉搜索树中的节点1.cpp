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
    // 采用迭代法
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *head = new TreeNode;
        TreeNode *pre = head;
        int flag = 0; // 0 for left and 1 for right
        head->left = root;

        TreeNode *cur = root;
        while (cur) {
            if (cur->val > key) {
                // 向左找
                pre = cur;
                cur = cur->left;
                flag = 0;
            } else if (cur->val < key) {
                // 向右找
                pre = cur;
                cur = cur->right;
                flag = 1;
            } else {
                // 当前结点就是需要被删除的结点
                if (cur->left == nullptr && cur->right == nullptr) {
                    if (flag == 0) pre->left = nullptr;
                    else pre->right = nullptr;

                    break;
                } else if (cur->left == nullptr) {
                    if (flag == 0) pre->left = cur->right;
                    else pre->right = cur->right;

                    break;
                } else if (cur->right == nullptr) {
                    if (flag == 0) pre->left = cur->left;
                    else pre->right = cur->left;

                    break;
                } else {
                    // 首先找到当前节点的右子树的最左孩子
                    TreeNode *temp = cur->right;
                    while (temp->left) temp = temp->left;

                    // 找到之后把当前结点的左子树作为寻找到的目标节点的左孩子
                    temp->left = cur->left;

                    // 连接上父结点
                    if (flag == 0) pre->left = cur->right;
                    else pre->right = cur->right;

                    break;
                } // end of if cur->left and cur->right is nullptr 
            } // end of if key is less than cur->val
        } // end of while cur

        if (cur) delete cur;

        // 删除虚拟头节点
        TreeNode *temp = head;
        head = head->left;
        delete temp;

        return head;
    }
};
// @lc code=end

