#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
bool ok[10001];
vector<int> adj[10001];

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> m;
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    // adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int max_val = -1;
  vector<vector<int>> ans;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      ok[j] = false;
    int cnt = 1;
    queue<int> Q;
    Q.push(i);
    ok[i] = true;
    while (!Q.empty()) {
      auto cur = Q.front();
      Q.pop();
      for (auto next : adj[cur]) {
        if (ok[next])
          continue;
        ok[next] = true;
        Q.push(next);
        cnt++;
      }
    }
    max_val = max(max_val, cnt);
    ans.push_back({cnt, i});
  }
  for (auto a : ans) {
    if (a[0] == max_val)
      cout << a[1] << " ";
  }
  return 0;
}