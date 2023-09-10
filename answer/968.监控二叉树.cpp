/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    int count;

    // 采用先序遍历(递归形式)
    int traverse(TreeNode *cur) {
        // 空结点
        if (cur == nullptr) return 2;
        
        // 先遍历左右孩子
        int left = traverse(cur->left);
        int right = traverse(cur->right);

        // 根据左右孩子的状态推断中间节点的状态
        // 如果左右孩子均为已经覆盖的情况
        // 那么中间节点应该为覆盖状态
        if (left == 2 && right == 2) return 0; 

        // 左右结点至少有一个无覆盖
        if (left == 0 || right == 0) {
            // 此时应该让中间节点进行监视
            count++;
            return 1; // 返回中间节点的监视状态
        }

        // 左右节点至少有一个摄像头
        if (left == 1 || right == 1) {
            // 此时中间节点应该为被覆盖状态
            return 2;
        }

        return -1;
    } 

    int minCameraCover(TreeNode* root) {
        count = 0;

        // 递归结束之后需要判断根节点的状态
        if (traverse(root) == 0) count++;

        return count;
    }
};
// @lc code=end

