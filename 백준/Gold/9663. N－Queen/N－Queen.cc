#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int col[16];
int n, total = 0;

bool check(int level) {
  for (int i = 0; i < level; i++)
    if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)
      return false;

  return true;
}

void solve(int x) {
  if (x == n)
    total++;
  else {
    for (int i = 0; i < n; i++) {
      col[x] = i;
      if (check(x))
        solve(x + 1);
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  solve(0);
  cout << total;
  return 0;
}