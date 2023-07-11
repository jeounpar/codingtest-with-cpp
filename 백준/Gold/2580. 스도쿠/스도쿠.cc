#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int board[10][10];
vector<pair<int, int>> vc;
bool solved = false;

bool check(pair<int, int> cur) {
  for (int i = 0; i < 9; i++) {
    if (i == cur.first)
      continue;
    if (board[i][cur.second] == board[cur.first][cur.second])
      return false;
  }
  for (int i = 0; i < 9; i++) {
    if (i == cur.second)
      continue;
    if (board[cur.first][i] == board[cur.first][cur.second])
      return false;
  }
  int x = cur.first / 3;
  int y = cur.second / 3;
  for (int i = 3 * x; i < 3 * x + 3; i++) {
    for (int j = 3 * y; j < 3 * y + 3; j++) {
      if (i == cur.first && j == cur.second)
        continue;
      if (board[i][j] == board[cur.first][cur.second])
        return false;
    }
  }
  return true;
}

void solve(int idx) {
  if (idx == vc.size()) {
    solved = true;
    return;
  }
  auto cur = vc[idx];
  for (int num = 1; num <= 9; num++) {
    board[cur.first][cur.second] = num;
    if (check(cur))
      solve(idx + 1);
    if (solved)
      return;
  }
  board[cur.first][cur.second] = 0;
  return;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> board[i][j];
      if (board[i][j] == 0) {
        vc.push_back({i, j});
      }
    }
  }

  solve(0);

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}