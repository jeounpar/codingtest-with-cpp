#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  int n;
  cin >> n;
  ll st = 666;
  int idx = 0;
  while (idx != n) {
    // cout << st << "\n";
    if (to_string(st).find("666") != string::npos)
      idx++;
    st++;
  }
  cout << st - 1;
  return 0;
}