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
    stack<int> st;
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(s[i]=='3'){
            continue;
        }
        else if(s[i]=='1'){
            st.push(i);
        }
        else{
            if(!st.empty()){
                st.pop();
                ans.push_back(i);
            }
            else{
                continue;
            }
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    cout<<ans.size()<<endl;
    sort(ans.begin(),ans.end());
    for(auto it: ans){
        cout<<it+1<<" ";
    }
    cout<<endl;
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