#include <bits/stdc++.h>
using namespace std;
void solve()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int mn = n;
  int mx = 0;
  int cnt = 0;

  for (int i = 0; i < n; i++)
  {
    if (s[i] == '1')
    {
      cnt++;
      mn = min(mn, i + 1);
      mx = max(mx, i + 1);
    }
  }
  if(cnt==2) cout<<1<<endl;
  else 
  cout << mx - mn << endl;

}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
