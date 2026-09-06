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
    TreeNode* rightmost(TreeNode* root) {
        if (!root->right)
            return root;
        return rightmost(root->right);
    }
    TreeNode* node = nullptr;
    void find(TreeNode* root, int& key) {
        if (!root)
            return;
        if (root->val == key) {
            node = root;
        }
        find(root->left, key);
        find(root->right, key);
    }
    void del(TreeNode* root, TreeNode* node) {
        if (!root)
            return;

        if (root->left == node) {

            if (node->left == nullptr) {
                root->left = node->right;
            } else {
                root->left = node->left;
                TreeNode* rmst = rightmost(node->left);
                rmst->right = node->right;
            }
            return;
        }
        if (root->right == node) {

            if (node->left == nullptr) {
                root->right = node->right;
            } else {
                root->right = node->left;
                TreeNode* rmst = rightmost(node->left);
                rmst->right = node->right;
            }
            return;
        }
        del(root->left, node);
        del(root->right, node);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return root;
        if (root->val == key) {
            if (!root->left) {
                return root->right;
            }
            TreeNode* rmst = rightmost(root->left);
            rmst->right = root->right;
            return root->left;
        }
        find(root, key);
        if (!node)
            return root;
        del(root, node);
        return root;
    }
};