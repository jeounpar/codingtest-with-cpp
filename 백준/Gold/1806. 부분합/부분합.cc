#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, s;
vector<int> vc;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> s;
  int t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    vc.push_back(t);
  }
  int arr[n + 1];
  arr[0] = 0;
  arr[1] = vc[0];
  for (int i = 2; i <= n; i++) {
    arr[i] = arr[i - 1] + vc[i - 1];
  }
  int ed = 0;
  int ans = INT_MAX;
  for (int st = 0; st <= n; st++) {
    while (ed <= n && arr[ed] - arr[st] < s)
      ed++;
    if (ed == n + 1)
      break;
    ans = min(ans, ed - st);
  }
  if (ans == INT_MAX)
    ans = 0;
  cout << ans;
  return 0;
}