#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int s[101][101];
int d[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int>> adj[101];

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    string tmp;
    cin >> tmp;
    for (int j = 0; j < m; j++) {
      s[i][j + 1] = tmp[j] - '0';
    }
  }
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      pq;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      d[i][j] = INT_MAX;
  d[1][1] = 0;
  pq.push({d[1][1], 1, 1});
  while (!pq.empty()) {
    int w, x, y;
    tie(w, x, y) = pq.top();
    pq.pop();
    if (d[x][y] > w)
      continue;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 1 || nx > n || ny < 1 || ny > m)
        continue;
      if (d[nx][ny] <= d[x][y] + s[nx][ny])
        continue;
      d[nx][ny] = d[x][y] + s[nx][ny];
      pq.push({d[nx][ny], nx, ny});
    }
  }
  cout << d[n][m];
  return 0;
}