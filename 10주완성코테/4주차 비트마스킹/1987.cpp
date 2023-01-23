#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int r, c;
vector<string> vc;
bool ok[26];
int ans = 1;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void solve(int x, int y, int cnt) {
  ans = max(ans, cnt);
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx >= r || ny < 0 || ny >= c || ok[vc[nx][ny] - 'A'])
      continue;
    ok[vc[nx][ny] - 'A'] = true;
    solve(nx, ny, cnt + 1);
    ok[vc[nx][ny] - 'A'] = false;
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> r >> c;
  string s;
  for (int i = 0; i < r; i++) {
    cin >> s;
    vc.push_back(s);
  }
  ok[vc[0][0] - 'A'] = true;
  solve(0, 0, 1);
  cout << ans;
  return 0;
}