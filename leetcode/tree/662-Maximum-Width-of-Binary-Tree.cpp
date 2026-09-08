class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;

        int ans = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int n = q.size();
            long long minIndex = q.front().second;
            long long first, last;

            for (int i = 0; i < n; i++) {
                long long cur = q.front().second - minIndex;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0)
                    first = cur;
                if (i == n - 1)
                    last = cur;
                if (node->left) {
                    q.push({node->left, cur * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, cur * 2 + 2});
                }
            }
            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
    }
};