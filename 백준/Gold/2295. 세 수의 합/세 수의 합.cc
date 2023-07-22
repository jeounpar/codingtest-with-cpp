#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<ll> vc;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  ll t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    vc.push_back(t);
  }
  sort(vc.begin(), vc.end());
  vector<ll> tmp;

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      t = vc[i] + vc[j];
      tmp.push_back(t);
    }
  }
  ll ans = 0;
  sort(tmp.begin(), tmp.end());
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      t = vc[i] - vc[j];
      if (binary_search(tmp.begin(), tmp.end(), t)) {
        cout << vc[i];
        return 0;
      }
    }
  }
  return 0;
}