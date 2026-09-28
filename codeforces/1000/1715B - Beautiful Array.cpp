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
    long long n, k, b, s;
    cin >> n >> k >> b >> s;

    long long mn = b * k;
    long long mx = b * k + n * (k - 1);

    if (s < mn || s > mx)
    {
        cout << -1 << '\n';
        return;
    }

    vector<long long> a(n, 0);

    a[0] = mn;
    long long rem = s - mn;

    long long add = min(rem, k - 1);
    a[0] += add;
    rem -= add;

    for (int i = 1; i < n; i++)
    {
        add = min(rem, k - 1);
        a[i] = add;
        rem -= add;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << '\n';
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