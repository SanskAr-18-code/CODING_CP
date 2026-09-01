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
    vector<ll> arr(n);
    int even = 0;
    int odd = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }
    if (even != 0 && odd != 0)
    {
        cout << 2 << endl;
    }
    else
    {
        ll i = 4;
        while (1)
        {
            set<ll> rem;
            for (int k = 0; k < n; k++)
            {
                rem.insert(arr[k] % i);
            }
            if (rem.size() == 2)
            {
                cout << i << endl;
                return;
            }
            i *= 2;
        }
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