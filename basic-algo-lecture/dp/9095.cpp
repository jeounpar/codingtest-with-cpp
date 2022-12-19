#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int d[100];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  d[1] = 1;
  d[2] = 2;
  d[3] = 4;
  for (int i = 4; i <= 30; i++) {
    d[i] = d[i - 1] + d[i - 2] + d[i - 3];
  }
  while (t--) {
    int k;
    cin >> k;
    cout << d[k] << "\n";
  }
  return 0;
}