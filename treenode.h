/*
 * @Author: Guomw
 * @Date: 2023-06-17 19:35:44
 * @LastEditors: Guomw  isguo_mw@163.com
 * @LastEditTime: 2023-06-17 19:37:08
 * @Description: leetcode 树的定义
 */
#ifndef TREENODE_H_
#define TREENODE_H_

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



#endif

