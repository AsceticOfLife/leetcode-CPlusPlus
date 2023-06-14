/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode *buildCore(const vector<int> &nums, int start, int end) {
        if ((end - start) == 0) return nullptr;
        if ((end - start) == 1) return new TreeNode(nums[start]);

        // 寻找数组中的最大值的索引
        int max_index = start;
        int max_num = nums[start];
        for (int i = start + 1; i < end; ++i) {
            if (nums[i] > max_num) {
                max_num = nums[i];
                max_index = i;
            }
        }

        // 创建根节点
        TreeNode *cur = new TreeNode(max_num);

        // 左子树向量表
        cur->left = buildCore(nums, start, max_index);

        // 右子树向量表
        cur->right = buildCore(nums, max_index + 1, end);

        return cur;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildCore(nums, 0, nums.size());
    }
};
// @lc code=end

