#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n,k;
  string s;
  cin>>n>>k>>s;
  int ans=0;
  for(int i=0; i<n; i+=k){
    bool flag=false;
    for(int j=i; j<i+k ; j++){
      if(s[j]=='0'){
        flag=true;
        break;
      }
    }
    if(!flag) ans++;
  }
  cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  int t;
  cin>>t;
  while(t--)  solve();
    return 0;
}
