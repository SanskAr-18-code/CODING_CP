#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve()
{
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<vector<int>> vec;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }
    vector<int> dp(s.size() + 1, 0);
    for (int i = 1; i < s.size(); i++)
    {
        if(s[i]==s[i-1]){
            dp[i]=dp[i-1]+1;
        }
        else dp[i]=dp[i-1];
    }
    for (int i = 0; i < m; i++)
    {
        int ans = dp[vec[i][1] - 1] - dp[vec[i][0] - 1];
        cout << ans << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}