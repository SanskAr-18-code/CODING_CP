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
    int n;
    cin >> n;
    vector<int> arr;
    long long sum = 0;
    int globalmin = 1e9;
    int secsmall = 1e9;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;

        vector<int> a(m);
        for (int j = 0; j < m; j++)
            cin >> a[j];
        sort(a.begin(), a.end());
        globalmin = min(globalmin, a[0]);
        secsmall = min(secsmall, a[1]);
        sum += a[1];
    }

    cout << sum - secsmall + globalmin << endl;
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