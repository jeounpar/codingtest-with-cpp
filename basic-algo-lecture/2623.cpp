#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int ind[1001];
vector<int> adj[1001];

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> m;
  int t;
  for (int i = 0; i < m; i++) {
    cin >> t;
    int a;
    vector<int> tmp;
    for (int j = 0; j < t; j++) {
      cin >> a;
      tmp.push_back(a);
    }
    int x = tmp[0];
    for (int j = 1; j < t; j++) {
      adj[x].push_back(tmp[j]);
      ind[tmp[j]] += 1;
      x = tmp[j];
    }
  }
  queue<int> Q;
  vector<int> ans;
  for (int i = 1; i <= n; i++) {
    if (ind[i] == 0)
      Q.push(i);
  }
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    ans.push_back(cur);
    for (auto a : adj[cur]) {
      ind[a] -= 1;
      if (ind[a] == 0)
        Q.push(a);
    }
  }
  if (ans.size() != n)
    cout << "0";
  else {
    for (auto a : ans)
      cout << a << "\n";
  }
  return 0;
}