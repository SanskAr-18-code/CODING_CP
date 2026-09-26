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
    char s1;
    string s;
    cin >> n >> s1 >> s;
    vector<int> green;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'g')
        {
            green.push_back(i);
            green.push_back(i + n);
        }
    }
    sort(green.begin(), green.end());
    stack<int> st;
    for (int i = green.size() - 1; i >= 0; i--)
    {
        st.push(green[i]);
    }
    int k = 0;
    int maxDiff = 0;
    while (!st.empty() && k < n)
    {
        int it = st.top();
        if (s[k] == 'g')
        {
            st.pop();
            k++;
        }
        else if (s[k] == s1)
        {
            maxDiff = max(maxDiff, it - k);
            k++;
        }
        else
            k++;
    }

    cout << maxDiff << endl;
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