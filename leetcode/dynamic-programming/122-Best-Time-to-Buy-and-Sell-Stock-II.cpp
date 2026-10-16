class Solution {
public:
    int f(vector<int> &prices,int i,bool canbuy,vector<vector<int>> &dp){
        if(i>=prices.size()) return 0;

        if(dp[i][canbuy]!=-1) return dp[i][canbuy];
        if(canbuy){
            int take=-prices[i]+f(prices,i+1,!canbuy,dp);
            int nottake=f(prices,i+1,canbuy,dp);
            
            return dp[i][canbuy]= max(take,nottake);
        }
        else{
            int take=prices[i]+f(prices,i+1,!canbuy,dp);
            int nottake=f(prices,i+1,canbuy,dp);

            return dp[i][canbuy]= max(take,nottake);
        }

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));

        return f(prices,0,true,dp);
    }
};