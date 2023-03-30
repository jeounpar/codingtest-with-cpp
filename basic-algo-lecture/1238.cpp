#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, x;
vector<pair<int, int>> adj[1001];
int d[1001];
const int INF = 1e9 + 10;
int ans = -INF;

int solve(int st, int ed) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  for (int i = 1; i <= n; i++)
    d[i] = INF;
  d[st] = 0;
  pq.push({d[st], st});
  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();
    if (d[cur.second] != cur.first)
      continue;
    for (auto nxt : adj[cur.second]) {
      if (d[cur.second] + nxt.first >= d[nxt.second])
        continue;
      d[nxt.second] = d[cur.second] + nxt.first;
      pq.push({d[nxt.second], nxt.second});
    }
  }
  return d[ed];
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> x;
  int a, b, c;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
  }

  for (int i = 1; i <= n; i++)
    ans = max(ans, solve(i, x) + solve(x, i));
  cout << ans;
  return 0;
}