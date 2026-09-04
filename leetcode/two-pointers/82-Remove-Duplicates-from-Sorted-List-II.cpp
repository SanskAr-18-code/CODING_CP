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
        ListNode* cur=head;
        ListNode* prev=nullptr;
        while(cur){
            if(!cur->next) break;
            if(cur->next && cur->next->val!=cur->val) prev=cur;
            ListNode* nextnode=cur;
            while(nextnode && nextnode->val==cur->val){
                nextnode=nextnode->next;
            }
            if(!prev) head=nextnode;
            if(prev) prev->next=nextnode;
            cur=nextnode;
        }
        return head;
    }
};