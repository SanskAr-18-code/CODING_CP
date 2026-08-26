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
    void inorder(TreeNode* root,vector<TreeNode*> &nodes){
        if (!root)  return;
        inorder(root->left,nodes);
        nodes.push_back(root);
        inorder(root->right,nodes);
    }
    TreeNode* build(vector<TreeNode*> &arr,int low,int high){
        if(low>high){
            return nullptr;
        }
        int mid=low+(high-low)/2;
        TreeNode* temp=arr[mid];
        temp->left=build(arr,low,mid-1);
        temp->right=build(arr,mid+1,high);
        return temp;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if(!root) return root;
        vector<TreeNode*> nodes;
        inorder(root,nodes);
        TreeNode* newroot=build(nodes,0,nodes.size()-1);
        return newroot;
    }
};