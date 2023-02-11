#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
ll arr[100004];

bool check(ll mid) {
  int tmp = mid;
  int cnt = 1;
  for (int i = 0; i < n; i++) {
    if (mid - arr[i] >= 0) {
      mid -= arr[i];
    } else {
      mid = tmp;
      cnt++;
      if (arr[i] > mid)
        return false;
      else
        mid -= arr[i];
    }
  }
  // cout << cnt << "\n";
  return cnt <= m;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> m;
  ll st = 0, ed = 10000000004;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ll mid, ans = INT_MAX;
  while (st <= ed) {
    mid = (st + ed + 1) / 2;
    // cout << st << " " << ed << " " << mid << "\n";
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