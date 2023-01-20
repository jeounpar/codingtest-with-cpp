#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int r, c;
int fire[1001][1001];
int dist[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<string> vc;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> r >> c;
  string s;
  queue<pair<int, int>> Q_j;
  queue<pair<int, int>> Q;
  for (int i = 0; i < r; i++) {
    cin >> s;
    vc.push_back(s);
    for (int j = 0; j < c; j++) {
      if (vc[i][j] == 'J') {
        dist[i][j] = 1;
        Q_j.push({i, j});
      } else if (vc[i][j] == 'F') {
        fire[i][j] = 1;
        Q.push({i, j});
      }
    }
  }
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if (nx < 0 || nx >= r || ny < 0 || ny >= c)
        continue;
      if (fire[nx][ny] > 0 || vc[nx][ny] == '#')
        continue;
      fire[nx][ny] = fire[cur.first][cur.second] + 1;
      Q.push({nx, ny});
    }
  }
  int ans = INT_MAX;
  while (!Q_j.empty()) {
    auto cur = Q_j.front();
    Q_j.pop();
    for (int i = 0; i < 4; i++) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
        continue;
      }
      if (vc[nx][ny] != '.' || dist[nx][ny] > 0 ||
          (fire[nx][ny] != 0 &&
           fire[nx][ny] <= dist[cur.first][cur.second] + 1))
        continue;
      dist[nx][ny] = dist[cur.first][cur.second] + 1;
      Q_j.push({nx, ny});
    }
  }
  // for (int i = 0; i < r; i++) {
  //   for (int j = 0; j < c; j++)
  //     cout << fire[i][j];
  //   cout << "\n";
  // }
  // cout << "\n";

  for (int i = 0; i < r; i++) {
    if (dist[i][0] != 0)
      ans = min(ans, dist[i][0]);
  }
  for (int i = 0; i < r; i++) {
    if (dist[i][c - 1] != 0)
      ans = min(ans, dist[i][c - 1]);
  }
  for (int i = 0; i < c; i++) {
    if (dist[0][i] != 0)
      ans = min(ans, dist[0][i]);
  }
  for (int i = 0; i < c; i++) {
    if (dist[r - 1][i] != 0)
      ans = min(ans, dist[r - 1][i]);
  }
  if (ans == INT_MAX)
    cout << "IMPOSSIBLE";
  else
    cout << ans;
  return 0;
}