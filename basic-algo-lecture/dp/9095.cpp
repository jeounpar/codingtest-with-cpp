#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int d[12];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  d[0] = 1;
  d[1] = 1;
  d[2] = 2;
  for (int i = 3; i < 11; i++) {
    d[i] = d[i - 1] + d[i - 2] + d[i - 3];
  }
  int n;
  while (t--) {
    cin >> n;
    cout << d[n] << "\n";
  }
  return 0;
}
