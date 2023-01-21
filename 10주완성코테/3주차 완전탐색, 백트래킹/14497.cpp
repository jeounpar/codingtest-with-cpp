#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int arr[301][301];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<string> vc;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  int x1, y1, x2, y2;
  cin >> n >> m;
  cin >> x1 >> y1 >> x2 >> y2;
  x1--;
  y1--;
  x2--;
  y2--;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    vc.push_back(s);
  }
  queue<pair<int, int>> Q;
  Q.push({x1, y1});
  int cnt = 0;
  while (vc[x2][y2] != '0') {
    cnt++;
    queue<pair<int, int>> tmp;
    while (!Q.empty()) {
      auto cur = Q.front();
      Q.pop();
      for (int i = 0; i < 4; i++) {
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || arr[nx][ny] > 0)
          continue;
        arr[nx][ny] = cnt;
        if (vc[nx][ny] != '0') {
          vc[nx][ny] = '0';
          tmp.push({nx, ny});
        } else
          Q.push({nx, ny});
      }
    }
    Q = tmp;
  }
  cout << arr[x2][y2];
  return 0;
}