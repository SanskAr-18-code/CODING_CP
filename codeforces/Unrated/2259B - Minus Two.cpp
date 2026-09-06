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
    vector<int> arr(n);
    int odd_cnt=0;
    vector<int> even;
    int ans=0;
    for(int i=0;i<n; i++){
        int a; cin>>a;
        if (a & 1){
            odd_cnt++;
        }
        else{
            even.push_back(a/2);
        }
    }
    int odd=0;
    int eve=0;
    for(int i=0; i<even.size(); i++ ){
        if(even[i] & 1){
            odd++;
        }
        else eve++;
    }
    ans=max(odd_cnt,max(odd,eve));
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