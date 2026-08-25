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

// ━━━━━━━━━━━━━━ Solve ━━━━━━━━━━━━━━━
int paths(int sum,int used,vector<vector<int>> &dp,int& k,int &d){
    if(sum<0) return 0;
    if(sum==0){
        if(used) return 1;
        return 0;
    }
    int newUsed = used;
    if(dp[sum][used]!=-1) return dp[sum][used];
    int cur=0;
    for(int i=1; i<=k ;i++){
        if(i>=d) newUsed=1;
        cur=(cur+paths(sum-i,newUsed,dp,k,d))%MOD;
    }
    return dp[sum][used]=cur;
}
void solve() {
    int n,k,d;
    cin>>n>>k>>d;
    vector<vector<int>> dp(n+1,vector<int> (2,-1));
    cout<<paths(n,0,dp,k,d);
}

int32_t main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}