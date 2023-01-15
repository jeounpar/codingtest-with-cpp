#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
vector<string> bd;
int dist[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  string str;
  for (int i = 0; i < n; i++) {
    cin >> str;
    bd.push_back(str);
  }
  queue<pair<int, int>> Q;
  dist[1][1] = 1;
  Q.push({1, 1});
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = cur.first + dx[i];
      int ny = cur.second + dy[i];
      if (nx < 1 || nx > n || ny < 1 || ny > m)
        continue;
      if (bd[nx][ny] == '0')
        continue;
      dist[nx][ny] = dist[cur.first][cur.second] + 1;
      Q.push({nx, ny});
    }
  }
  cout << dist[n][m];
  return 0;
}