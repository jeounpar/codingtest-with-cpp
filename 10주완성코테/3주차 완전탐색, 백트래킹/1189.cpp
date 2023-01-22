#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int r, c, k;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ok[6][6];
int ans = 0;
set<vector<pair<int, int>>> S;
vector<pair<int, int>> tmp;
vector<string> vc;
void solve(int x, int y, int cnt) {
  if (cnt == k && x == 0 && y == c - 1) {
    S.insert(tmp);
    return;
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    // cout << nx << " " << ny << " " << cnt << "\n";
    if (nx < 0 || nx >= r || ny < 0 || ny >= c || ok[nx][ny])
      continue;
    if (vc[nx][ny] == 'T')
      continue;
    ok[nx][ny] = true;
    tmp.push_back({nx, ny});
    solve(nx, ny, cnt + 1);
    ok[nx][ny] = false;
    tmp.pop_back();
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> r >> c >> k;
  string s;
  for (int i = 0; i < r; i++) {
    cin >> s;
    vc.push_back(s);
  }
  ok[r - 1][0] = true;
  solve(r - 1, 0, 1);
  cout << S.size();
  return 0;
}