class Solution {
public:
    int len(int idx, vector<int>& nums, int pre, vector<vector<int>>& dp) {
        if (idx == nums.size())
            return 0;
        if (dp[idx][pre] != -1)
            return dp[idx][pre];
        if (idx == pre || nums[idx] <= nums[pre]) {
            return dp[idx][pre] = len(idx + 1, nums, pre, dp);
        } else {
            int nottake = len(idx + 1, nums, pre, dp);
            int take = 1 + len(idx + 1, nums, idx, dp);
            return dp[idx][pre] = max(take, nottake);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 1;
        vector<vector<int>> dp(n + 1, vector<int>(n, 0));
        // for(int i=0; i<n ; i++){
        //     maxlen=max(maxlen,1+len(i,nums,i,dp));
        // }
        // Tabulation
        for (int i = n - 1; i >= 0; i--) {
            for (int k = i; k >= 0; k--) {
                if (i == k || nums[i] <= nums[k]) {
                    dp[i][k] = dp[i + 1][k];
                } else {
                    int nottake = dp[i + 1][k];
                    int take = 1 + dp[i + 1][i];
                    dp[i][k] = max(nottake, take);
                }
            }
        }
        int ans = 1;
        for (int i = 0; i < n; i++) {
            ans = max(ans, 1 + dp[i][i]);
        }
        return ans;
    }
};