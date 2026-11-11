
class Solution {
public:
    int helper(int i, string &s,
               vector<int> &dp,
               vector<vector<bool>> &pal) {

        int n = s.size();

        if (i == n) return 0;

        if (dp[i] != -1)
            return dp[i];

        int ans = INT_MAX;

        for (int j = i; j < n; j++) {

            if (pal[i][j]) {

                int cur = 1 + helper(j + 1, s, dp, pal);

                ans = min(ans, cur);
            }
        }

        return dp[i] = ans;
    }

    int minCut(string s) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {

                if (s[i] == s[j] &&
                    (j - i <= 2 || pal[i + 1][j - 1])) {

                    pal[i][j] = true;
                }
            }
        }

        vector<int> dp(n, -1);

        return helper(0, s, dp, pal) - 1;
    }
};
