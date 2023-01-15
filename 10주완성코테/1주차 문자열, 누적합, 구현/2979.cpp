#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int arr[101];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);
  int a, b, c;
  cin >> a >> b >> c;
  for (int i = 0; i < 3; i++) {
    int x, y;
    cin >> x >> y;
    for (int j = x; j < y; j++)
      arr[j]++;
  }
  int ans = 0;
  for (int i = 1; i <= 100; i++) {
    if (arr[i] == 1)
      ans += a;
    else if (arr[i] == 2)
      ans += b * 2;
    else if (arr[i] == 3)
      ans += c * 3;
  }
  cout << ans;
  // for (auto a : vc)
  //   cout << a[0] << " " << a[1] << "\n";
  return 0;
}