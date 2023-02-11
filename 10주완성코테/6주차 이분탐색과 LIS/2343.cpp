#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int arr[100004];

bool check(ll mid) {
  for (int i = 0; i < n; i++) {
    if (mid < arr[i])
      return false;
  }
  int tmp = mid;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    tmp -= arr[i];
    if (tmp < 0) {
      cnt++;
      tmp = mid;
      i--;
    }
  }
  if (mid != tmp)
    cnt++;
  if (cnt <= m)
    return true;
  return false;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> m;
  ll st = 0, ed = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    ed += arr[i];
  }
  ll mid, ans = INT_MAX;
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