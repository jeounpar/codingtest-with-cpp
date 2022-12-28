#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int s[51][51];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  vector<pair<int, int>> ch;
  vector<pair<int, int>> homes;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> s[i][j];
      if (s[i][j] == 2)
        ch.push_back({i, j});
      else if (s[i][j] == 1)
        homes.push_back({i, j});
    }
  }
  vector<int> vc;
  for (int i = 0; i < ch.size() - m; i++)
    vc.push_back(0);
  for (int i = 0; i < m; i++)
    vc.push_back(1);
  int ans = INT_MAX;
  do {
    int dist_sum = 0;
    for (auto home : homes) {
      int dist = INT_MAX;
      for (int i = 0; i < vc.size(); i++) {
        if (vc[i] == 1) {
          int tmp =
              abs(home.first - ch[i].first) + abs(home.second - ch[i].second);
          dist = min(tmp, dist);
        }
      }
      dist_sum += dist;
    }
    ans = min(ans, dist_sum);
  } while (next_permutation(vc.begin(), vc.end()));
  cout << ans;
  return 0;
}