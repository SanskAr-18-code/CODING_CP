class Solution {
public:
    int helper(int i,int j, vector<int> &nums,vector<vector<int>> &dp){
        if(i==j-1) return 0;
        int ans=INT_MIN;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i+1; k<j; k++){
            int cur=nums[i]*nums[j]*nums[k]+helper(i,k,nums,dp)+helper(k,j,nums,dp);

            if(ans<cur) ans=cur;
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);

        vector<vector<int>> dp(nums.size() ,vector<int> (nums.size(),-1));
        return helper(0,nums.size()-1,nums,dp);
    }
};