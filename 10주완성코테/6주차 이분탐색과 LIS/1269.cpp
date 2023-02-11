#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
unordered_map<int, int> M;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> m;
  int t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    M[t]++;
  }
  for (int i = 0; i < m; i++) {
    cin >> t;
    M[t]++;
  }
  int ans = 0;
  for (auto i : M) {
    if (i.second == 1)
      ans++;
  }
  cout << ans;
  return 0;
}