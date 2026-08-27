class Solution {
private:
    int profit(int idx, vector<int>& arr, bool canbuy,vector<vector<int>>& dp) {
        if (idx == arr.size())
            return 0;
        if (dp[idx][canbuy] != -1)
            return dp[idx][canbuy];
        if (canbuy) {
            int take = -arr[idx] + profit(idx + 1, arr, false, dp);
            int nottake = profit(idx + 1, arr, true, dp);
            return dp[idx][canbuy] = max(take, nottake);
        } else {
            int take = arr[idx] + profit(idx + 1, arr, true, dp);
            int nottake = profit(idx + 1, arr, false, dp);
            return dp[idx][canbuy] = max(take, nottake);
        }
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return profit(0, prices, true, dp);
    }
};