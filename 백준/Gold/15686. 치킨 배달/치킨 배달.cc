#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int ans = INT_MAX;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

void solve(int idx, vector<pair<int, int>> &vc) {
  if (vc.size() == m) {
    int sum = 0;
    for (int i = 0; i < home.size(); i++) {
      int t = INT_MAX;
      for (auto a : vc) {
        t = min(t,
                abs(home[i].first - a.first) + abs(home[i].second - a.second));
      }
      sum += t;
    }
    ans = min(ans, sum);
    return;
  }
  for (int i = idx; i < chicken.size(); i++) {
    vc.push_back(chicken[i]);
    solve(i + 1, vc);
    vc.pop_back();
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;
  int t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> t;
      if (t == 1) {
        home.push_back({i, j});
      } else if (t == 2) {
        chicken.push_back({i, j});
      }
    }
  }
  vector<pair<int, int>> tmp;
  solve(0, tmp);
  cout << ans;
  return 0;
}