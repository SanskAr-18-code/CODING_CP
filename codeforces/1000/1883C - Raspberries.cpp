#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;

    int ans = INT_MAX;
    int even = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        int rem = x % k;
        ans = min(ans, (k - rem) % k);
        if (x % 2 == 0)
            even++;
    }
    if (k == 4 && n > 1)
    {
        ans = min(ans, max(0, 2 - even));
    }
    cout << ans << '\n';
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
