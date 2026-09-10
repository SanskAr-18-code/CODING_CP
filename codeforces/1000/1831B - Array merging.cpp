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
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    unordered_map<int, int> mp1;
    unordered_map<int, int> mp2;
    int cnt = 1;
    int cnt1 = 1;
    mp1[a[0]] = 1;
    mp2[b[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] == a[i])
        {
            cnt++;
        }
        else
        {
            mp1[a[i - 1]] = max(mp1[a[i - 1]], cnt);
            cnt = 1;
        }
        if (b[i - 1] == b[i])
        {
            cnt1++;
        }
        else
        {
            mp2[b[i - 1]] = max(mp2[b[i - 1]], cnt1);
            cnt1 = 1;
        }
    }
    mp1[a[n - 1]] = max(mp1[a[n - 1]], cnt);
    mp2[b[n - 1]] = max(mp2[b[n - 1]], cnt1);

    int res = 0;

    for (auto it : mp1)
    {
        int x = it.first;
        res = max(res, mp1[x] + mp2[x]);
    }

    for (auto it : mp2)
    {
        int x = it.first;
        res = max(res, mp1[x] + mp2[x]);
    }
    cout<<res<<endl;
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