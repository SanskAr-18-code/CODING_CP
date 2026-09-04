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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back({cost[i], a[i]});
    }
    sort(vec.begin(), vec.end());
    long long total = k;
    int cnt = 1;
    int i = 0;

    while (cnt < n)
    {
        if (vec[i].first >= k)
        {
            total += 1LL * (n - cnt) * k;
            break;
        }

        int take = min(vec[i].second, n - cnt);
        total += 1LL * take * vec[i].first;
        cnt += take;
        i++;
    }
    cout << total << endl;
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