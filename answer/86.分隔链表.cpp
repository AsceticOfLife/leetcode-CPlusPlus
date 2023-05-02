/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head;

        ListNode *front_nodes = new ListNode(10);
        ListNode *tail_nodes = new ListNode(12);
        ListNode *p1 = front_nodes;
        ListNode *p2 = tail_nodes;

        ListNode *p = head;
        while (p) {
            if (p->val < x) {
                p1->next = p;
                p1 = p;
            } else {
                p2->next = p;
                p2 = p;
            }
            ListNode *t = p->next;
            p->next = nullptr;
            p = t;
        }
        p1->next = tail_nodes->next;

        ListNode *temp = front_nodes;
        front_nodes = front_nodes->next;
        delete temp;
        delete tail_nodes;

        return front_nodes;
    }
};
// @lc code=end

