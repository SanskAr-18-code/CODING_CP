class Solution {
public:
    int sum = INT_MIN;

    int path(TreeNode* root) {
        if(!root) return 0;

        int ls = max(0, path(root->left));
        int rs = max(0, path(root->right));

        sum = max(sum, root->val + ls + rs);

        return root->val + max(ls, rs);
    }

    int maxPathSum(TreeNode* root) {
        path(root);
        return sum;
    }
};