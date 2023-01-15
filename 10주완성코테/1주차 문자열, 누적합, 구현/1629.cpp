#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a, b, c;
ll go(ll a, ll b) {
  if (b == 1)
    return a % c;
  ll rst = go(a, b / 2);
  rst = (rst * rst) % c;
  if (b % 2 == 1)
    rst = (rst * a) % c;
  return rst;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> a >> b >> c;
  ll ans = go(a, b);
  cout << ans;
  return 0;
}