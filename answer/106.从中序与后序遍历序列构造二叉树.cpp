/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    // 采用递归地方式重构二叉树
    TreeNode *buildCore(const vector<int> &inorder, const vector<int> &postorder) {
        // 如果中序遍历和后序遍历都为空
        if (inorder.size() == 0 && postorder.size() == 0) return nullptr;
        if (inorder.size() == 1 && postorder.size() == 1) {
            TreeNode *cur = new TreeNode(inorder[0]);
            
            return cur;
        }

        // 根据后序遍历找到根节点
        int last = postorder.size() - 1;
        int val = postorder[last];

        // 创建根节点
        TreeNode *cur = new TreeNode(val);

        // 在中序遍历中以val为根节点划分左右子树
        // 每一个子树有自己的中序遍历和前序遍历列表
        vector<int> sub_inorder, sub_postorder;
        int i;
        // 左子树前序遍历列表和后序遍历列表
        for (i = 0; val != inorder[i]; ++i) {
            sub_inorder.push_back(inorder[i]);
            sub_postorder.push_back(postorder[i]);
        }

        // 递归生成左子树
        cur->left = buildCore(sub_inorder, sub_postorder);

        // 右子树中序遍历和后序遍历列表
        int j = i;
        i++;
        sub_inorder.clear();
        sub_postorder.clear();
        for (; i < inorder.size(); ++i, ++j) {
            sub_inorder.push_back(inorder[i]);
            sub_postorder.push_back(postorder[j]);
        }
        
        // 递归生成右子树
        cur->right = buildCore(sub_inorder, sub_postorder);    

        return cur;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildCore(inorder, postorder);
    }
};
// @lc code=end

