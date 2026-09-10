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
    unordered_map<TreeNode*,int> mpsum;
    unordered_map<TreeNode*,int> mplen;
    int sum(TreeNode* root){
        if(!root) return 0;
        int left=sum(root->left);
        int right=sum(root->right);
        return mpsum[root]=root->val+left+right;
    }
    int length(TreeNode* root){
        if(!root) return 0;
        int left=length(root->left);
        int right=length(root->right);

        return mplen[root]=1+left+right;        
    }
    int ans=0;
    void traversal(TreeNode* root){
        if(!root) return;

        if(root->val==(mpsum[root]/mplen[root])){
            ans++;
        }
        traversal(root->left);
        traversal(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;
        sum(root);
        length(root);
        traversal(root);
        return ans;
    }
};