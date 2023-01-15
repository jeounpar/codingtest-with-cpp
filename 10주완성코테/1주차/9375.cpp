#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  while (n--) {
    int t;
    cin >> t;
    if (t == 0) {
      cout << 0 << "\n";
      continue;
    }
    unordered_map<string, vector<string>> M;
    while (t--) {
      string a, b;
      cin >> a >> b;
      M[b].push_back(a);
    }
    vector<int> vc;
    for (auto el : M) {
      vc.push_back(el.second.size());
    }
    // for (auto a : vc)
    //   cout << a << " ";
    // cout << "\n";
    int ans = 1;
    for (auto a : vc)
      ans *= (a + 1);
    ans--;
    cout << ans << "\n";
  }
  return 0;
}