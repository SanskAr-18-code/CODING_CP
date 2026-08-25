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
ll maxSum(int idx,vector<ll> &points,vector<ll> &dp){
    if(idx==0){
        return 0;
    }
    if(idx==1){
        return points[idx];
    }
    if (dp[idx]!=-1) return dp[idx];
    ll nottake=maxSum(idx-1,points,dp);
    ll take=points[idx]+ maxSum(idx-2,points,dp);
    return dp[idx]=max(nottake,take);
}
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n;i++){
        cin>>a[i];
    }

    ll mx=*max_element(a.begin(),a.end());

    vector<ll> cnt(mx+1,0);
    vector<ll> points(mx+1,0);
    for(int i=0; i<n; i++){
        cnt[a[i]]++;
    }
    for(int i=1; i<=mx ; i++){
        points[i]=i*cnt[i];
    }
    vector<ll> dp(mx+1,-1);
    cout<<maxSum(mx,points,dp);
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