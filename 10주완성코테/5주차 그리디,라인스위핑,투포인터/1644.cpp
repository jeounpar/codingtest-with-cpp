#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int ans = 0;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  bool ok[4000001];
  memset(ok, 1, sizeof(ok));
  ok[1] = 0;
  for (int i = 2; i <= 4000000; i++) {
    for (int j = i * 2; j <= 4000000; j += i) {
      ok[j] = 0;
    }
  }
  int idx = 1;
  vector<int> arr;
  arr.push_back(0);
  for (int i = 2; i <= 4000000; i++) {
    if (ok[i]) {
      arr.push_back(arr[idx - 1] + i);
      idx++;
    }
  }
  cin >> n;
  int l = 0, r = 1;
  while (l <= r && r <= arr.size() - 1) {
    int sum = arr[r] - arr[l];
    if (sum == n) {
      ans++;
      r++;
    } else if (sum < n)
      r++;
    else if (sum > n)
      l++;
  }
  cout << ans;
  return 0;
}