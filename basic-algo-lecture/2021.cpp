#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, l;
vector<int> route[100001];
vector<int> nodes[100001];
bool visited[100001];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> l;
  int t;
  for (int i = 1; i <= l; i++) {
    vector<int> tmp;
    while (true) {
      cin >> t;
      if (t == -1)
        break;
      route[i].push_back(t);
      nodes[t].push_back(i);
    }
  }
  int st, ed;
  cin >> st >> ed;
  int ans = INT_MAX;
  // 현재 노선, 환승 횟수
  queue<pair<int, int>> Q;
  for (auto a : nodes[st]) {
    Q.push({a, 0});
    visited[a] = true;
  }
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    for (auto a : route[cur.first]) {
      if (a == ed) {
        ans = min(ans, cur.second);
        break;
      } else {
        for (auto node : nodes[a]) {
          if (visited[node])
            continue;
          visited[node] = true;
          Q.push({node, cur.second + 1});
        }
      }
    }
  }
  if (ans == INT_MAX)
    ans = -1;
  cout << ans;
  return 0;
}