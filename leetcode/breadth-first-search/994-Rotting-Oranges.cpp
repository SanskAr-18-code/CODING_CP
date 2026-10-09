class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // bfs traversal
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = false;
                }
            }
        }
        int ans = 0;
        while (!q.empty()) {
            int l = q.size();
            bool flag = false;
            for (int k = 0; k < l; k++) {
                auto it = q.front();
                q.pop();
                int dr[] = {0, -1, 0, 1, 0};
                for (int i = 0; i < 4; i++) {
                    int nr = it.first + dr[i];
                    int nc = it.second + dr[i + 1];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        !vis[nr][nc] && grid[nr][nc] == 1) {
                        flag = true;
                        grid[nr][nc] = 2;
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            if (flag)
                ans++;
        }
        bool possible = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    possible = false;
                    break;
                }
            }
        }
        if (possible) {
            return ans;
        }
        return -1;
    }
};