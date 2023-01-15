#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, k;
int ar[300][300];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);
  cin >> m >> n >> k;
  while (k--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i = x1 * 2; i < x2 * 2; i++)
      for (int j = y1 * 2; j < y2 * 2; j++)
        ar[j][i] = -1;
  }
  int cnt = 0;
  vector<int> s;
  for (int i = 0; i <= m * 2 - 1; i++) {
    for (int j = 0; j <= n * 2 - 1; j++) {
      if (ar[i][j] == 0) {
        int s_cnt = 1;
        cnt++;
        queue<pair<int, int>> Q;
        Q.push({i, j});
        ar[i][j] = 1;
        while (!Q.empty()) {
          auto cur = Q.front();
          Q.pop();
          for (int t = 0; t < 4; t++) {
            int nx = cur.first + dx[t];
            int ny = cur.second + dy[t];
            if (nx < 0 || nx > m * 2 - 1 || ny < 0 || ny > n * 2 - 1)
              continue;
            if (ar[nx][ny] == -1 || ar[nx][ny] == 1)
              continue;
            s_cnt++;
            ar[nx][ny] = 1;
            Q.push({nx, ny});
          }
        }
        s.push_back(s_cnt / 4);
      }
    }
  }
  cout << cnt << "\n";
  sort(s.begin(), s.end());
  for (auto a : s)
    cout << a << " ";
  return 0;
}
