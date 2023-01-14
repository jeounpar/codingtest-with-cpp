#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);
  string s;
  cin >> s;
  string p = s;
  reverse(p.begin(), p.end());
  if (s.compare(p) == 0)
    cout << 1;
  else
    cout << 0;
  return 0;
}