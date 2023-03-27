#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
vector<int> adj[32001];
int ind[32001];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> m;

  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    adj[a].push_back(b);
    ind[b] += 1;
  }
  queue<int> Q;
  for (int i = 1; i <= n; i++) {
    if (ind[i] == 0)
      Q.push(i);
  }
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    cout << cur << "\n";
    for (auto a : adj[cur]) {
      ind[a] -= 1;
      if (ind[a] == 0)
        Q.push(a);
    }
  }
  return 0;
}