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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> st;
        ListNode* temp;
        vector<ListNode*> vec;
        while (head) {
            temp = head;
            st.push(head);
            head = head->next;
            temp->next = nullptr;
            if (st.size() == k) {
                while (!st.empty()) {
                    auto it = st.top();
                    vec.push_back(it);
                    st.pop();
                }
            }
        }
        stack<ListNode*> nst;
        while (!st.empty()) {
            auto it = st.top();
            nst.push(it);
            st.pop();
        }
        while (!nst.empty()) {
                    auto it = nst.top();
                    vec.push_back(it);
                    nst.pop();
                }

        if (vec.empty())
            return nullptr;

        for (int i = 1; i < vec.size(); i++) {
            vec[i - 1]->next = vec[i];
        }
        vec[vec.size() - 1]->next = nullptr;
        return vec[0];
    }
};