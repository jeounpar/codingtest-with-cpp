#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  int a, b;
  vector<pair<int, int>> vc;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    vc.push_back({b, a});
  }
  sort(vc.begin(), vc.end());
  int ans = 1;
  auto cur = vc[0];
  for (int i = 1; i < n; i++) {
    if (vc[i].second >= cur.first)
      ans++;
    cur = vc[i];
  }

  cout << ans;
  return 0;
}