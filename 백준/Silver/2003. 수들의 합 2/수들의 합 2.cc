#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int vc[10001];
int pre_sum[10001];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  int t;
  for (int i = 1; i <= n; i++) {
    cin >> vc[i];
  }
  pre_sum[1] = vc[1];
  for (int i = 2; i <= n; i++) {
    pre_sum[i] = pre_sum[i - 1] + vc[i];
  }
  int ans = 0;
  int left = 0;
  int right = 0;
  while (right <= n) {
    ll csum = pre_sum[right] - pre_sum[left];
    if (csum <= m) {
      if (csum == m)
        ans++;
      right++;
    } else
      left++;
  }
  cout << ans;
  return 0;
}