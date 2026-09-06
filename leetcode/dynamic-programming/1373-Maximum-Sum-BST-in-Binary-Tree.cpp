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
    struct info {
        bool isBST;
        int mn;
        int mx;
        long long sum;
    };
    long long ans = INT_MIN;
    info dfs(TreeNode* root) {
        if (!root) {
            return {true, INT_MAX, INT_MIN, 0};
        }
        info left = dfs(root->left);
        info right = dfs(root->right);

        if (left.isBST && right.isBST && left.mx < root->val &&
            right.mn > root->val) {
            long long cursum = root->val + left.sum + right.sum;
            ans = max(ans, cursum);
            return {true, min(left.mn, root->val), max(root->val, right.mx),
                    cursum};
        }
        return {false, INT_MIN, INT_MAX, 0};
    }
    int maxSumBST(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};