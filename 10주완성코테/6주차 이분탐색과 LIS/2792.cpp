#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
ll arr[300004];

bool check(ll mid) {
  ll num = 0;
  for (int i = 0; i < m; i++) {
    num += arr[i] / mid;
    if (arr[i] % mid > 0)
      num++;
  }
  return n >= num;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> m;
  int t;
  ll st = 1, ed = 0;
  for (int i = 0; i < m; i++) {
    cin >> arr[i];
    ed = max(ed, arr[i]);
  }
  ll ans = INT_MAX;
  ll mid;
  while (st <= ed) {
    mid = (st + ed) / 2;
    if (check(mid)) {
      ans = min(ans, mid);
      ed = mid - 1;
    } else {
      st = mid + 1;
    }
  }
  cout << ans;
  return 0;
}