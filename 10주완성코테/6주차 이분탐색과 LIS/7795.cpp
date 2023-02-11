#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int n, m;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> t;
  while (t--) {
    vector<int> a, b;
    cin >> n >> m;
    int ans = 0;
    int k;
    for (int i = 0; i < n; i++) {
      cin >> k;
      a.push_back(k);
    }
    for (int i = 0; i < m; i++) {
      cin >> k;
      b.push_back(k);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
      int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
      ans += idx;
    }
    cout << ans << "\n";
  }

  return 0;
}