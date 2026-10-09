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
    ll k;
    cin >> n >> k;
    vector<vector<ll>> vec(n, vector<ll>(3));
    ll mn = INF;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> vec[i][j];
        }
        mn = min(mn, vec[i][0] + vec[i][1] + vec[i][2]);
    }
    ll low = mn;
    ll high = mn + k;
    ll ans = low;

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll tempk = k;
        bool possible = true;

        for (int i = 0; i < n; i++)
        {
            ll a = vec[i][0];
            ll b = vec[i][1];
            ll c = vec[i][2];
            ll sum = a + b + c;

            if (sum < mid)
            {
                if (a <= b && b <= c)
                {
                    if (a == c)
                    {
                        possible = false;
                        break;
                    }

                    ll extra = 2LL * (b - a + 1);
                    if (a < b)
                    {
                        extra = min(extra, 2LL * (c - b + 1));
                    }

                    ll needed = (mid - sum) + extra;

                    if (tempk >= needed)
                    {
                        tempk -= needed;
                    }
                    else
                    {
                        possible = false;
                        break;
                    }
                }
                else
                {
                    ll needed = mid - sum;
                    if (tempk >= needed)
                    {
                        tempk -= needed;
                    }
                    else
                    {
                        possible = false;
                        break;
                    }
                }
            }
        }

        if (possible)
        {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
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