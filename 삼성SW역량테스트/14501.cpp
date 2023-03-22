#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int d[16];
int p[16];
int n;
int ans;

void solve(int day, int sum) {
  if (day > n + 1)
    return;
  if (day == n + 1) {
    if (sum > ans) {
      ans = sum;
    }
    return;
  }
  solve(day + 1, sum);
  solve(day + d[day], sum + p[day]);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  int a, b;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b;
    d[i] = a;
    p[i] = b;
  }
  solve(1, 0);
  cout << ans << '\n';
  return 0;
}