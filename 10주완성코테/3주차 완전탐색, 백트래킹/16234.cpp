#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, l, r;
int arr[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> l >> r;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
  int ans = 0;
  for (int a = 0; a < 2000; a++) {
    bool ok[54][54];
    int sum[3000];
    memset(ok, 0, sizeof(ok));
    memset(sum, 0, sizeof(sum));
    int close = 0;
    vector<pair<int, int>> vc[3000];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (ok[i][j] == 0) {
          close++;
          queue<pair<int, int>> Q;
          Q.push({i, j});
          ok[i][j] = 1;
          vc[close].push_back({i, j});
          sum[close] += arr[i][j];
          while (!Q.empty()) {
            auto cur = Q.front();
            Q.pop();
            for (int t = 0; t < 4; t++) {
              int nx = cur.first + dx[t];
              int ny = cur.second + dy[t];
              if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
              int tmp = abs(arr[cur.first][cur.second] - arr[nx][ny]);
              if (ok[nx][ny] || tmp < l || tmp > r)
                continue;
              ok[nx][ny] = 1;
              vc[close].push_back({nx, ny});
              sum[close] += arr[nx][ny];
              Q.push({nx, ny});
            }
          }
        }
      }
    }
    for (int i = 1; i <= close; i++) {
      for (auto a : vc[i]) {
        arr[a.first][a.second] = sum[i] / vc[i].size();
      }
    }
    ans = a;
    if (close == n * n)
      break;
  }
  cout << ans;
  return 0;
}