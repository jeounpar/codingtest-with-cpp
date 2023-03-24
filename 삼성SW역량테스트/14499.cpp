#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, x, y, k;
int board[21][21];
int dice[7];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> m >> x >> y >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> board[i][j];
  int t;
  for (int i = 0; i < k; i++) {
    cin >> t;
    t--;
    int nx = x + dx[t];
    int ny = y + dy[t];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
      continue;
    x = nx;
    y = ny;
    // 6 4 1 3
    // 3 6 4 1

    // 6 4 1 3
    // 4 1 3 6

    // 2 1 5 6
    // 1 5 6 2

    // 2 1 5 6
    // 6 2 1 5
    int tmp;
    tmp = dice[1];
    if (t == 0) {
      dice[1] = dice[4];
      dice[4] = dice[6];
      dice[6] = dice[3];
      dice[3] = tmp;
    } else if (t == 1) {
      dice[1] = dice[3];
      dice[3] = dice[6];
      dice[6] = dice[4];
      dice[4] = tmp;
    } else if (t == 2) {
      dice[1] = dice[5];
      dice[5] = dice[6];
      dice[6] = dice[2];
      dice[2] = tmp;
    } else {
      dice[1] = dice[2];
      dice[2] = dice[6];
      dice[6] = dice[5];
      dice[5] = tmp;
    }
    if (board[x][y] == 0) {
      board[x][y] = dice[6];
    } else {
      dice[6] = board[x][y];
      board[x][y] = 0;
    }
    cout << dice[1] << "\n";
  }
  return 0;
}
