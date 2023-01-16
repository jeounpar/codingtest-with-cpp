#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int h, w;
int dx[1] = {0};
int dy[1] = {1};
int ans[101][101];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> h >> w;
  for (int i = 0; i < 101; i++)
    fill(ans[i], ans[i] + 101, -1);
  queue<pair<int, int>> Q;
  string s;
  for (int i = 0; i < h; i++) {
    cin >> s;
    for (int j = 0; j < w; j++) {
      if (s[j] == 'c') {
        ans[i][j] = 0;
        Q.push({i, j});
      }
    }
  }
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    int nx = cur.first + dx[0];
    int ny = cur.second + dy[0];
    if (nx < 0 || nx + 1 > h || ny < 0 || ny + 1 > w)
      continue;
    if (ans[nx][ny] == 0)
      continue;
    ans[nx][ny] = ans[cur.first][cur.second] + 1;
    Q.push({nx, ny});
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
