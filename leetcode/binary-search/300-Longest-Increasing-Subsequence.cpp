class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        for(int i=0; i<n; i++){
            int ans=1;
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]){
                    int cur=1+dp[j];
                    ans=max(ans,cur);
                }
            }
            dp[i]=ans;
        }
       int len=*max_element(dp.begin(),dp.end());
       return len;
    }
};