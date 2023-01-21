#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int r, c;
vector<string> vc;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool ok[1501][1501];
bool ok2[1501][1501];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> r >> c;
  string s;
  queue<pair<int, int>> Q;
  vector<pair<int, int>> b;
  for (int i = 0; i < r; i++) {
    cin >> s;
    vc.push_back(s);
    for (int j = 0; j < c; j++) {
      if (vc[i][j] == 'L')
        b.push_back({i, j});
      if (vc[i][j] != 'X')
        Q.push({i, j});
    }
  }
  int x1, y1, x2, y2;
  x1 = b[0].first;
  y1 = b[0].second;
  x2 = b[1].first;
  y2 = b[1].second;

  int day = 0;
  queue<pair<int, int>> Q2;
  Q2.push({x1, y1});
  while (true) {
    queue<pair<int, int>> Q2_tmp;
    bool flag = false;
    while (!Q2.empty()) {
      auto cur = Q2.front();
      Q2.pop();
      for (int i = 0; i < 4; i++) {
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || ok[nx][ny])
          continue;
        ok[nx][ny] = true;
        if (vc[nx][ny] == '.') {
          Q2.push({nx, ny});
        } else if (vc[nx][ny] == 'X') {
          Q2_tmp.push({nx, ny});
        } else if (nx == x2 && ny == y2) {
          flag = true;
          break;
        }
      }
    }
    Q2 = Q2_tmp;
    if (flag)
      break;
    else
      day++;

    queue<pair<int, int>> tmp;
    while (!Q.empty()) {
      auto cur = Q.front();
      Q.pop();
      for (int t = 0; t < 4; t++) {
        int nx = cur.first + dx[t];
        int ny = cur.second + dy[t];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || ok2[nx][ny])
          continue;
        if (vc[nx][ny] == 'X') {
          ok2[nx][ny] = true;
          vc[nx][ny] = '.';
          tmp.push({nx, ny});
        }
      }
    }
    Q = tmp;
  }
  cout << day;
  return 0;
}