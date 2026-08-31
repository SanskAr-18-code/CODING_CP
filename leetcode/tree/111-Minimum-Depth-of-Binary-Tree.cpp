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
        return (root->right==nullptr && root->left==nullptr);
    }
    int maxlen=INT_MAX;
    void dfs(TreeNode* root,int len){
        if(!root) return;
        if(isleaf(root)){
            maxlen=min(maxlen,len);
            return;
        }
        dfs(root->left,len+1);
        dfs(root->right,len+1); 
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        dfs(root,1);
        return maxlen;
    }
};