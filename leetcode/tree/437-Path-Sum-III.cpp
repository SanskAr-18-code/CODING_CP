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
    bool isleaf(TreeNode* root){
        return (root->left==nullptr && root->right==nullptr);
    }

    void paths(TreeNode* root,long long target,int &total){
        if(!root) return;
        target-=root->val;
        if(target==0) total+=1;
        if(isleaf(root)) return;
        paths(root->left,target,total);
        paths(root->right,target,total);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int total=0;
        queue<TreeNode*> q;
        if(!root) return 0;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=1 ; i<=n; i++){
                auto it=q.front();
                q.pop();
                int sum=0;
                paths(it,targetSum,sum);
                total+=sum;
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
        }
        return total;
    }
};