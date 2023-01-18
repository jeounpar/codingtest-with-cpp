#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, t;
vector<int> adj[54];

int dfs(int cur) {
  int ret = 0;
  int child = 0;
  for (auto next : adj[cur]) {
    if (next == t)
      continue;
    ret += dfs(next);
    child++;
  }
  if (child == 0)
    return 1;
  return ret;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  int m;
  int root;
  for (int i = 0; i < n; i++) {
    cin >> m;
    if (m == -1)
      root = i;
    else
      adj[m].push_back(i);
  }
  cin >> t;
  if (root == t) {
    cout << "0";
    return 0;
  }
  cout << dfs(root);
  return 0;
}