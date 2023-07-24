#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, t, cnt_2, sum;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    sum += t;
    cnt_2 += t / 2;
  }
  if (sum % 3 != 0)
    cout << "NO";
  else {
    if (cnt_2 >= sum / 3)
      cout << "YES";
    else
      cout << "NO";
  }

  return 0;
}