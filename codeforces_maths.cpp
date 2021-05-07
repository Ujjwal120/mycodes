#include<bits/stdc++.h>
#define ll long long 
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int p = 1e9+7;
const int maxn = 1e5+2;

void solve() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if(a > b*c) { cout << "-1\n"; return; }
  ll pro = b*d;
  ll kth = (a - a%(pro))/pro + 1;
  ll ans = a*(kth) - pro*(kth)*(kth-1)/2;
  cout << ans << "\n";
}

int main() {
  fast
  int t; cin >> t;
  while(t--) solve();
  return 0;
}