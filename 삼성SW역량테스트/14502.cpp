#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int arr[9][9];
bool ok[9][9];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int answer;
vector<pair<int, int>> virus;
void solve(int cnt) {
  if (cnt == 3) {
    queue<pair<int, int>> Q;
    int board[9][9];
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        board[i][j] = arr[i][j];
    bool visited[9][9];
    memset(visited, false, sizeof(visited));
    for (auto a : virus) {
      Q.push(a);
      visited[a.first][a.second] = true;
    }
    while (!Q.empty()) {
      auto cur = Q.front();
      Q.pop();
      for (int i = 0; i < 4; i++) {
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] ||
            board[nx][ny] > 0)
          continue;
        Q.push({nx, ny});
        board[nx][ny] = 2;
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == 0) {
          ans++;
        }
      }
    }
    answer = max(answer, ans);
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 0) {
        arr[i][j] = 1;
        solve(cnt + 1);
        arr[i][j] = 0;
      }
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 2) {
        virus.push_back({i, j});
      }
    }
  }
  solve(0);
  cout << answer;
  return 0;
}