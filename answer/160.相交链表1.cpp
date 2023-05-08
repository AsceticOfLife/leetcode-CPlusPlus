/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        
        // 首先找到A的尾结点
        ListNode *end = headA;
        while (end->next) end = end->next;

        // 将A链表的结尾连接到B链表的头结点
        end->next = headB;

        // 接着判断是否存在循环
        // 如果不存在相交结点就不会出现循环
        ListNode *slow, *fast;
        slow = fast = headA;
        while (fast->next && fast->next->next) {
            // 慢指针移动
            slow = slow->next;
            // 快指针移动
            fast = fast->next->next;

            if (slow == fast) {
                // 第一次相遇
                // 寻找环的起点
                slow = headA;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                end->next = nullptr;
                return slow;
            }
            
        } 

        end->next = nullptr;
        return nullptr;
    }
};
// @lc code=end

