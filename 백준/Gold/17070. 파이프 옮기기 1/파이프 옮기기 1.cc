#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int board[17][17];
int n, ans;
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};

struct info {
  int x, y, d;
};

queue<info> q;

void move(int x, int y, int d, int i) {
  int nx = x + dx[i];
  int ny = y + dy[i];
  int nd = i;
  if (board[nx][ny] == 0 && nx > 0 && nx <= n && ny > 0 && ny <= n) {
    if (i == 1) {
      if (board[nx - 1][ny] == 1 || board[nx][ny - 1] == 1)
        return;
    }
    q.push({nx, ny, nd});
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> board[i][j];
    }
  }
  q.push({1, 2, 0});
  while (!q.empty()) {
    auto cur = q.front();
    int x = cur.x;
    int y = cur.y;
    int d = cur.d;
    q.pop();
    if (x == n && y == n)
      ans++;
    if (d == 0) {
      for (int i = 0; i < 2; i++) {
        move(x, y, d, i);
      }
    } else if (d == 1) {
      for (int i = 0; i < 3; i++) {
        move(x, y, d, i);
      }
    } else {
      for (int i = 1; i < 3; i++) {
        move(x, y, d, i);
      }
    }
  }
  cout << ans;
  return 0;
}