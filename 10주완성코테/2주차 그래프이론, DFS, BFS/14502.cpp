#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int board[9][9];
bool ok[9][9];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> m;
  queue<pair<int, int>> Q;
  int wall = 0;
  int virus = 0;
  int total = n * m;
  vector<pair<int, int>> vc;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
      if (board[i][j] == 2) {
        Q.push({i, j});
        virus++;
      } else if (board[i][j] == 1)
        wall++;
      if (board[i][j] == 1 || board[i][j] == 2)
        ok[i][j] = true;
    }
  }
  total = total - (wall + 3);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!ok[i][j]) {
        vc.push_back({i, j});
      }
    }
  }
  sort(vc.begin(), vc.end());
  int ans = INT_MIN;
  queue<pair<int, int>> Q_tmp;

  for (int i = 0; i < vc.size(); i++) {
    for (int j = i + 1; j < vc.size(); j++) {
      for (int k = j + 1; k < vc.size(); k++) {
        Q_tmp = Q;
        int virus_tmp = virus;
        int arr[9][9];
        for (int x = 0; x < n; x++)
          for (int y = 0; y < m; y++)
            arr[x][y] = board[x][y];
        arr[vc[i].first][vc[i].second] = 1;
        arr[vc[j].first][vc[j].second] = 1;
        arr[vc[k].first][vc[k].second] = 1;
        while (!Q_tmp.empty()) {
          auto cur = Q_tmp.front();
          Q_tmp.pop();
          for (int t = 0; t < 4; t++) {
            int nx = cur.first + dx[t];
            int ny = cur.second + dy[t];
            if (nx < 0 || nx + 1 > n || ny < 0 || ny + 1 > m)
              continue;
            if (arr[nx][ny] != 0)
              continue;
            arr[nx][ny] = 2;
            virus_tmp++;
            Q_tmp.push({nx, ny});
          }
        }
        ans = max(ans, total - virus_tmp);
      }
    }
  }
  cout << ans;

  return 0;
}