/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void parent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &mp){
        if(!root) return ;
        if(root->left){
            mp[root->left]=root;
        }
        if(root->right){
            mp[root->right]=root;
        }
        parent(root->left,mp);
        parent(root->right,mp);
    }
    TreeNode* node;
    void pos(TreeNode* root,int &start){
        if(!root) return ;
        if(root->val==start){
            node=root;
            return;
        }
        pos(root->left,start);
        pos(root->right,start);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> mp;
        parent(root,mp);
        node=nullptr;
        pos(root,start);
        unordered_map<TreeNode*,bool> vis;
        queue<TreeNode*> q;
        q.push(node);
        vis[node]=true;
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0; i<n; i++){
                auto it=q.front();
                q.pop();
                if(it->left && !vis[it->left]){
                    q.push(it->left);
                    vis[it->left]=true;
                }
                if(it->right && !vis[it->right]){
                    q.push(it->right);
                    vis[it->right]=true;
                }
                if(mp[it] && !vis[mp[it]]){
                    q.push(mp[it]);
                    vis[mp[it]]=true;
                }
            }
            ans++;
        }
        return ans-1;
    }
};