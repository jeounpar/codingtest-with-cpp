#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
vector<int> vc;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  int t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    vc.push_back(t);
  }
  sort(vc.begin(), vc.end(), greater<>());
  int answer = 0;
  for (auto a : vc) {
    if (k / a > 0) {
      answer += k / a;
      k = k - (k / a) * a;
    }
  }
  cout << answer;
  return 0;
}