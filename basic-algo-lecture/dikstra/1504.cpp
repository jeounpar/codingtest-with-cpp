#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int d[801];
int n, e;
int v1, v2;
vector<pair<int, int>> adj[801];

ll solve(int st, int ed) {
  for (int i = 1; i <= 800; i++)
    d[i] = INT_MAX;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  d[st] = 0;
  pq.push({d[st], st});
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
  return d[ed];
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> e;
  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }
  cin >> v1 >> v2;

  ll ans1 = solve(1, v1) + solve(v1, v2) + solve(v2, n);
  ll ans2 = solve(1, v2) + solve(v2, v1) + solve(v1, n);
  ll ans = min(ans1, ans2);
  if (ans >= INT_MAX)
    cout << -1;
  else
    cout << ans;
  return 0;
}