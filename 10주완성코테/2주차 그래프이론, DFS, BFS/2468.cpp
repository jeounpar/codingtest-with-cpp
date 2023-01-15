#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int ar[101][101];
bool visited[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> ar[i][j];
    }
  }
  int ans = 1;
  for (int t = 1; t <= 100; t++) {
    int tmp = 0;
    for (int i = 1; i <= n; i++)
      fill(visited[i], visited[i] + 101, false);

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (ar[i][j] > t && !visited[i][j]) {
          tmp++;
          queue<pair<int, int>> Q;
          Q.push({i, j});
          visited[i][j] = true;
          while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            for (int q = 0; q < 4; q++) {
              int nx = cur.first + dx[q];
              int ny = cur.second + dy[q];
              if (nx < 1 || nx > n || ny < 1 || ny > n)
                continue;
              if (ar[nx][ny] <= t || visited[nx][ny])
                continue;
              visited[nx][ny] = true;
              Q.push({nx, ny});
            }
          }
        }
      }
    }
    ans = max(ans, tmp);
  }
  cout << ans;
  return 0;
}