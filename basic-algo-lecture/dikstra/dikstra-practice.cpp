#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<pair<int, int>> adj[20001];
int d[20001];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int v, e;
  cin >> v >> e;
  int st;
  cin >> st;
  while (e--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
  }
  for (int i = 1; i <= v; i++)
    d[i] = INT_MAX;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  d[st] = 0;
  pq.push({0, st});
  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if (d[cur.second] != cur.first)
      continue;
    for (auto next : adj[cur.second]) {
      if (d[next.second] <= d[cur.second] + next.first)
        continue;
      d[next.second] = d[cur.second] + next.first;
      pq.push({d[next.second], next.second});
    }
  }
  for (int i = 1; i <= v; i++) {
    if (d[i] == INT_MAX)
      cout << "INF\n";
    else
      cout << d[i] << "\n";
  }
  return 0;
}