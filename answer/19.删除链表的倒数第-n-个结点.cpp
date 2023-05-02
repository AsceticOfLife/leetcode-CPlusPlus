/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;

        ListNode *vhead = new ListNode(-1, head);
        ListNode *p1 = vhead;
        for (int i = 0; i < n + 1; i++) p1 = p1->next;

        

        ListNode *p2 = vhead;
        while (p1 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }

        // 删除p2后面的结点
        ListNode *p3 = p2->next;
        p2->next = p3->next;
        delete p3;
        
        ListNode *t = vhead;
        vhead = vhead->next;
        delete t;

        return vhead;
    }
};
// @lc code=end

