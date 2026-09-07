/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    void parent(Node* root, unordered_map<Node*,Node*> &mp){
        if(!root) return;
        if(root->left) mp[root->left]=root;
        if(root->right) mp[root->right]=root;
        parent(root->left,mp);
        parent(root->right,mp);
    }
    Node* node;
    void pos(Node* root,int target){
        if(!root) return;
        if(root->data==target){
            node=root;
            return;
        }
        pos(root->left,target);
        pos(root->right,target);
    }
    int minTime(Node* root, int target) {
        if(!root) return 0;
        
        unordered_map<Node*,Node*> mp;
        unordered_map<Node*,bool> vis;
        parent(root,mp);
        
        node=nullptr;
        pos(root,target);
        
        queue<Node*> q;
        q.push(node);
        vis[node] = true;
        int ans=0;
        
        while(!q.empty()){
            int n=q.size();
            bool flag=false;
            for(int i=0; i<n; i++){
                auto it=q.front();
                q.pop();
                
                if(it->left && !vis[it->left]){
                    flag=true;
                    q.push(it->left);
                    vis[it->left]=true;
                }
                if(it->right && !vis[it->right]){
                    flag=true;
                    q.push(it->right);
                    vis[it->right]=true;
                }
                if(mp[it] && !vis[mp[it]]){
                    flag=true;
                    q.push(mp[it]);
                    vis[mp[it]]=true;
                }
            }
            if(flag) ans++;
        }
        return ans;
    }
};