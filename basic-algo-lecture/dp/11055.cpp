#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int s[1001];
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  int d[1001];
  d[1] = s[1];
  for (int i = 2; i <= n; i++) {
    d[i] = s[i];
    for (int j = 1; j <= i; j++) {
      if (s[i] > s[j])
        d[i] = max(d[j] + s[i], d[i]);
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   cout << d[i] << " ";
  // }
  cout << *max_element(d + 1, d + 1 + n);
  return 0;
}