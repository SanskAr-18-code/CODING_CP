class Solution {
  public:
    int solve(int i,int j,vector<int> &arr,vector<vector<int>> & dp){
        if(i==j) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int res=INT_MAX;

        for(int k=i; k<j; k++){
            int curr=arr[i-1]*arr[k]*arr[j]+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
            if(curr<res ) res=curr;
        }
        return dp[i][j]=res ;
    }
    int matrixMultiplication(vector<int> &arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));

        // return solve(1,n-1,arr,dp);
        //Tabulation
        
        for(int i=n-1; i>0; i--){
            for(int j=i+1; j<n ; j++){
                int res=INT_MAX;
                for(int k=i; k<j; k++){
                    int cur=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    if(cur<res) res=cur;
                }
                dp[i][j]=res;
                
            }
        }
        return dp[1][n-1];
        
    }
};