class Solution {
private:
    int profit(int idx,bool canbuy,vector<int> &prices,vector<vector<int>> &dp){
        if(idx==prices.size()) return 0;
        if(dp[idx][canbuy]!=-1) return dp[idx][canbuy];
        if(canbuy){
            return dp[idx][canbuy]=max(-prices[idx]+profit(idx+1,false,prices,dp),profit(idx+1,true,prices,dp));
        }
        else{
            return dp[idx][canbuy]=max(prices[idx],profit(idx+1,false,prices,dp));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return profit(0,true,prices,dp);
    }
};