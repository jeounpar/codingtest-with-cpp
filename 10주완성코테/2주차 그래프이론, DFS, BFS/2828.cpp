#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, j;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> m >> j;
  int l = 1;
  int r = 0;
  int ans = 0;
  int tmp;
  for (int i = 0; i < j; i++) {
    r = l + m - 1;
    cin >> tmp;
    if (tmp >= l && tmp <= r)
      continue;
    else {
      if (tmp < l) {
        ans += (l - tmp);
        l = tmp;
      } else {
        l += (tmp - r);
        ans += (tmp - r);
      }
    }
  }
  cout << ans;
  return 0;
}