#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  int a, b;
  vector<pair<int, int>> vc;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    vc.push_back({b, a});
  }
  sort(vc.begin(), vc.end());
  priority_queue<int, vector<int>, greater<int>> pq; // min_heap
  for (int i = 0; i < n; i++) {
    pq.push(vc[i].second);
    if (pq.size() > vc[i].first)
      pq.pop();
  }
  int ans = 0;
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }
  cout << ans;
  return 0;
}