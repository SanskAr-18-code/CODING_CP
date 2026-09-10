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
    int a = -1;
    int b = -1;
    if (n & 1)
    {
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                a = n / i;
                b = n - a;
                break;
            }
        }
        if (a == -1 && b == -1)
        {
            a = 1;
            b = n - 1;
        }
        cout << a << " " << b << endl;
    }
    else
    {
        cout << n / 2 << " " << n / 2 << endl;
    }
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