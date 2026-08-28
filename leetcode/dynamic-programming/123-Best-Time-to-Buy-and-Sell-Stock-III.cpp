class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int> (3,0)));
        // return profit(0,true,0,prices);
        //Tabulation
        for (int idx=n-1; idx>=0 ; idx--){
            for(int buy=0; buy<=1; buy++){
                for(int trans=1; trans<=2; trans++){
                    if(buy==1){
                        int pick=-prices[idx]+dp[idx+1][false][trans];
                        int notpick=dp[idx+1][true][trans];
                        dp[idx][buy][trans]=max(pick,notpick);
                    }
                    else{
                        int pick=prices[idx]+dp[idx+1][true][trans-1];
                        int notpick=dp[idx+1][false][trans];
                        dp[idx][buy][trans]=max(pick,notpick);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};