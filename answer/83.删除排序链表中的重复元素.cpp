/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode *slow, *fast;
        slow = head;
        fast = head->next;
        while (fast) {
            if (fast->val == slow->val) {
                slow->next = fast->next;
                delete fast;
                fast = slow->next;
            } else {
                slow = slow->next;
                fast = fast->next;
            }
        }

        return head;
    }
};
// @lc code=end

