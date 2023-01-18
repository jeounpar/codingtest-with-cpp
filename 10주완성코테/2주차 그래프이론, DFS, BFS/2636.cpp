#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int arr[101][101];
bool ok[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
set<pair<int, int>> S;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  int cnt = 0;
  int last_cnt = 0;

  while (true) {
    S.clear();
    bool ok[101][101];

    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        ok[i][j] = false;

    queue<pair<int, int>> Q;
    Q.push({0, 0});
    ok[0][0] = true;
    while (!Q.empty()) {
      auto cur = Q.front();
      Q.pop();
      for (int t = 0; t < 4; t++) {
        int nx = cur.first + dx[t];
        int ny = cur.second + dy[t];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || ok[nx][ny])
          continue;
        if (arr[nx][ny] == 1) {
          S.insert({nx, ny});
          continue;
        }
        ok[nx][ny] = true;
        Q.push({nx, ny});
      }
    }
    if (S.size() == 0)
      break;
    cnt++;
    last_cnt = S.size();
    for (auto a : S)
      arr[a.first][a.second] = 0;
  }
  cout << cnt << "\n";
  cout << last_cnt;
  return 0;
}