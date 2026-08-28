#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int profit(int idx, bool canbuy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (idx >= prices.size())
            return 0;
        if (dp[idx][canbuy] != -1)
            return dp[idx][canbuy];
        if (canbuy)
        {
            int pick = -prices[idx] + profit(idx + 1, false, prices, dp);
            int notpick = profit(idx + 1, true, prices, dp);
            return dp[idx][canbuy] = max(pick, notpick);
        }
        else
        {
            int pick = prices[idx] + profit(idx + 2, true, prices, dp);
            int notpick = profit(idx + 1, false, prices, dp);
            return dp[idx][canbuy] = max(pick, notpick);
        }
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        // return profit(0, true, prices, dp);
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                int pick=0;
                int notpick=0;
                if(buy){
                    pick=-prices[i]+dp[i+1][false];
                    notpick=dp[i+1][true];
                }
                else{
                    pick=prices[i]+dp[i+2][true];
                    notpick=dp[i+1][false];
                }
                dp[i][buy]=max(pick,notpick);
            }
        }
        return dp[0][1];
    }
};