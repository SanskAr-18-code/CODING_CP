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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root) return root;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=1; i<=n; i++){
                auto it=q.front();
                q.pop();
                TreeNode* temp=it->left;
                it->left=it->right;
                it->right=temp;
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
              } 
        }
        return root;
    } 
};