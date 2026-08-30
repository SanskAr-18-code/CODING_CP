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
int ways(int idx, vector<int> &l, vector<int> &r, int n, vector<int> &arr)
{
    if (idx >= 2 * n)
        return 0;
    // notake
    int nottake = 1 + ways(idx + 1, l, r, n, arr);
    // take
    int take = 0;
    if (idx == l[arr[idx]] && r[arr[idx]] != -1)
    {
        take = (r[arr[idx]] - l[arr[idx]] + 1) * (r[arr[idx]] - l[arr[idx]] + 1) + ways(r[arr[idx]] + 1, l, r, n, arr);
    }
    return max(nottake, take);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(2 * n);
    vector<int> l(n + 1, -1);
    vector<int> r(n + 1, -1);
    for (int i = 0; i < 2 * n; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
        if (l[a] == -1)
        {
            l[a] = i;
        }
        else
            r[a] = i;
    }
    // int res = ways(0, l, r, n, arr);
    // cout << res << endl;

    vector<ll> dp(2*n+1,0);
    //tabulation
    for(int i=2*n-1; i>=0; i--){
        ll nottake=dp[i+1]+1;
        ll take=0;
        if(i==l[arr[i]] && r[arr[i]]!=-1){
            ll len=r[arr[i]]-l[arr[i]]+1;
            take=(len*len)+dp[r[arr[i]]+1];
        }
        dp[i]=max(take,nottake);
    }
    cout<<dp[0]<<endl;
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