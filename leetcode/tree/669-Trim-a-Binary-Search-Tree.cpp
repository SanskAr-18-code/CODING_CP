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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while (root) {
            if (root->val < low)
                root = root->right;
            else if (root->val > high)
                root = root->left;
            else
                break;
        }
        TreeNode* curr = root;

        while (curr) {
            while (curr->left && curr->left->val < low) {
                curr->left = curr->left->right;
            }
            curr = curr->left;
        }
        curr = root;

        while (curr) {
            while (curr->right && curr->right->val > high) {
                curr->right = curr->right->left;
            }
            curr = curr->right;
        }
        return root;
    }
};