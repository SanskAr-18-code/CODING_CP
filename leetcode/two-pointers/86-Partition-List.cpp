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
        queue<ListNode*> q;
        ListNode* cur = head;
        ListNode* prev = nullptr;

        while (cur) {
            ListNode* nxt = cur->next;
            if (cur->val < x) {
                if (cur == head) {
                    head = nxt;
                }
                q.push(cur);
                cur->next = nullptr;
                if (prev)
                    prev->next = nxt;
            } else {
                prev = cur;
            }
            cur = nxt;
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!q.empty()) {
            tail->next = q.front();
            tail = tail->next;
            q.pop();
        }

        tail->next = head;
        return dummy.next;
    }
};