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
    void inorder(TreeNode* root, vector<TreeNode*>& a, vector<int>& b) {
        if (!root)
            return;
        inorder(root->left, a, b);
        a.push_back(root);
        b.push_back(root->val);
        inorder(root->right, a, b);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> b;
        vector<TreeNode*> a;
        if(!root) return root;
        inorder(root, a, b);
        vector<int> suf(a.size());
        suf[a.size()-1]=b[a.size()-1];
        for (int i = a.size() - 2; i >= 0; i--) {
            suf[i] = b[i]+suf[i+1];
        }
        for (int i = 0; i < a.size(); i++) {
            a[i]->val = suf[i];
        }
        return root;
    }
};