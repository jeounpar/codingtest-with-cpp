#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, s;
int answer;
vector<int> vc;
void solve(int len, int idx, vector<int> tmp) {
  if (tmp.size() == len) {
    int sum = 0;
    for (auto a : tmp)
      sum += a;
    if (sum == s)
      answer++;
  }
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
  cin >> n >> s;
  int t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    vc.push_back(t);
  }
  sort(vc.begin(), vc.end());
  for (int len = 1; len <= n; len++) {
    solve(len, 0, {});
  }
  cout << answer;
  return 0;
}