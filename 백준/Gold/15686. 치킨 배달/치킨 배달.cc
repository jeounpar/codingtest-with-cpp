#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int arr[51][51];
vector<pair<int, int>> home;
vector<pair<int, int>> ch;
int ans = INT_MAX;

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
  for (int i = 0; i < ch.size() - m; i++)
    vc.push_back(0);
  for (int i = 0; i < m; i++)
    vc.push_back(1);
  do {
    int dist_sum = 0;
    for (auto h : home) {
      int dist = INT_MAX;
      for (int i = 0; i < vc.size(); i++) {
        if (vc[i] == 1) {
          int tmp = abs(h.first - ch[i].first) + abs(h.second - ch[i].second);
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