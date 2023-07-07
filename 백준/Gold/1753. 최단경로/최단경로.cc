#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int v, e, k;
vector<pair<int, int>> adj[20001];
int d[20001];
const int INF = 1e9 + 10;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> v >> e;
  cin >> k;
  int a, b, c;
  for (int i = 0; i < e; i++) {
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
  }
  for (int i = 1; i <= v; i++)
    d[i] = INF;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  d[k] = 0;
  pq.push({d[k], k});
  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if (d[cur.second] != cur.first)
      continue;
    for (auto next : adj[cur.second]) {
      if (d[cur.second] + next.first >= d[next.second])
        continue;
      d[next.second] = d[cur.second] + next.first;
      pq.push({d[next.second], next.second});
    }
  }
  for (int i = 1; i <= v; i++) {
    if (d[i] == INF)
      cout << "INF\n";
    else
      cout << d[i] << "\n";
  }
  return 0;
}
