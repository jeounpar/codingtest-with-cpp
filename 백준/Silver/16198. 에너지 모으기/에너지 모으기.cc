#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int ans = 0;
vector<int> vc(n + 1);

void solve(vector<int> tmp, int sum) {
  if (tmp.size() == 2) {
    if (sum > ans)
      ans = sum;
    return;
  }
  for (int i = 1; i < tmp.size() - 1; i++) {
    int t = tmp[i - 1] * tmp[i + 1];
    int a = tmp[i];
    tmp.erase(tmp.begin() + i);
    solve(tmp, sum + t);
    tmp.insert(tmp.begin() + i, a);
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
  solve(vc, 0);
  cout << ans;
  return 0;
}