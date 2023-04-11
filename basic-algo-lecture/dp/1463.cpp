#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int d[1000002];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  d[1] = 0;
  for (int i = 2; i <= 1000000; i++) {
    d[i] = d[i - 1] + 1;
    if (i % 3 == 0)
      d[i] = min(d[i / 3] + 1, d[i]);
    if (i % 2 == 0)
      d[i] = min(d[i / 2] + 1, d[i]);
  }
  cout << d[n];
  return 0;
}