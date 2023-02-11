#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
vector<int> vc;
map<int, int> M;
bool ok[101];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> k;
  int t;
  for (int i = 0; i < k; i++) {
    cin >> t;
    vc.push_back(t);
    M[t] += 1;
  }
  // for (auto a : M)
  //   cout << a.first << " " << a.second << "\n";
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  int ans = 0;
  for (auto a : vc) {
    if (pq.size() < n && !ok[a]) {
      M[a] -= 1;
      pq.push({M[a], a});
      ok[a] = true;
    } else if (ok[a])
      continue;
    else {
      auto cur = pq.top();
      pq.pop();
      ok[cur.second] = false;
      M[a] -= 1;
      pq.push({M[a], a});
      ok[a] = true;
      ans++;
    }
  }
  cout << ans;
  return 0;
}