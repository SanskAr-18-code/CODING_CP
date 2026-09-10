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
    int n, k, t;
    cin >> n >> k >> t;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int cnt = 0;
    vector<int> days;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= t)
        {
            cnt++;
        }
        else
        {
            days.push_back(cnt);
            cnt = 0;
        }
    }
    days.push_back(cnt);
    ll ans = 0;
    for (int i = 0; i < days.size(); i++)
    {
        if (days[i] >= k)
        {
            if (days[i] >= k)
                ans +=1LL* (days[i] - k + 1) * (days[i] - k + 2) / 2;
        }
    }
    cout << ans << endl;
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