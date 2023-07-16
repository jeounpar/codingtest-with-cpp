#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int op[4];
int max_ans = INT_MIN;
int min_ans = INT_MAX;
vector<int> vc;

void solve(int idx, int sum) {
  // cout << sum << " ";
  if (idx == n) {
    if (sum > max_ans)
      max_ans = sum;
    if (sum < min_ans)
      min_ans = sum;
    return;
  }
  if (op[0] > 0) {
    op[0]--;
    solve(idx + 1, sum + vc[idx]);
    op[0]++;
  }
  if (op[1] > 0) {
    op[1]--;
    solve(idx + 1, sum - vc[idx]);
    op[1]++;
  }
  if (op[2] > 0) {
    op[2]--;
    solve(idx + 1, sum * vc[idx]);
    op[2]++;
  }
  if (op[3] > 0) {
    op[3]--;
    solve(idx + 1, sum / vc[idx]);
    op[3]++;
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    vc.push_back(t);
  }
  for (int i = 0; i < 4; i++) {
    cin >> op[i];
  }
  solve(1, vc[0]);
  // cout << "\n";
  cout << max_ans << "\n" << min_ans;
  return 0;
}