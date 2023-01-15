#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t, m, n, k;
int bd[51][51];
bool chk[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> m >> n >> k;
    for (int i = 0; i <= 50; i++)
      for (int j = 0; j <= 50; j++)
        bd[i][j] = 0;
    for (int i = 0; i <= 50; i++)
      for (int j = 0; j <= 50; j++)
        chk[i][j] = false;
    while (k--) {
      int x, y;
      cin >> x >> y;
      bd[x][y] = 1;
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (bd[i][j] == 1 && !chk[i][j]) {
          ans++;
          queue<pair<int, int>> Q;
          Q.push({i, j});
          chk[i][j] = true;
          while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            for (int t = 0; t < 4; t++) {
              int nx = cur.first + dx[t];
              int ny = cur.second + dy[t];
              if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                continue;
              if (bd[nx][ny] == 0 || chk[nx][ny])
                continue;
              chk[nx][ny] = true;
              Q.push({nx, ny});
            }
          }
        }
      }
    }
    cout << ans << "\n";
  }
  return 0;
}