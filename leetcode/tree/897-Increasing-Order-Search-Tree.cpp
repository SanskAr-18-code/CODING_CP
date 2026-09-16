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
    void inorder(TreeNode* root,queue<TreeNode*>& q){
        if(!root) return ;
        inorder(root->left,q);
        q.push(root);
        inorder(root->right,q);
    }
    TreeNode* increasingBST(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root) return root;
        inorder(root,q);
        root=q.front();
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(!q.empty()) it->right=q.front();
            else{
                it->right=nullptr;
            }
            it->left=nullptr;
        }
        return root;
    }
   
};