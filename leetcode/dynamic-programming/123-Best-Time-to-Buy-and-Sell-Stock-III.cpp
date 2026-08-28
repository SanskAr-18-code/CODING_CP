#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int profit(int idx, bool canbuy, int trans, vector<int> &prices,
    vector<vector<vector<int>>> &dp)
    {
        if (idx == prices.size())
            return 0;
        if (trans == 2)
            return 0;
        if(dp[idx][canbuy][trans]!=-1) return dp[idx][canbuy][trans];
        if (canbuy)
        {
            int pick = -prices[idx] + profit(idx + 1, false, trans, prices,dp);
            int notpick = profit(idx + 1, true, trans, prices,dp);
            return dp[idx][canbuy][trans]=max(pick, notpick);
        }
        else
        {
            int pick = prices[idx] + profit(idx + 1, true, trans+1, prices,dp);
            int notpick = profit(idx + 1, false, trans, prices,dp);
            return dp[idx][canbuy][trans]=max(pick, notpick);
        }
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int> (3,-1)));
        return profit(0,true,0,prices,dp);
    }
};