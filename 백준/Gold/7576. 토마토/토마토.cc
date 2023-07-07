#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int m, n;
int board[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int d[1001][1001];
int INF = 1e9 + 10;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> m >> n;
  // x y time
  int cnt = 0;
  int t_cnt = 0;
  queue<pair<int, int>> Q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      d[i][j] = INF;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == -1) {
        cnt++;
      } else if (board[i][j] == 1) {
        Q.push({i, j});
        d[i][j] = 0;
        t_cnt++;
      }
    }
  }
  if (t_cnt == m * n - cnt) {
    cout << 0;
    return 0;
  }
  cnt = m * n - cnt;
  int answer = -1;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    if (t_cnt == cnt) {
      break;
    }
    for (int dir = 0; dir < 4; dir++) {
      int nx = cur.first + dx[dir];
      int ny = cur.second + dy[dir];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == -1 ||
          board[nx][ny] == 1)
        continue;
      if (d[cur.first][cur.second] + 1 < d[nx][ny]) {
        board[nx][ny] = 1;
        d[nx][ny] = d[cur.first][cur.second] + 1;
        Q.push({nx, ny});
        t_cnt++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (board[i][j] == 0) {
        cout << -1;
        return 0;
      } else if (d[i][j] != INF) {
        answer = max(answer, d[i][j]);
      }
    }
  }
  if (answer == INT_MAX)
    cout << -1;
  else
    cout << answer;
  return 0;
}