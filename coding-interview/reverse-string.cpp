#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int board[51][51];
vector<string> ans;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int g_n, g_m, g_r, g_c, g_k;

string dir(int i) {
  if (i == 0)
    return "r";
  else if (i == 1)
    return "l";
  else if (i == 2)
    return "d";
  else
    return "u";
}

void solve(int dist, int x, int y, string path) {
  if (dist == g_k && (x == g_r && y == g_c)) {
    cout << path << "\n";
    // ans.push_back(path);
    return;
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (nx < 0 || nx > g_n || ny < 0 || ny > g_m)
      continue;
    solve(dist + 1, nx, ny, path + dir(i));
  }
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
  string answer = "";
  g_n = n;
  g_m = m;
  g_r = r;
  g_c = c;
  g_k = k;
  solve(0, x, y, "");
  return answer;
}

int main(void) { solution(3, 4, 2, 3, 3, 1, 5); }