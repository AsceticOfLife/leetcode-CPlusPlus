/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode *traversal(vector<int> &nums, int low, int high) {
        if (high == low) return nullptr;

        int mid = low + (high - low) / 2;
        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = traversal(nums, low, mid);
        cur->right = traversal(nums, mid + 1, high);

        return cur;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};
// @lc code=end

