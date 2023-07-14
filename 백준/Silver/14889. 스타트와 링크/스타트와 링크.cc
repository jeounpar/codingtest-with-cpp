#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int score[21][21];
int ans = INT_MAX;

void solve(vector<int> &a, vector<int> &b, int idx) {
  if (idx == n + 1) {
    if (a.size() != n / 2 || b.size() != n / 2) {
      return;
    }
    if (a.size() == n / 2 && b.size() == n / 2) {
      int sum_a = 0;
      int sum_b = 0;
      for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
          sum_a += score[a[i]][a[j]];
          sum_b += score[b[i]][b[j]];
        }
      }
      if (abs(sum_a - sum_b) < ans)
        ans = abs(sum_a - sum_b);
      // cout << sum_a << " " << sum_b << "\n";
      return;
    }
  }

  a.push_back(idx);
  solve(a, b, idx + 1);
  a.pop_back();
  b.push_back(idx);
  solve(a, b, idx + 1);
  b.pop_back();
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> score[i][j];

  vector<int> a, b;
  solve(a, b, 1);
  cout << ans;
  return 0;
}