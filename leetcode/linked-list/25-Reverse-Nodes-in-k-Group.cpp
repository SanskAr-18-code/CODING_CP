class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* cur = head;
        ListNode* prev = nullptr;

        int cnt = 0;
        ListNode* tail = nullptr;

        while (cur) {
            ListNode* check = cur;
            int nodes = 0;
            while (check && nodes < k) {
                check = check->next;
                nodes++;
            }
            if (nodes < k) {
                if (tail)
                    tail->next = cur;
                break;
            }
            int t = k;
            ListNode* listtail = cur;
            prev = nullptr;

            while (cur && t--) {
                ListNode* nextnode = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nextnode;
            }
            if (cnt == 0) {
                head = prev;
                cnt++;
            }
            if (tail)
                tail->next = prev;

            tail = listtail;
            tail->next = cur;
        }

        return head;
    }
};