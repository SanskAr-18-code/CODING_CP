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
     int maxDepth(TreeNode* root) {

        if(root==NULL){
            return 0;
        }
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
        return 1+(max(lh,rh));
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        if(abs(maxDepth(root->left)-maxDepth(root->right))>=2){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};