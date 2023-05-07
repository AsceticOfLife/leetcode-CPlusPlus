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
        // p1先走n+1步，到达n+1，从虚拟结点开始，就当从0开始
        for (int i = 0; i < n + 1; i++) p1 = p1->next;

        // 接着p2随着p1一起走
        // 最终到达的位置为len-n
        // 倒数第n个结点是len-n+1
        // 所以p2指向被删除节点的前一个结点
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

