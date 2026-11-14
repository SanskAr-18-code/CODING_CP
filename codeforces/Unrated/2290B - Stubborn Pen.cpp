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
    string s;
    cin >> n >> s;

    char prev = 'B';
    int change = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == prev)
        {
            change++;
            continue;
        }
        if (prev == 'B')
            prev = 'R';
        else
            prev = 'B';
    }
    cout << change << endl;
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