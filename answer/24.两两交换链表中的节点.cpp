/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;

        ListNode *vhead = new ListNode(-1, head);
        ListNode *pre = vhead;
        ListNode *cur = head;
        ListNode *back = cur->next;

        while (back) {
            // 首先连接back
            pre->next = back;
            cur->next = back->next;
            back->next = cur;

            // 更新
            if (cur->next != nullptr) {
                pre = cur;
                cur = cur->next;
                back = cur->next;
            } else break;

        }

        ListNode *temp = vhead;
        vhead = temp->next;
        delete temp;
        
        return vhead;
    }
};
// @lc code=end

