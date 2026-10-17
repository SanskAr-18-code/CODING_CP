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

bool sameparity(int a, int b)
{
    return (a % 2 == 0 && b % 2 == 0) || (a % 2 != 0 && b % 2 != 0);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int maxSum = INT_MIN;
    vector<int> dp(n, 0);
    int sum = arr[0];
    dp[0] = arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        if (sameparity(arr[i], arr[i + 1]))
        {
            dp[i + 1] = arr[i + 1];
        }
        else
        {
            int currsum = arr[i + 1] + dp[i];
            dp[i + 1] = max(currsum, arr[i + 1]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
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