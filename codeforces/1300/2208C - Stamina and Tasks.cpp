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
double points(int idx, vector<int> &c, vector<int> &p, vector<double> &dp)
{
    if (idx == c.size())
        return 0.0;
    if (dp[idx] != -1.0)
        return dp[idx];
    double notpick = points(idx + 1, c, p, dp);
    double newStamina = 1.0 - (p[idx] / 100.0);
    double pick = c[idx] + newStamina * points(idx + 1, c, p, dp);

    return dp[idx] = max(pick, notpick);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> c(n);
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i] >> p[i];
    }
    vector<double> dp(n, -1.0);
    cout << fixed << setprecision(10) << points(0, c, p, dp) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}