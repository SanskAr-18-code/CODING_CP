/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* build(vector<int>& postorder, int ps, int pe,
                    vector<int>& inorder, int is, int ie,
                    unordered_map<int, int>& mp) {
        if (ps > pe || is > ie) {
            return nullptr;
        }
        TreeNode* node = new TreeNode(postorder[pe]);
        int idx = mp[node->val];
        node->left =
            build(postorder, ps, ps + (idx - is) - 1, inorder, is, idx - 1,mp);
        node->right =
            build(postorder, ps + (idx - is), pe - 1, inorder, idx + 1, ie,mp);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        int n=postorder.size();
        TreeNode* root=build(postorder,0,n-1,inorder,0,n-1,mp);
        return root;
    }
};