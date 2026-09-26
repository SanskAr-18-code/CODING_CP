class Solution {
  public:
    void traversal(vector<vector<int>>& adj,vector<int> &res,int i,vector<bool>&vis) {
        auto it=adj[i];
        res.push_back(i);
    
        for (int k=0; k<it.size(); k++){
            if(!vis[it[k]]){
                vis[it[k]]=true;
                traversal(adj,res,it[k],vis);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<bool> vis(n,false);
        vector<int> res;
        for(int i=0; i<n ; i++){
            if (!vis[i]){
                vis[i]=true;
                traversal(adj,res,i,vis);
            }
        }
        return res;
    }
    
};