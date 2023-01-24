#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, k;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> k;
  ll a, b;
  vector<pair<ll, ll>> vc;
  for (ll i = 0; i < n; i++) {
    cin >> a >> b;
    vc.push_back({a, b});
  }
  sort(vc.begin(), vc.end());
  vector<ll> bag;
  for (ll i = 0; i < k; i++) {
    cin >> a;
    bag.push_back(a);
  }
  sort(bag.begin(), bag.end());
  ll idx = 0;
  ll ans = 0;
  priority_queue<ll> pq;
  for (ll i = 0; i < k; i++) {
    while (idx < n && vc[idx].first <= bag[i]) {
      pq.push(vc[idx].second);
      idx++;
    }
    if (!pq.empty()) {
      ans += pq.top();
      pq.pop();
    }
  }
  cout << ans;
  return 0;
}