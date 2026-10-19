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

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum=0;
    int ne=0;
    int no=0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum+=arr[i];
        if(arr[i]%2==0) ne++;
        else no++;
    }
    if(sum%2==0){
        cout<<"Moggity"<<endl;
    }
    else{
        if(n==2){
            cout<<"Larpity"<<endl;
            return;
        }
        if(ne!=0){
            cout<<"Moggity"<<endl;
        }
        else{
            if(n==1 || n>=4) cout<<"Moggity"<<endl;
            else if(n==3){
                cout<<"Larpity"<<endl;
            }
        }
    }
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