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
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    vector<vector<vector<int>>> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    vector<pair<long long, int>> A;

    for (int i = 0; i < n; i++)
    {
        A.push_back({a[i], i});
    }
    sort(A.begin(), A.end(), greater<pair<long long, int>>());
    vector<pair<long long, int>> B;
    for (int i = 0; i < n; i++)
    {
        B.push_back({b[i], i});
    }
    sort(B.begin(), B.end(), greater<pair<long long, int>>());
    vector<pair<long long, int>> C;
    for (int i = 0; i < n; i++)
    {
        C.push_back({c[i], i});
    }
    sort(C.begin(), C.end(), greater<pair<long long, int>>());
    ll sum=0;
    for(int i=0; i<3; i++){
        ll va=A[i].first;
        ll ai=A[i].second;
        for(int j=0; j<3; j++){
            ll vb=B[j].first;
            ll bi=B[j].second;
            if(ai==bi) continue;
            for(int k=0; k<3; k++){
                ll vc=C[k].first;
                ll ci=C[k].second;
                if(ci==ai || bi==ci ) continue;
                else sum=max(va+vb+vc,sum);
            }
        }
    }
    cout<<sum<<endl;
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