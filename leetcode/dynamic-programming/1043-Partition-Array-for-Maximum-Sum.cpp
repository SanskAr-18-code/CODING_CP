class Solution {
public:
    int helper(int i, int k, vector<int> &nums,vector<int> &dp){
        int n=nums.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int curMax=nums[i];
        int ans=INT_MIN;
        for(int j=i; j<min(n,i+k); j++){
            curMax=max(curMax,nums[j]);
            int cur=(j-i+1)*curMax+helper(j+1,k,nums,dp);

            ans=max(ans,cur);
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n+1,0);
        // return helper(0,k,arr,dp);
        //tabulation
        for(int i=n-1; i>=0; i--){
            int curMax=arr[i];
            int ans=INT_MIN;
            for(int j=i; j<min(n,i+k); j++){
                curMax=max(curMax,arr[j]);
                int cur=(j-i+1)*curMax+dp[j+1];
                ans=max(cur,ans);
            }
            dp[i]=ans;
        }
        return dp[0];
    }
};