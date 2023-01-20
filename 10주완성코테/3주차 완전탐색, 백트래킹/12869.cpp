#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<int> arr;
int dmg[6][3] = {{9, 3, 1}, {9, 1, 3}, {1, 9, 3},
                 {1, 3, 9}, {3, 9, 1}, {3, 1, 9}};
int dist[61][61][61];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  int t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    arr.push_back(t);
  }
  for (int i = 0; i < 3 - arr.size(); i++)
    arr.push_back(0);
  queue<tuple<int, int, int>> Q;
  Q.push({arr[0], arr[1], arr[2]});
  dist[arr[0]][arr[1]][arr[2]] = 1;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    int a, b, c;
    tie(a, b, c) = cur;
    if (a == 0 && b == 0 && c == 0)
      break;
    for (int i = 0; i < 6; i++) {
      int nx = max(0, a - dmg[i][0]);
      int ny = max(0, b - dmg[i][1]);
      int nz = max(0, c - dmg[i][2]);
      if (dist[nx][ny][nz] > 0)
        continue;
      dist[nx][ny][nz] = dist[a][b][c] + 1;
      Q.push({nx, ny, nz});
    }
  }
  cout << dist[0][0][0] - 1;
  return 0;
}