class Solution {
    int mn = INT_MAX;
    TreeNode* prev = nullptr;

public:
    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);

        if(prev)
            mn = min(mn, root->val - prev->val);
        prev = root;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return mn;
    }
};