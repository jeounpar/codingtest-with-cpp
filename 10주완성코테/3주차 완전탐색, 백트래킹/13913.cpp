#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
int dist[200001];
int cnt[200001];
int ans = 0;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> k;

  queue<int> Q;
  dist[n] = 1;
  memset(cnt, -1, sizeof(cnt));
  Q.push(n);
  int time = 0;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    if (cur == k)
      break;
    for (int i = 0; i < 3; i++) {
      int next;
      if (i == 0)
        next = cur + 1;
      else if (i == 1)
        next = cur - 1;
      else
        next = cur * 2;
      if (next < 0 || next >= 200000)
        continue;
      if (dist[next] == 0) {
        Q.push(next);
        dist[next] = dist[cur] + 1;
        cnt[next] = cur;
      }
    }
  }
  cout << dist[k] - 1 << "\n";
  int cur = k;
  vector<int> path;
  while (true) {
    int pre = cnt[cur];
    if (pre == -1)
      break;
    path.push_back(cur);
    cur = pre;
  }
  path.push_back(n);
  for (int i = path.size() - 1; i >= 0; i--)
    cout << path[i] << " ";
  return 0;
}