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
    int maxdepth(TreeNode* root){
        if(!root) return 0;

        int left=maxdepth(root->left);
        int right=maxdepth(root->right);
        return 1+max(left,right);
    }
    void traversal(TreeNode* root,int &dia){
        if(!root) return ;
        int left=maxdepth(root->left);
        int right=maxdepth(root->right);
        int cur=left+right;
        dia=max(dia,cur);
        traversal(root->left,dia);
        traversal(root->right,dia);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=INT_MIN;
        traversal(root,dia);
        return dia;
    }
};