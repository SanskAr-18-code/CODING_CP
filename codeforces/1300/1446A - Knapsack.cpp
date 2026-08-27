#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;

void solve()
{
    int n;
    ll w;
    cin >> n >> w;

    vector<pair<ll, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }

    ll limit = (w + 1) / 2;
    ll curr = 0;
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].first > w)
            continue;

        if (arr[i].first >= limit)
        {
            cout << 1 << endl;
            cout << arr[i].second << endl;
            return;
        }

        curr += arr[i].first;
        res.push_back(arr[i].second);

        if (curr >= limit)
        {
            cout << res.size() << endl;
            for (auto it : res)
            {
                cout << it << " ";
            }
            cout << endl;
            return;
        }
    }

    cout << -1 << endl;
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
