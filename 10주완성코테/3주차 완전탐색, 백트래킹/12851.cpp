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
  cnt[n] = 1;
  Q.push(n);
  int time = 0;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
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
        cnt[next] += cnt[cur];
      } else if (dist[next] == dist[cur] + 1)
        cnt[next] += cnt[cur];
    }
  }
  cout << dist[k] - 1 << "\n" << cnt[k];
  return 0;
}