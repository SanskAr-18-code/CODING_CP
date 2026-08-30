class Solution {
public:
    int len(int idx,vector<int> &nums,int pre,vector<vector<int>> &dp){
        if(idx==nums.size()) return 0;
        if(dp[idx][pre]!=-1) return dp[idx][pre];
        if(idx==pre  ||  nums[idx]<=nums[pre]){
            return dp[idx][pre]=len(idx+1,nums,pre,dp);
        }
        else{
            int nottake=len(idx+1,nums,pre,dp);
            int take = 1+len(idx+1,nums,idx,dp);
            return dp[idx][pre]=max(take,nottake);
        }
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxlen=1;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0; i<n ; i++){
            maxlen=max(maxlen,1+len(i,nums,i,dp));
        }
        //tabulation
        return maxlen;
    }
};