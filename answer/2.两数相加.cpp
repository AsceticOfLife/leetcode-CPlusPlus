/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;

        ListNode *res = nullptr;
        ListNode *rear = res;
        int flag = 0; // 表示进位
        int temp;
        while (p1 || p2) {
            if (p1 != nullptr && p2 != nullptr) {
                temp = p1->val + p2->val + flag;
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1 != nullptr && p2 == nullptr) {
                temp = p1->val + flag;
                p1 = p1->next;
            } else if (p1 == nullptr && p2 != nullptr) {
                temp = p2->val + flag;
                p2 = p2->next;
            }
                
            // 调整进位
            if (temp >= 10) flag = 1;
            else flag = 0;

            // 创建新节点
            ListNode *t = new ListNode(temp % 10);

            if (res == nullptr) {
                res = t;
                rear = res;
            } else {
                rear->next = t;
                rear = t;
            }

        }
        // 判断最后是否存在进位
        if (flag == 1) {
            ListNode *t = new ListNode(flag);
            rear->next = t;
            rear = t;
        }

        return res;
    }
};
// @lc code=end

