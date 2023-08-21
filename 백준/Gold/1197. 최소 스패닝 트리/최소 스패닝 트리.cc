#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int v, e;
int node[10001];
vector<tuple<int, int, int>> edges;

int find_parent(int idx) {
  // cout << idx << " ";
  if (node[idx] == idx)
    return idx;
  return node[idx] = find_parent(node[idx]);
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> v >> e;
  int a, b, c;
  for (int i = 0; i < e; i++) {
    cin >> a >> b >> c;
    edges.push_back({c, a, b});
  }
  for (int i = 1; i <= v; i++)
    node[i] = i;
  sort(edges.begin(), edges.end());
  int ans = 0;
  for (int i = 0; i < edges.size(); i++) {
    int cost, x, y;
    tie(cost, x, y) = edges[i];
    int st = find_parent(x);
    int ed = find_parent(y);
    if (st != ed) {
      node[ed] = st;
      ans += cost;
    }
  }
  cout << ans;
  return 0;
}