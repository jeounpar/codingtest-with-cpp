#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  vector<pair<int, int>> vc;
  int a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    vc.push_back({a, b});
  }
  sort(vc.begin(), vc.end());
  int cur = vc[0].first + vc[0].second;
  for (int i = 1; i < n; i++) {
    cur = max(cur, vc[i].first);
    cur += vc[i].second;
  }
  cout << cur;
  return 0;
}