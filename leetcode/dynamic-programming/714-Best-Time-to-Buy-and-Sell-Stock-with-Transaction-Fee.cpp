#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int profit(int idx, bool canbuy, vector<int> &arr, vector<vector<int>> &dp, int &fee)
    {
        if (idx == arr.size())
            return 0;

        if (canbuy)
        {
            int pick = -arr[idx] + profit(idx + 1, false, arr, dp, fee);
            int notpick = profit(idx + 1, true, arr, dp, fee);
            return dp[idx][canbuy] = max(pick, notpick);
        }
        else
        {
            int pick = arr[idx] - fee + profit(idx + 2, true, arr, dp, fee);
            int notpick = profit(idx + 1, false, arr, dp, fee);
            return dp[idx][canbuy] = max(pick, notpick);
        }
    }
    int maxProfit(vector<int> &arr, int fee)
    {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        // return profit(0,true,arr,dp,fee);
        //Tabulation
        for(int i=n-1; i>=0 ; i--){
            for(int k=0; k<=1; k++){
                if(k){
                    int pick=-arr[i]+dp[i+1][false];
                    int notpick=dp[i+1][true];
                    dp[i][k]=max(pick,notpick);
                }
                else{
                    int pick=arr[i]-fee+dp[i+1][true];
                    int notpick=dp[i+1][false];
                    dp[i][k]=max(pick,notpick);
                }
            }
        }
        return dp[0][true];
    }
};