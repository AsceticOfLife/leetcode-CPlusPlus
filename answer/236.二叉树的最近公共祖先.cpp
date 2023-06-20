/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int last_depth;
    TreeNode *last_grandp;
    TreeNode *p;
    TreeNode *q;

    // 寻找当前子树中是否出现目标结点
    bool findChildren(TreeNode *cur, TreeNode *target) {
        if (cur == nullptr) return false;

        if (cur == target) return true;

        if (findChildren(cur->left, target)) return true;
        if (findChildren(cur->right, target)) return true;
        
        return false;
    }

    // 采用递归法遍历
    void treaversal(TreeNode *cur, int depth) {
        if (cur == nullptr) return;

        // 首选处理当前根节点
        bool left_flag = findChildren(cur, p);
        bool right_flag = findChildren(cur, q);
        if (left_flag && right_flag) {
            if (last_grandp == nullptr) {
                last_depth = depth;
                last_grandp = cur;
            } else {
                if (depth > last_depth) {
                    last_grandp = cur;
                    last_depth = depth;
                }
            } // end if last_grandp is nullptr
        } // end if flags are true

        // 如果当前结点就是其中一个结点，那么不用再向下遍历
        if (cur == p || cur == q) return;
        // 遍历左子树
        treaversal(cur->left, depth + 1);
        // 遍历右子树
        treaversal(cur->right, depth + 1);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 初始化
        last_depth = 0;
        last_grandp = nullptr;
        this->p = p;
        this->q = q;

        treaversal(root, 1);

        return last_grandp;
    }
};
// @lc code=end

