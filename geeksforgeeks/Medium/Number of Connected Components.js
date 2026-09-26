class Solution {
  public:
    void dfs(vector<vector<int>> &adj,vector<bool> &vis,int node){
        vis[node]=true;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(adj,vis,it);
            }
        }
    }
    int countConnected(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(V,false);
        int ans=0;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                ans++;
                dfs(adj,vis,i);
            }
        }
    return ans;
    }
};