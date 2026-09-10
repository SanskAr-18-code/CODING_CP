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
    int path(TreeNode* root, TreeNode* temp) {
        if (!root)
            return 0;
        if (root->val != temp->val) {
            return 0;
        }
        int left = path(root -> left, temp);
        int right = path(root->right, temp);
        if (root == temp) {
            return 1 + left + right;
        }
        return 1 + max(left, right);
    }
    int ans = 1;
    void res(TreeNode* root) {
        if (!root)
            return;
        ans = max(ans, path(root, root));
        res(root->left);
        res(root->right);
        return;
    }
    int longestUnivaluePath(TreeNode* root) {
        if (!root)
            return 0;;
        res(root);
        return ans-1;
    }
};