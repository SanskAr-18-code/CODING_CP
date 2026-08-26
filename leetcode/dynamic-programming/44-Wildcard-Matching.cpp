class Solution {
private:
    bool match(int i,int j,string &s,string &p,vector<vector<int>> &dp){
        if(i<0 && j<0) return true;
        if(i<0){
            for(int k=0; k<=j ; k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(j<0)  return false;
        //matched
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=match(i-1,j-1,s,p,dp);
        }
        //s[i]=='*'
        else if(p[j]=='*'){
                return dp[i][j]=match(i,j-1,s,p,dp)|match(i-1,j,s,p,dp);
        }
        return dp[i][j]=false;
    }
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>> dp(n+1,vector<bool> (m+1,0));
        // return match(n-1,m-1,s,p,dp);
        // Tabulation
        // base case
        dp[0][0]=true;
        for(int j=1; j<=m; j++){
            bool flag=true;
            for(int k=1; k<=j ; k++){
                if(p[k-1]!='*') flag=false; 
            }
            if(flag) dp[0][j]=true;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if (s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};