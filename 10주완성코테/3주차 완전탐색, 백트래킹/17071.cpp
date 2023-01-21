#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
int dist[500001];
int pSum[1001];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> k;

  vector<int> k_arr;
  pSum[1] = 1;
  for (int i = 2; i <= 1000; i++) {
    pSum[i] = pSum[i - 1] + i;
  }
  int idx = 0;
  int t = k;
  while (t + pSum[idx] <= 500000) {
    k_arr.push_back(t + pSum[idx]);
    idx++;
  }
  // if (n > k) {
  //   int time = 0;
  //   while (n != k_arr[time]) {
  //     n--;
  //     time++;
  //     cout << n << " " << time << " " << k_arr[time] << "\n";
  //     if (time >= k_arr.size() || n < 0)
  //       break;
  //   }
  //   if (time != 0)
  //     cout << time;
  //   else
  //     cout << -1;
  // }
  queue<int> Q;
  Q.push(n);
  dist[n] = 1;
  int ans = -1;
  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();
    if (dist[cur] - 1 >= k_arr.size())
      break;
    // cout << "k_arr " << k_arr[dist[cur] - 1] << "\n";
    if (k_arr[dist[cur] - 1] == cur) {
      ans = dist[cur] - 1;
      break;
    }
    for (int next : {cur - 1, cur + 1, cur * 2}) {
      if (next < 0 || next > 500000 || dist[next] > 0)
        continue;
      dist[next] = dist[cur] + 1;
      Q.push(next);
    }
  }

  cout << ans;
  return 0;
}