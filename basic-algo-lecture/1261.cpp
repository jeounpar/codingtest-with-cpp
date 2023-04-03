#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int board[101][101];
int d[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
const int INF = 1e9 + 10;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> m >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < m; j++) {
      board[i][j] = s[j] - '0';
    }
  }
  memset(d, INF, sizeof(d));
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      pq;
  d[0][0] = 0;
  pq.push({d[0][0], 0, 0});
  while (!pq.empty()) {
    int w, x, y;
    tie(w, x, y) = pq.top();
    pq.pop();
    if (w > d[x][y])
      continue;
    int nx, ny;
    for (int i = 0; i < 4; i++) {
      nx = x + dx[i];
      ny = y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        continue;
      if (d[x][y] + board[nx][ny] >= d[nx][ny])
        continue;
      d[nx][ny] = board[nx][ny] + d[x][y];
      pq.push({d[nx][ny], nx, ny});
    }
  }
  cout << d[n - 1][m - 1];
  return 0;
}