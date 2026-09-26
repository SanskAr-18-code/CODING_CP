class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int n=adj.size();
        vector<bool> vis(n,false);
        queue<int> q;
        vis[0]=true;
        q.push(0);
        vector<int> res;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            res.push_back(it);
            for(auto itr:adj[it]){
                if(!vis[itr]){
                    vis[itr]=true;
                    q.push(itr);
                }
            }
        }
        return res;
    }
};