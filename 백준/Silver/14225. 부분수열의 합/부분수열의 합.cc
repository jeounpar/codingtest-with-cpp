#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<int> vc;
bool ok[20 * 100000 + 3];

void solve(int len, int idx, vector<int> &tmp) {
  if (tmp.size() == len) {
    int sum = 0;
    for (auto a : tmp)
      sum += a;
    ok[sum] = true;
    return;
  } else if (tmp.size() > len)
    return;
  for (int i = idx; i < n; i++) {
    tmp.push_back(vc[i]);
    solve(len, i + 1, tmp);
    tmp.pop_back();
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
  sort(vc.begin(), vc.end());
  vector<int> tmp;
  for (int len = 1; len <= n; len++) {
    solve(len, 0, tmp);
  }
  for (int i = 1; i <= 20 * 100000; i++) {
    if (!ok[i]) {
      cout << i;
      return 0;
    }
  }
  return 0;
}