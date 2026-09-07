/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        if(!head) return 0;
        unordered_map<Node*,int> mp;
        Node* temp=head;
        while(temp){
            mp[temp]++;
            if(mp[temp]==3){
                // mp[temp]=2;
                break;
            }
            temp=temp->next;
        }
        int cnt=0;
        for(auto it: mp){
            if(it.second>=2){
                cnt++;
            }
        }
        return cnt;
    }
};