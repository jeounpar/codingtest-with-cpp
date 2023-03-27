#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int board[11][11];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = INT_MAX;
bool ok[11][11];

void solve(int sum, int cnt) {
  if (cnt == 3) {
    ans = min(ans, sum);
    return;
  }
  for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < n - 1; j++) {
      if (ok[i][j])
        continue;
      bool flag = false;
      for (int k = 0; k < 4; k++) {
        if (ok[i + dx[k]][j + dy[k]]) {
          flag = true;
          break;
        }
      }
      if (flag)
        continue;
      ok[i][j] = true;
      for (int k = 0; k < 4; k++)
        ok[i + dx[k]][j + dy[k]] = true;

      int t = board[i][j];
      for (int k = 0; k < 4; k++)
        t += board[i + dx[k]][j + dy[k]];

      solve(sum + t, cnt + 1);

      ok[i][j] = false;
      for (int k = 0; k < 4; k++)
        ok[i + dx[k]][j + dy[k]] = false;
    }
  }
}
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> board[i][j];
  solve(0, 0);
  cout << ans;
  return 0;
}