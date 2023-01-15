#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);
  int n;
  while (cin >> n) {
    int num = 1;
    int cnt = 1;
    while (true) {
      if (num % n != 0) {
        num = num * 10 + 1;
        num = num % n;
        cnt++;
      } else {
        break;
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}