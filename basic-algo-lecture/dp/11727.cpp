#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int d[1001];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  d[1] = 1;
  d[2] = 3;
  for (int i = 3; i <= 1000; i++) {
    d[i] = (d[i - 1] + 2 * d[i - 2]) % 10007;
  }
  cout << d[n];
  return 0;
}