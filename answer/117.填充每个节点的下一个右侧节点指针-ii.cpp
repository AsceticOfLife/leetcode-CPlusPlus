/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node *> que;

        if (root) que.push(root);

        while (!que.empty()) {
            int size = que.size();
            Node *oldNode = que.front();
            que.pop();
            // 将左右孩子入队
            if (oldNode->left) que.push(oldNode->left);
            if (oldNode->right) que.push(oldNode->right);

            for (int i = 1; i < size; ++i) {
                Node *newNode = que.front();
                que.pop();

                oldNode->next = newNode;

                oldNode = newNode;
                if (oldNode->left) que.push(oldNode->left);
                if (oldNode->right) que.push(oldNode->right);
            }

            oldNode->next = nullptr;

        }

        return root;
    }
};
// @lc code=end

