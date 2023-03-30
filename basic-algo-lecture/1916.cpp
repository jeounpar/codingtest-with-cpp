#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, st, ed;
vector<pair<int, int>> adj[1001];
int d[1001];
const int INF = 1e9 + 10;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  cin >> m;
  int a, b, c;

  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
  }
  cin >> st >> ed;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  memset(d, INF, sizeof(d));
  d[st] = 0;
  pq.push({d[st], st});
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
  cout << d[ed];
  return 0;
}