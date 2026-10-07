#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int m = n - 4;
    vector<int> value(m);

    for (int i = 0; i < m; i++)
    {
        value[i] = arr[i] + arr[i + 2] - arr[i + 4];
    }
    unordered_map<int, ll> freq;
    for (int i = 0; i < m; i++)
    {
        freq[value[i]]++;
    }
    ll ans = 0;
    for (auto it : freq)
    {
        ans += it.second * (it.second - 1) / 2;
    }
    for (int i = 0; i < m; i++)
    {
        if (i + 2 < m && value[i] == value[i + 2])
            ans--;

        if (i + 4 < m && value[i] == value[i + 4])
            ans--;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}