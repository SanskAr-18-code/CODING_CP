#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int profit(int idx, bool canbuy, vector<int> &arr, vector<vector<int>> &dp, int &fee)
    {
        if (idx == arr.size())
            return 0;
    if(dp[idx][canbuy]!=-1) return dp[idx][canbuy];
        if (canbuy)
        {
            int pick = -arr[idx] + profit(idx + 1, false, arr, dp, fee);
            int notpick = profit(idx + 1, true, arr, dp, fee);
            return dp[idx][canbuy] = max(pick, notpick);
        }
        else
        {
            int pick = arr[idx] - fee + profit(idx + 1, true, arr, dp, fee);
            int notpick = profit(idx + 1, false, arr, dp, fee);
            return dp[idx][canbuy] = max(pick, notpick);
        }
    }
    int maxProfit(vector<int> &arr, int fee)
    {
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return profit(0,true,arr,dp,fee);
    }
};