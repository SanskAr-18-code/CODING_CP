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
    int diff = INT_MAX;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (!root)
            return;
        inorder(root->left);
        if (prev) {
            diff = min(diff, root->val - prev->val);
        }
        prev = root;
        inorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        inorder(root);
        return diff;
    }
};