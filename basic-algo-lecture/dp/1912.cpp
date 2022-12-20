#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int s[100001];
  int d[100001];
  for (int i = 1; i <= n; i++)
    cin >> s[i];
  d[1] = s[1];
  for (int i = 2; i <= n; i++) {
    d[i] = max(d[i - 1] + s[i], s[i]);
  }
  cout << *max_element(d + 1, d + n + 1);
  return 0;
}