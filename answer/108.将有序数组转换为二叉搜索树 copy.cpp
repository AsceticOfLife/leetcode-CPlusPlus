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
    // 迭代法
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;

        TreeNode *temp = new TreeNode(0);
        queue<TreeNode *> nodeQue;
        queue<int> left;
        queue<int> right;

        nodeQue.push(temp);
        left.push(0);
        right.push(nums.size());
        
        while (!nodeQue.empty()) {
            TreeNode *cur = nodeQue.front();
            nodeQue.pop();
            int low = left.front(); left.pop();
            int high = right.front(); right.pop();

            // 更新当前根节点的值
            int mid = low + (high - low) / 2;
            cur->val = nums[mid];

            if (low < mid) {
                cur->left = new TreeNode;
                nodeQue.push(cur->left);
                left.push(low);
                right.push(mid);
            }

            if (high > mid + 1) {
                cur->right = new TreeNode;
                nodeQue.push(cur->right);
                left.push(mid + 1);
                right.push(high);
            }
        }

        return temp;
    }
};
// @lc code=end

