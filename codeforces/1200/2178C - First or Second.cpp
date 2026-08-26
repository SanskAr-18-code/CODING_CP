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

#define int long long
void solve()
{
    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<long long> pref(n + 1, 0);
    pref[1] = (a[1]);
    for (int i = 2; i <= n; i++)
    {
        pref[i] = pref[i - 1] + abs(a[i]);
    }

    long long ans = -4e18;
    long long suf = 0;
    for (int i = n; i >= 1; i--)
    {
        ans = max(ans, pref[i - 1] + suf);
        suf -= a[i];
    }
    cout << ans << '\n';
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
        solve();
}