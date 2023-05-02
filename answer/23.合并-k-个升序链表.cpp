/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    struct mygreater {
        bool operator()(ListNode *a, ListNode *b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if (k == 0) return nullptr;

        ListNode *res = new ListNode;
        ListNode *p = res;
        // 创建优先级队列
        priority_queue<ListNode *, vector<ListNode *>, mygreater> pq;
        // 将k个链表的头结点插入优先级队列
        for (auto head : lists) {
            if (head != nullptr) pq.push(head);
        }

        while (!pq.empty()) {
            // 获取最小结点
            ListNode *temp = pq.top();
            p->next = temp;
            pq.pop();

            if (temp->next != nullptr) pq.push(temp->next);
            
            p = p->next;
        }

        ListNode *d = res;
        res = res->next;
        delete d;

        return res;
    }

};
// @lc code=end

