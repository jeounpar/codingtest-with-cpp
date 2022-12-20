#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int d[1000001];
int pre[1000001];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  d[1] = 0;
  d[2] = 1;
  d[3] = 1;
  pre[1] = 1;
  pre[2] = 1;
  pre[3] = 1;
  for (int i = 4; i <= 1000000; i++) {
    d[i] = d[i - 1] + 1;
    pre[i] = i - 1;
    if (i % 3 == 0 && d[i / 3] + 1 < d[i]) {
      d[i] = d[i / 3] + 1;
      pre[i] = i / 3;
    }
    if (i % 2 == 0 && d[i / 2] + 1 < d[i]) {
      d[i] = d[i / 2] + 1;
      pre[i] = i / 2;
    }
  }
  cout << d[n] << "\n";
  int st = n;
  while (true) {
    cout << st << " ";
    if (st == 1)
      break;
    st = pre[st];
  }
  return 0;
}