#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
vector<string> vc;
int dist[51][51];
int ans = INT_MIN;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> m;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    vc.push_back(s);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vc[i][j] == 'L') {
        memset(dist, 0, sizeof(dist));
        queue<pair<int, int>> Q;
        Q.push({i, j});
        dist[i][j] = 1;
        while (!Q.empty()) {
          auto cur = Q.front();
          Q.pop();
          for (int t = 0; t < 4; t++) {
            int nx = cur.first + dx[t];
            int ny = cur.second + dy[t];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
              continue;
            if (vc[nx][ny] == 'W' || dist[nx][ny] > 0)
              continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1;
            Q.push({nx, ny});
            ans = max(ans, dist[nx][ny]);
            // cout << ans << " ";
          }
        }
      }
    }
  }
  cout << ans - 1;
  return 0;
}