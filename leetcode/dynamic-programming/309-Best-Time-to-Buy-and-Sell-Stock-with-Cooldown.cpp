#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int profit(int idx,bool canbuy,vector<int> &prices,vector<vector<int>> &dp){
        if(idx>=prices.size()) return 0;
        if(dp[idx][canbuy]!=-1) return dp[idx][canbuy];
        if(canbuy){
            int pick=-prices[idx]+profit(idx+1,false,prices,dp);
            int notpick=profit(idx+1,true,prices,dp);
            return dp[idx][canbuy]=max(pick,notpick);
        }
        else{
            int pick=prices[idx]+profit(idx+2,true,prices,dp);
            int notpick=profit(idx+1,false,prices,dp);
            return dp[idx][canbuy]=max(pick,notpick);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));        
        return profit(0,true,prices,dp);
    }
};