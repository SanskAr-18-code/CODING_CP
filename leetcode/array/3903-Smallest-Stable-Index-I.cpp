class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int mx=nums[0];
        for(int i=0; i<n; i++){
            mx=max(mx,nums[i]);
            int mn=nums[i];
            for(int j=i; j<n; j++){
                mn=min(nums[j],mn);
            }
            int score=mx-mn;
            if (score<=k){
                return i;
            }
        }
        return -1;
    }
};