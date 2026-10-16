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

// int ways(int idx, vector<int> &arr, vector<int> &dp)
// {
//     if (idx >= arr.size())
//     {
//         return 0;
//     }
//     if (dp[idx] != -1)
//         return dp[idx];
//     return dp[idx] = arr[idx] + ways(idx + arr[idx], arr, dp);
// }
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> dp(n,0);
    int ans=0;
    for(int i=n-1; i>=0; i--){
        int next=arr[i]+i;

        dp[i]=arr[i];
        if(next<n){
            dp[i]+=dp[next];
        }
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
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