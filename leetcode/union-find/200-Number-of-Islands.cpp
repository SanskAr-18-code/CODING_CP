class Solution {
public:
    void dfs(int r,int c,vector<vector<char>>& grid,vector<vector<bool>>& vis,int n,int m){
        vis[r][c]=true;
        int dr[]={0,-1,0,1,0};
        for(int i=0; i<4; i++){
            int nr=r+dr[i];
            int nc=c+dr[i+1];

            if(nr<n && nr>=0 && nc<m && nc>=0 && !vis[nr][nc] && grid[nr][nc]=='1'){
                dfs(nr,nc,grid,vis,n,m);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool> (m,false));
        int ans=0;
        for(int i=0; i<n ; i++){
            for(int j=0; j<m ; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,grid,vis,n,m);
                }
            }
        }
        return ans;
    }
};