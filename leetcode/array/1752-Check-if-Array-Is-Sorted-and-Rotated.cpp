class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int i=0; 
        if(is_sorted(nums.begin(),nums.end())) return true;
        while(i<n-1){
            if(nums[i+1]<nums[i]){
                i++;
                break;
            }
            i++;
        }
        // if(i==0) return false;
        int temp=i;
        vector<int> vec;
        while(i<n){
            vec.push_back(nums[i]);
            i++;
        }
        int j=0;
        while(j<temp){
            vec.push_back(nums[j]);
            j++;
        }
        if(is_sorted(vec.begin(),vec.end())){
            return true;
        }
        return false;
    }
};