#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
vector<int> vc;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    vc.push_back(t);
  }
  sort(vc.begin(), vc.end());
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (vc[i] + vc[j] == m)
        ans++;
    }
  }
  cout << ans;
  return 0;
}