#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int d[100001];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> vc;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    vc.push_back(t);
  }
  d[1] = vc[0];
  for (int i = 2; i <= n; i++) {
    d[i] = d[i - 1] + vc[i - 1];
  }
  while (m--) {
    int st, ed;
    cin >> st >> ed;
    cout << d[ed] - d[st - 1] << "\n";
  }

  return 0;
}