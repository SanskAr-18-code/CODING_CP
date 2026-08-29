class Solution {
    int sum = 0;

    void dfs(TreeNode* root, vector<int> cur) {
        if (!root) return;

        cur.push_back(root->val);

        if (!root->left && !root->right) {
            long long n = 1;
            int num = 0;

            for (int i = cur.size() - 1; i >= 0; i--) {
                num += cur[i] * n;
                n *= 10;
            }
            sum += num;
            return;
        }
        dfs(root->left, cur);
        dfs(root->right, cur);
    }

public:
    int sumNumbers(TreeNode* root) {
        dfs(root, {});
        return sum;
    }
};