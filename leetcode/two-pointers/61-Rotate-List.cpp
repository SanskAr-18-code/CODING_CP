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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        if(!head->next){
            return head;
        }
        int n=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            n++;
        }
        k=k%n;
        while(head && k--){
            ListNode* ptr=head;
            while(ptr->next->next){
                ptr=ptr->next;
            }
            ptr->next->next=head;
            head=ptr->next;
            ptr->next=nullptr;
        }
        return head;
    }
};