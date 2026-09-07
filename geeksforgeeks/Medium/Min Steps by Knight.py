class Solution {
	public:
	int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
		int dr[] = {-2, -2, -1, -1, 1, 1, 2, 2};
		int dc[] = {-1, 1, -2, 2, -2, 2, -1, 1};
		int sr = knightPos[0];
		int sc = knightPos[1];
		queue<pair<int, int>> q;
		vector<vector<int>> dist(n+1, vector<int> (n+1, -1));
		q.push({sr, sc});
		dist[sr][sc] = 0;
		while (!q.empty()) {
			auto it = q.front();
			int x = it.first;
			int y = it.second;
			q.pop();

			if (x == targetPos[0] && y == targetPos[1]) {
				return dist[x][y];
			}
			for (int i = 0; i<8; i++) {
				int nr = x + dr[i];
				int nc = y + dc[i];

				if (nr > 0 && nr<= n  && nc > 0 && nc<= n && dist[nr][nc] == -1) {
					dist[nr][nc] = 1 + dist[x][y];
					q.push({nr, nc});
				}

			}
		}
		return 0;
	}
};
