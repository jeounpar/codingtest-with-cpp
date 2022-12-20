#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define X first
#define Y second

int d[1001];
int ans[1001];
vector<pair<int, int>> adj[1001];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, x;
  cin >> n >> m >> x;
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  for (int st = 1; st <= n; st++) {
    for (int i = 1; i <= n; i++)
      d[i] = INT_MAX;
    d[st] = 0;
    pq.push({d[st], st});
    while (!pq.empty()) {
      auto cur = pq.top();
      pq.pop();
      if (d[cur.Y] != cur.X)
        continue;
      for (auto nxt : adj[cur.Y]) {
        if (d[nxt.Y] <= d[cur.Y] + nxt.X)
          continue;
        d[nxt.Y] = d[cur.Y] + nxt.X;
        pq.push({d[nxt.Y], nxt.Y});
      }
    }
    if (st == x) {
      for (int t = 1; t <= n; t++) {
        if (t == x)
          continue;
        ans[t] += d[t];
      }
    } else {
      ans[st] += d[x];
    }
  }
  cout << *max_element(ans + 1, ans + 1 + n);
  return 0;
}