class Solution {
public:
    unordered_map<string,bool> mp;
    vector<int> dp;
    bool helper(int i,string s){
        if(i==s.size()) return true;

        if(dp[i]!=-1 ) return dp[i];

        string cur="";
        for(int k=i; k<s.size(); k++){
            cur+=s[k];
            if(mp.count(cur)){
                if(helper(k+1,s)){
                    return dp[i]=true;
                }
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        for(int i=0; i<wordDict.size(); i++){
            mp[wordDict[i]]=true;
        }

        dp.assign(s.size()+1, false);

        // return helper(0,s);
        dp[s.size()]=true;
        for(int i=n-1; i>=0; i--){
            string cur="";
            for(int k=i; k<n; k++){
                cur+=s[k];
                if(mp.count(cur)){
                    if(dp[k+1]){
                        dp[i]=true;
                    }
                }
            }
        }
        return dp[0];
    }
};