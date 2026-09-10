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

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    // unordered_map<char,int> mp;
    // for(int i=0; i<n; i++){
    //     mp[s[i]]++;
    // }
    // int ans=0;
    // for(auto it: mp){
    //     if(it.second>1){
    //         ans+=2;
    //     }
    //     else{
    //         ans++;
    //     }
    // }
    // cout<<ans<<endl;
    // unordered_map<char,int> mp;
    unordered_set<char> st;
    vector<int> prefix(n,0);
    vector<int> suffix(n,0);
    for(int i=0; i<n; i++){
        st.insert(s[i]);
        prefix[i]=st.size();
    }
    st.clear();
    for(int i=n-1; i>=0; i--){
        st.insert(s[i]);
        suffix[i]=st.size();
    }
    int ans=0;
    for(int i=0; i<n-1; i++){
        ans=max(ans,prefix[i]+suffix[i+1]);
    }
    cout<<ans<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}