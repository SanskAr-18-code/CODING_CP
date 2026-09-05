/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // vector<vector<Node*>> vec;
        if(!root) return root;
        Node* cur=root;
        queue<Node*> q;
        q.push(cur);
        while(!q.empty()){
            int n=q.size();
            vector<Node*> nodes;
            for(int i=0; i<n; i++){
                auto it=q.front();
                q.pop();
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
                int k=nodes.size();
                if(k){
                    nodes[k-1]->next=it;
                }
                nodes.push_back(it);
            }
            nodes[nodes.size()-1]->next=nullptr;
        }
        return root;
    }
};