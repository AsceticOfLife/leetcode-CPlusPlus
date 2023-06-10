/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
    // 采用递归的方法
    int max_depth = 0;
    int res;
    void traversal(TreeNode *cur, int depth) {
        if (cur->left == nullptr && cur->right == nullptr) {
            if (depth > max_depth) {
                max_depth = depth;
                res = cur->val;
            }

            return ;
        }

        if (cur->left) {
            depth++;
            traversal(cur->left, depth);
            depth--;
        }

        if (cur->right) {
            depth++;
            traversal(cur->right, depth);
            depth--;
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return -1;
        traversal(root, 1);

        return res;
    }
};
// @lc code=end

