class Solution {
public:
    long long cnt = 0;
    long long prefix = 0;

    unordered_map<long long,long long> mp;
    void dfs(TreeNode* root, long long target)
    {
        if(root == nullptr)
            return;
        prefix += root->val;
        cnt += mp[prefix - target];
        mp[prefix]++;

        dfs(root->left, target);
        dfs(root->right, target);
        mp[prefix]--;
        prefix -= root->val;
    }

    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        dfs(root, targetSum);

        return cnt;
    }
};