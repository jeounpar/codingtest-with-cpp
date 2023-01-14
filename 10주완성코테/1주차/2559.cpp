#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int pSum[100004];
int n, k;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> k;
  int t;
  for (int i = 1; i <= n; i++) {
    cin >> t;
    pSum[i] = pSum[i - 1] + t;
  }
  int ans = INT_MIN;
  // cout << n << " " << k;
  for (int i = 1; i <= n - k + 1; i++) {
    ans = max(ans, pSum[i + k - 1] - pSum[i - 1]);
  }
  cout << ans;
  return 0;
}