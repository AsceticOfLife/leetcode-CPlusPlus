/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 创建一个头结点
        ListNode *vhead = new ListNode(-1, head);

        ListNode *s = head;     // 当前结点
        ListNode *pre = vhead;  // 前一个结点
        // 遍历链表
        while (s) {
            // 判断当前结点的值是否为目标值
            if (s->val == val) {
                pre->next = s->next; // 断开s的连接
                delete s; // 删除当前节点
                s = pre->next; // s后移，pre不动
            } else {
                pre = s;    // pre指向s
                s = s->next;    // s指向下一个
            }
        }

        // 删除头结点
        ListNode *temp = vhead;
        vhead = temp->next;
        delete temp;

        return vhead;
    }
};
// @lc code=end

