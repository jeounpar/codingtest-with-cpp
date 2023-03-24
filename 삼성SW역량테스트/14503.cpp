// 27m 24s
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, r, c, d;
int board[51][51];

// 0 -> 북, 1 -> 동, 2 -> 남, 3 -> 서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

vector<int> get_dir(int d) {
  vector<int> vc;
  for (int i = 0; i < 4; i++) {
    d--;
    if (d < 0)
      d = 3;
    vc.push_back(d);
  }
  return vc;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> m;
  cin >> r >> c >> d;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> board[i][j];

  int ans = 0;
  while (true) {
    // 0 -> 청소 X, 1 -> 벽, 2 -> 청소 O
    if (board[r][c] == 0) {
      ans++;
      board[r][c] = 2;
    }
    bool flag = false;
    vector<int> vc = get_dir(d);
    for (int i = 0; i < 4; i++) {
      int nx = r + dx[vc[i]];
      int ny = c + dy[vc[i]];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 1)
        continue;
      if (board[nx][ny] == 0) {
        flag = true;
        r = nx;
        c = ny;
        d = vc[i];
        break;
      }
    }
    if (!flag) {
      int behind = (d + 2) % 4;
      int nx = r + dx[behind];
      int ny = c + dy[behind];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 1)
        break;
      r = nx;
      c = ny;
    }
  }
  cout << ans;
  return 0;
}