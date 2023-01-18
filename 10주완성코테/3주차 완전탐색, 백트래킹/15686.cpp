#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int arr[51][51];
vector<pair<int, int>> home;
vector<pair<int, int>> ch;
int ans = INT_MAX;

void solve(vector<int> vc, int idx) {
  if (vc.size() == m) {
    // for (auto a : vc)
    //   cout << a << " ";
    // cout << "\n";
    int sum = 0;
    for (auto h : home) {
      int dist = INT_MAX;
      for (auto c : vc) {
        dist = min(dist,
                   abs(h.first - ch[c].first) + abs(h.second - ch[c].second));
      }
      sum += dist;
    }
    ans = min(sum, ans);
    return;
  }
  for (int i = idx + 1; i < ch.size(); i++) {
    vc.push_back(i);
    solve(vc, i);
    vc.pop_back();
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 1)
        home.push_back({i, j});
      else if (arr[i][j] == 2)
        ch.push_back({i, j});
    }
  }
  vector<int> vc;
  solve(vc, -1);
  cout << ans;
  return 0;
}