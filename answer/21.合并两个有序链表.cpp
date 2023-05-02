/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start

// * Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode *res = nullptr;

        (list1->val <= list2->val) ? (res = list1, list1 = list1->next) :
                                     (res = list2, list2 = list2->next);
        ListNode *rear = res;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                rear->next = list1;
                rear = list1;
                list1 = list1->next;
            } else {
                rear->next = list2;
                rear = list2;
                list2 = list2->next;
            }
        }

        if (list1 != nullptr) 
            rear->next = list1;

        if (list2 != nullptr) 
            rear->next = list2;

        return res;
    }
};
// @lc code=end

