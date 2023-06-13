/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode * buildCore(const vector<int> &preorder, const vector<int> &inorder) {
        int pre_size = preorder.size();
        int in_size = inorder.size();
        if (pre_size == 0 && in_size == 0) return nullptr;
        if (pre_size == 1 && in_size == 1) {
            TreeNode *cur = new TreeNode(preorder[0]);

            return cur;
        }

        // 根据前序遍历找到根节点
        int val = preorder[0];
        TreeNode *cur = new TreeNode(val);

        // 找到中序遍历中根节点的索引
        int index;
        for (index = 0; val != inorder[index]; ++index)
            ;
        
        // 确定左子树的中序遍历列表
        vector<int> sub_inorder(inorder.begin(), inorder.begin() + index);
        // 缺点左子树的前序遍历列表
        vector<int> sub_preorder(preorder.begin() + 1, preorder.begin() + 1 + index);

        // 重构左子树
        cur->left = buildCore(sub_preorder, sub_inorder);

        // 确定右子树的中序遍历列表
        sub_inorder = vector<int>(inorder.begin() + index + 1, inorder.end());
        // 确定右子树的前序遍历列表
        sub_preorder = vector<int>(preorder.begin() + 1 + index, preorder.end());

        // 重构右子树
        cur->right = buildCore(sub_preorder, sub_inorder);

        return cur;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildCore(preorder, inorder);
    }
};
// @lc code=end

